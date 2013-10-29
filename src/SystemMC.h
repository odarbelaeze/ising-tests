#ifndef SYSTEM_M_C_H_
#define SYSTEM_M_C_H_

#include <cmath>
#include <cstdlib>

#include "System.h"

class SystemMC : public System
{
public:
    explicit SystemMC(unsigned int N);
    void mcs(double kBT);

protected:
    long energy_(int i);
    void flip_(int i);
    int deckGet_();

private:
    int* deck_;
    int  top_;

};

#endif