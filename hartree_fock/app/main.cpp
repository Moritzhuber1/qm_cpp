#include <format>
#include <iostream>
#include "hf/molecule.hpp"

int main() {
    hf::Molecule h2{{ {1, {0.0, 0.0, 0.0}},
                      {1, {0.0, 0.0, 1.4}} }};

    std::cout << std::format("Electrons: {}\n", h2.n_electrons());
    std::cout << std::format("E_nuc:     {:.6f}\n", hf::nuclear_repulsion(h2));
    std::cout << std::format("Z(O):      {}\n", hf::atomic_number("O"));
    std::cout << std::format("Symbol 8:  {}\n", hf::element_symbol(8));
}