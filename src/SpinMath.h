#ifndef SPIN_MATH_H_
#define SPIN_MATH_H_

#include <iostream>

enum class Spin {Up, Down};
std::ostream& operator<< (std::ostream& os, const Spin& s);

/*
    Internal operations
*/

Spin operator- (const Spin& s);

/*
    External operations
*/

int operator* (const Spin& a, const Spin& b);
int operator+ (const Spin& a, const Spin& b);
int operator- (const Spin& a, const Spin& b);

/*
    Ring external operations
*/

long operator+ (const Spin& s, long m);
long operator+ (const long m, const Spin& s);
long operator- (const Spin& s, const long m);
long operator- (const long m, const Spin& s);
long operator* (const Spin& s, const long m);
long operator* (const long m, const Spin& s);

#endif
