#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "SystemMC.h"
#include "Accumulator.h"

namespace po = boost::program_options;

int main(int argc, char const *argv[])
{
    /*
        Supported program options
    */

    int n;
    
    double kbt_min = 0.01;
    double kbt_max = 5.00;
    int    steps   = 100;

    int mcs_relax;
    int mcs_sample;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        (
            "count,n",
            po::value<int>(&n) -> default_value(10),
            "number of particles, (must be greater than 0)"
        )
        (
            "kbt_min",
            po::value<double>(&kbt_min) -> default_value(0.01),
            "minimun value of the thermal energy (must be greater than 0)"
        )
        (
            "kbt_max",
            po::value<double>(&kbt_max) -> default_value(5.00),
            "maximun value of the thermal energy (must be greater than 0)"
        )
        (
            "steps",
            po::value<int>(&steps) -> default_value(100),
            "number of particles (must be greater than 0)"
        )
        (
            "mcs_relax,r",
            po::value<int>(&mcs_relax) -> default_value(1000),
            "number of Monte Carlo relax steeps (must be greater than 0)"
        )
        (
            "mcs_sample,s",
            po::value<int>(&mcs_sample) -> default_value(1000),
            "number of Monte Carlo sample steeps (must be greater than 0)"
        )
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    if (n < 0) {
        std::cout << desc << std::endl;
        return 1;
    }

    SystemMC sys(n);

    double h       = (kbt_max - kbt_min) / steps;
    
    for (unsigned int s = 0; s < steps; ++s)
    {
        double kbt = kbt_max - s * h;

        sys.setWeights(kbt);

        Accumulator a_energy;
        Accumulator a_magnet;
        Accumulator a_absmag;

        double w, energy, mag;

        for (int i = 0; i < mcs_relax; ++i)
        {
            sys.mcs();
        }

        for (int i = 0; i < mcs_sample; ++i)
        {
            sys.mcs();

            energy = (double) sys.energy() / n;
            mag    = (double) sys.magnetization() / n;
            
            a_energy.accum(energy);
            a_magnet.accum(mag);
            a_absmag.accum(std::abs(mag));
        }

        std::cout << std::setw(15) << kbt
                  << std::setw(15) << a_energy.mean()
                  << std::setw(15) << a_energy.var()
                  << std::setw(15) << a_magnet.mean()
                  << std::setw(15) << a_magnet.var()
                  << std::setw(15) << a_absmag.mean()
                  << std::setw(15) << a_absmag.var()
                  << std::endl;

    }

    return 0;
}
