#include "BaseSystem.h"

BaseSystem::BaseSystem(uint w, uint h, bool pbcx, bool pbcy)
{
    w_ = w;
    h_ = h;
    n_ = w * h;

    pbcx_ = pbcx;
    pbcy_ = pbcy;

    state_ = new Spin*[w];
    for (int i = 0; i < w; ++i)
    {
        state_[i] = new Spin[h];
    }

}


BaseSystem::~BaseSystem()
{}



long BaseSystem::energy()
{
    long energy = 0L;
    for (int i = 0; i < w_; ++i)
    {
        for (int j = 0; j < h_; ++j)
        {
            energy -= (pbcx_ || i + 1 != w_)? state_[i][j] * state_[(i + 1) % w_][j] : 0L;
            energy -= (pbcy_ || j + 1 != h_)? state_[i][j] * state_[i][(j + 1) % h_] : 0L;
        }
    }
    return energy;
}


long BaseSystem::energy(int i, int j)
{
    if (i < 0 || i >= w_) throw std::out_of_range("i: must be in the range [0,w_)");
    if (j < 0 || j >= h_) throw std::out_of_range("j: must be in the range [0,h_)");

    long energy = 0L;
    
    energy -= (pbcx_ || i + 1 != w_)? state_[i][j] * state_[(i + 1) % w_][j] : 0L;
    energy -= (pbcy_ || j + 1 != h_)? state_[i][j] * state_[i][(j + 1) % h_] : 0L;

    energy -= (pbcx_ || i - 1 >= 0)? state_[i][j] * state_[(i - 1) < 0? i - 1 + w_ : i - 1][j] : 0L;
    energy -= (pbcy_ || j - 1 >= 0)? state_[i][j] * state_[i][(j - 1) < 0? j - 1 + h_ : j - 1] : 0L;

    return energy;
}


long BaseSystem::magnetization()
{
    long magnetization = 0L;

    for (int i = 0; i < w_; ++i)
    {
        for (int j = 0; j < h_; ++j)
        {
            // The compound asignment operator couldn't be implemented
            magnetization = magnetization + state_[i][j];
        }
    }

    return magnetization;
}



Spin** BaseSystem::getState() const
{
    return state_;
}


uint BaseSystem::getWidth()
{
    return w_;
}


uint BaseSystem::getHeight()
{
    return h_;
}


uint BaseSystem::getCount()
{
    return n_;
}


bool BaseSystem::hasPbcX()
{
    return pbcx_;
}


bool BaseSystem::hasPbcY()
{
    return pbcy_;
}


