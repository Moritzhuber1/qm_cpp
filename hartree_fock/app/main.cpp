#include <format>
#include <iostream>
#include "hf/molecule.hpp"

int main() {
    hf::Molecule water = hf::read_xyz("data/h2o.xyz");
    std::cout << std::format("From file: {} atoms, E_nuc = {:.10f}\n",
                            water.atoms.size(), hf::nuclear_repulsion(water));
}