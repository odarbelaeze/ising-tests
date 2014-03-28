#ifndef BASE_SIMULATION_H_
#define BASE_SIMULATION_H_

#include "WeightedAccumulator.h"

/*
    This will also require Histograms.
*/

#include <stdexcept>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

class ValidationError : public std::exception {};

class BaseSimulation
{
public:
    BaseSimulation(int, char**);
    virtual ~BaseSimulation();

    virtual void store();
    virtual void validate();
    // Pure virtual function
    virtual void run() = 0;
    po::options_description& getDesc();
    po::variables_map& getVariables();

protected:
    WeightedAccumulator waAbsMagnetization_;
    WeightedAccumulator waMagnetization_;
    WeightedAccumulator waEnergy_;

    po::options_description desc_;
    po::variables_map vm_;

    int l_;
    int steps_;
    int dimensions_;

    double kbtMax_;
    double kbtMin_;

    int ac_;
    char** av_;

};

#endif