#ifndef BASE_SYSTEM_H_
#define BASE_SYSTEM_H_

#include "SpinMath.h"

#include <stdexcept>

typedef unsigned int uint;

class BaseSystem
{
public:
    BaseSystem(uint, uint, bool, bool);
    ~BaseSystem();

    virtual long energy();
    virtual long energy(int, int);
    virtual long magnetization();

    Spin** getState() const;
    uint getWidth();
    uint getHeight();
    uint getCount();
    bool hasPbcX();
    bool hasPbcY();

protected:
    Spin** state_;
    uint w_;
    uint h_;
    uint n_;
    bool pbcx_;
    bool pbcy_;

};

#endif
