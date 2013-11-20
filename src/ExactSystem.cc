#include "ExactSystem.h"

ExactSystem::ExactSystem(int l, bool oned)
 : BaseSystem(l, oned? 1 : l, true, !oned)
{

}


ExactSystem::~ExactSystem()
{

}



void ExactSystem::set(uint n)
{
    for (int i = 0; i < n_; ++i)
    {
        state_[i / w_][i % w_] = ((n & (1UL << i)) != 0)? Spin::Up : Spin::Down;
    }
}
