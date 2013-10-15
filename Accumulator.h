#ifndef ACCUMULATOR_H_
#define ACCUMULATOR_H_

#include <cmath>
#include <stdexcept>

class NoDataException : public std::exception {};

class Accumulator
{
public:
    Accumulator();
    ~Accumulator();

    void accum(double x);
    double mean();
    double meansq();
    double var();
    double stddev();

private:
    double data_;
    double datasq_;
    unsigned long counter_;
};

#endif
