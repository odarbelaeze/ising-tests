#include "WeightedAccumulator.h"

WeightedAccumulator::WeightedAccumulator()
{
    data_ = 0.0;
    datasq_ = 0.0;
    weights_ = 0.0;
}


WeightedAccumulator::~WeightedAccumulator()
{
    /*
        Nothing to do here.
    */
}


void WeightedAccumulator::accum(double x, double w)
{
    /*
        If the weight is less than zero, it'll be a mathematical error
        to put it here.
    */

    if (w < 0.0) throw InvalidWeightException();

    data_   += w * x;
    datasq_ += w * x * x;
    weights_ += w;
}


double WeightedAccumulator::mean()
{
    /*
        If the weights are equal to zero, trying to compute the mean of the
        sample will lead to a mathematical error.
    */

    if (weights_ == 0.0) throw NoDataException();

    return data_ / weights_;
}


double WeightedAccumulator::meansq()
{
    /*
        If the weights are equal to zero, trying to compute the meansq of the
        sample will lead to a mathematical error.
    */

    if (weights_ == 0.0) throw NoDataException();

    return datasq_ / weights_;
}


double WeightedAccumulator::var()
{
    return meansq() - mean() * mean();
}


double WeightedAccumulator::stddev()
{
    return std::sqrt(var());
}


double WeightedAccumulator::getData()
{
    return data_;
}


double WeightedAccumulator::getDatasq()
{
    return datasq_;
}


double WeightedAccumulator::getWeights()
{
    return weights_;
}


