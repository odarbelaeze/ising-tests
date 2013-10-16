#include <cmath>
#include <iostream>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "System.h"

namespace po = boost::program_options;

int main(int argc, char const *argv[])
{
    /*
        Supported program options
    */

    int n;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("count,n", po::value<int>(&n) -> default_value(10), "number of particles, (must be greater than 0)")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    System sys(n);

    for (int i = 0; i < std::pow(2, n); ++i)
    {
        sys.set(n);
    }

    return 0;
}