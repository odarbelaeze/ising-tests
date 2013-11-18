#include "System2D.h"

System2D::System2D(unsigned int n)
{
    if (n < 1)
    {
        throw InvalidParticleNumberException();
    }
    n_ = n;
    try
    {
        state_ = new Spin*[n];
        for (int i = 0; i < n; ++i)
        {
            state_[i] = new Spin[n];
        }
        weights_ = new double[n];
    }
    catch (std::bad_alloc &e)
    {
        throw InvalidParticleNumberException();
    }
}


System2D::~System2D() {}


System2D::set(unsigned int n)
{
    if (n >= std::pow(2, n_ ** 2))
    {
        throw InvalidStateException();
    }
}
