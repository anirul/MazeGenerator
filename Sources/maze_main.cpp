#include <iostream>
#include <string>
#include <chrono>
#include <boost/program_options.hpp>

#include "maze_generator.hpp"

using boost::program_options::options_description;
using boost::program_options::variables_map;
using boost::program_options::store;
using boost::program_options::command_line_parser;
using boost::program_options::value;

int main(int ac, char** av) {
    try {
	unsigned int dx = 0;
	unsigned int dy = 0;
	unsigned int dz = 1;
	options_description desc("Allowed options");
	desc.add_options()
	    ("help,h", "produce help message")
	    ("size-x,x", value<unsigned int>(), "x size")
	    ("size-y,y", value<unsigned int>(), "y size")
	    ("size-z,z", value<unsigned int>(), "z size")
	    ;
	variables_map vm;
	store(command_line_parser(ac, av).options(desc).run(), vm);
	if (vm.count("help")) {
	    std::cout << desc << std::endl;
	    return 1;
	}
	if (vm.count("size-x")) {
	    dx = vm["size-x"].as<unsigned int>();
	} else {
	    throw std::runtime_error("size-x has to be defined");
	}
	if (vm.count("size-y")) {
	    dy = vm["size-y"].as<unsigned int>();
	} else {
	    throw std::runtime_error("size-y has to be defined");
	}
	if (vm.count("size-z")) {
	    dz = vm["size-z"].as<unsigned int>();
	}
	std::cout << "computing maze  : (" << dx << ", " << dy << ", " << dz << ")" << std::endl;
	maze_generator mg(dx, dy, dz);
    } catch (std::exception& ex) {
	std::cerr << "exception (std) : " << ex.what() << std::endl;
	return -1;
    }
    return 0;
}
