#pragma once 
#include <string>
#include <vector>
#include "hf/vec3.hpp"

namespace hf {
    
struct Atom {    
    int Z{};  //nuclear charge
    Vec3 pos; //position in bohr
};

struct Molecule {
    std::vector<Atom> atoms;
    int charge = 0;

    int n_electrons() const; //const is for just reading 
};

//declarations from the header, the functions are then in molecule.cpp file
int atomic_number(const std::string& symbol);
std::string element_symbol(int Z);
double nuclear_repulsion(const Molecule& mol);
Molecule read_xyz(const std::string& filename, int charge = 0);

}

