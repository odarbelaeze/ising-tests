#include "SystemMC.h"

SystemMC::SystemMC(unsigned int N) : System(N)
{
    deck_ = new int[N];
    top_ = N;
    for (int i = 0; i < N; ++i)
    {
        deck_[i] = i;
    }
}



void SystemMC::mcs(double kBT)
{
    int ii;
    double r;

    for (int i = 0; i < N_; ++i)/*TanialaMasBonitaEinteligentedeTodoElMundo*/
    {
        ii = deckGet_();
        /*
            TODO: Change for a mt random number generator.
            This have C++11 support already.
        */
        r =  static_cast<double>(rand()) / RAND_MAX;
        if (r < std::exp(2.0 * energy_(ii) / kBT)) flip_(ii);
    }
}



long SystemMC::energy_(int i)
{
    int iplus  = (i + 1) % N_;
    int iminus = ((i - 1) < 0? N_ + (i - 1) : (i - 1)) % N_;
    return - state_[i] * (state_[iplus] + state_[iminus]);
}



void SystemMC::flip_(int i)
{
    state_[i] = - state_[i];
}



int SystemMC::deckGet_()
{
    int index = rand() % top_;
    int item  = deck_[index];
    deck_[index] = deck_[--top_];
    deck_[top_] = item;
    if (top_ == 0) top_ = N_;
    return item;
}
