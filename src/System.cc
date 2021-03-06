#include "System.h"

System::System(unsigned int N)
{
    if (N == 0) throw InvalidParticleNumberException(); 
    N_ = N;

    /*
        If there is not enough memory to allocate the state
        an InvalidParticleNumberException must be thrown.
    */
    
    try
    {
        state_ = new Spin[N];
        weights_ = new double[4 * (int) N + 1];
    }
    catch (std::bad_alloc &e)
    {
        throw InvalidParticleNumberException();
    }

    std::cout << "System recently created" << std::endl;
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
        magnetization = magnetization + state_[i];
    }
    return magnetization;
}


long System::energy()
{
    long energy = 0L;
    for (int i = 0; i < N_; ++i)
    {
        energy -= state_[i] * state_[(i + 1) % N_];
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


void System::setWeights(double kBT)
{
    long max_ener = 2 * (long) N_;
    for (long ener = - max_ener; ener <= max_ener; ener++)
    {
        weights_[ener + 2 * (long) N_] = std::exp( - ener / kBT);
    }
}


double System::getWeight(long ener)
{
    if (ener < - 2 * (int) N_ || ener > 2 * (int) N_) throw UnavailableEnergyException();
    return weights_[ener + 2 * (int) N_];
}
