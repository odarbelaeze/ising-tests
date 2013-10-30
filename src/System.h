#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "SpinMath.h"

class InvalidStateException : public std::exception {};
class InvalidParticleNumberException : public std::exception {};
class UnavailableEnergyException : public std::exception {};

class System
{
public:
    explicit System(unsigned int N);
    ~System();

    void set(unsigned long n);
    long magnetization();
    virtual long energy();
    void setWeights(double kBT);
    double getWeight(long ener);

    friend std::ostream& operator<< (std::ostream& os, System system);

protected:
    unsigned int N_;
    Spin* state_;
    double* weights_;

};

#endif
