#include "BaseSimulation.h"

BaseSimulation::BaseSimulation(int ac, char** av)
 : desc_("Simulation options")
{
    desc_.add_options()
        ("help,h", "produce help message")
        (
            "count,n",
            po::value<int>(&l_) -> default_value(10),
            "number of particles, (must be greater than 0)"
        )
        (
            "dimensions,d",
            po::value<int>(&dimensions_),
            "number of dimensions (must be 1 or 2)"
        )
        (
            "kbt_min",
            po::value<double>(&kbtMin_) -> default_value(0.01),
            "minimun value of the thermal energy (must be greater than 0)"
        )
        (
            "kbt_max",
            po::value<double>(&kbtMax_) -> default_value(3.00),
            "maximun value of the thermal energy (must be greater than 0)"
        )
        (
            "steps",
            po::value<int>(&steps_) -> default_value(1000),
            "number of particles (must be greater than 0)"
        )
    ;
}


BaseSimulation::~BaseSimulation()
{
}



void BaseSimulation::store()
{
    po::store(po::parse_command_line(ac, av, desc_), vm_);
    po::notify(vm_);
}


void BaseSimulation::validate()
{
    if (l_ < 1) throw ValidationError();
    if (dimensions_ != 1 && dimensions_ != 2) throw ValidationError();
    if (kbtMax_ < kbtMin_) throw ValidationError();
    if (steps_ < 1) throw ValidationError();
}


void BaseSimulation::run()
{

}


po::options_description& BaseSimulation::getDesc()
{
    return desc_;
}


po::variables_map& BaseSimulation::getVariables()
{
    return vm_;
}


