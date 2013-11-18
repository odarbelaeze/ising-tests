#ifndef SYSTEM_2D_H_
#define SYSTEM_2D_H_

#include <cmath>

#include "SpinMath.h"

class InvalidStateException : public std::exception {};
class InvalidParticleNumberException : public std::exception {};
class UnavailableEnergyException : public std::exception {};

class System2D
{
public:
    explicit System2D(unsigned int N);
    ~System2D();

    void set(unsigned int i);
    void magnetization();
    void energy();
    void setWeights();
    void getWeight(long energy);

    friend std::ostream& operator<< (std::ostream& os, System2D system);

protected:
    unsigned int n_;
    Spin* state_;
    double* weights_;

};

#endif