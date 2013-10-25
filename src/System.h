#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "SpinMath.h"

class InvalidStateException : public std::exception {};
class InvalidParticleNumberException : public std::exception {};

class System
{
public:
    explicit System(unsigned int N);
    ~System();

    void set(unsigned long n);
    long magnetization();
    virtual long energy();

    friend std::ostream& operator<< (std::ostream& os, System system);

protected:
    unsigned int N_;
    Spin* state_;

};

#endif
