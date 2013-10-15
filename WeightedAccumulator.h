#ifndef WEIGHTED_ACCUMULATOR_H_
#define WEIGHTED_ACCUMULATOR_H_

#include <cmath>
#include <stdexcept>

class InvalidWeightException : public std::exception {};
class NoDataException : public std::exception {};

class WeightedAccumulator
{
public:
    WeightedAccumulator();
    ~WeightedAccumulator();

    void accum(double x, double w);
    double mean();
    double meansq();
    double var();
    double stddev();

private:
    double data_;
    double datasq_;
    double weights_;

};

#endif
