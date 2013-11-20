#ifndef EXACT_SYSTEM_
#define EXACT_SYSTEM_

#include "BaseSystem.h"

class ExactSystem : public BaseSystem
{
public:
    ExactSystem(int, bool);
    ~ExactSystem();

    void set(uint);

};

#endif