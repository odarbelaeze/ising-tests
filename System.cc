#include "System.h"

System::System(unsigned int N)
{
    N_ = N;
    state_ = new Spin[N];
}


System::~System()
{
    /*
        Nothing to do here.
    */
}


void System::set(unsigned long n)
{
    /*
        If i is not less than 2 ** N_, then the state given by bin(i)
        wont be a valid state of the system.
    */

    if (n >= std::pow(2, N_)) throw InvalidStateException();

    for (int i = 0; i < N_; ++i)
    {
        state_[i] = ((n & (1UL << i)) != 0)? Spin::Up : Spin::Down;
    }
}


long System::magnetization()
{
    long magnetization = 0L;
    for (int i = 0; i < N_; ++i)
    {
        magnetization += state_[i];
    }
    return magnetization;
}


long System::energy()
{
    long energy = 0L;
    for (int i = 0; i < N_; ++i)
    {
        energy += (state_[i] == state_[(i + 1) % N_])? - 1 : 1;
    }
    return energy;
}


std::ostream& operator<< (std::ostream& os, System sys)
{
    for (int i = 0; i < sys.N_; ++i)
    {
        os << sys.state_[i];
    }
    return os;
}
