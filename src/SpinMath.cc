#include "SpinMath.h"


std::ostream& operator<< (std::ostream& os, const Spin& s)
{
    if (s == Spin::Up)
    {
        os << "1";
    }
    else
    {
        os << "0";
    }
    return os;
}


Spin operator- (const Spin& s)
{
    if (s == Spin::Up) return Spin::Down;
    else               return Spin::Up;
}


int operator* (const Spin& a, const Spin& b)
{
    if (a == b) return   1;
    else        return - 1;
}


int operator+ (const Spin& a, const Spin& b)
{
    int value = - 2;
    if (a == Spin::Up) value += 2;
    if (b == Spin::Up) value += 2;
    return value;
}


int operator- (const Spin& a, const Spin& b)
{
    return a + ( - b);
}


long operator* (const Spin& a, long m)
{
    if (a == Spin::Up) return   m;
    else               return - m;
}


long operator* (long m, const Spin& a)
{
    return a * m;
}


long operator+ (const Spin& a, long m)
{
    if (a == Spin::Up) return m + 1;
    else               return m - 1;
}


long operator+ (long m, const Spin& a)
{
    return a + m;
}


long operator- (const Spin& a, long m)
{
    return a + ( - m);
}


long operator- (long m, const Spin& a)
{
    return ( - a) + m;
}
