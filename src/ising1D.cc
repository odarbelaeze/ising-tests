#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "System.h"
#include "WeightedAccumulator.h"

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
            "number of particles, (must be greater than 0)"
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

    System sys(n);

    double h       = (kbt_max - kbt_min) / steps;
    
    for (unsigned int s = 0; s < steps; ++s)
    {
        double kbt = kbt_max - s * h;

        WeightedAccumulator wa_energy;
        WeightedAccumulator wa_magnet;
        WeightedAccumulator wa_absmag;

        double w, energy, mag;

        for (unsigned long i = 0UL; i < std::pow(2, n); ++i)
        {
            sys.set(i);
            

            energy = (double) sys.energy() / n;
            mag    = (double) sys.magnetization() / n;
            w      = std::exp( - energy / kbt);

            // std::cout << sys << "  " << energy << "  " << mag << std::endl;
            
            wa_energy.accum(energy, w);
            wa_magnet.accum(mag, w);
            wa_absmag.accum(std::abs(mag), w);
        }

        std::cout << std::setw(15) << kbt
                  << std::setw(15) << wa_energy.mean()
                  << std::setw(15) << wa_energy.var()
                  << std::setw(15) << wa_magnet.mean()
                  << std::setw(15) << wa_magnet.var()
                  << std::setw(15) << wa_absmag.mean()
                  << std::setw(15) << wa_absmag.var()
                  << std::endl;

    }

    return 0;
}
