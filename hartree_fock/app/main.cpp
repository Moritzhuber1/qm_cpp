#include <format>
#include <iostream>
#include "hf/molecule.hpp"
#include "hf/shell.hpp"
#include <stdexcept>

int main() {

    hf::Shell h1s(hf::Vec3{}, 0,
                {3.425250914, 0.6239137298, 0.1688554040},
                {0.1543289673, 0.5353281423, 0.4446345422});

    hf::Shell o2p(hf::Vec3{}, 1,
                {5.033151319, 1.169596125, 0.3803889600},
                {0.1559162750, 0.6076837186, 0.3919573931});

    std::cout << "H 1s: " << h1s.n_primitives() << " primitives, "
            << h1s.n_functions() << " function(s)\n";
    std::cout << "O 2p: " << o2p.n_primitives() << " primitives, "
            << o2p.n_functions() << " function(s)\n";

    try {
        hf::Shell bad(hf::Vec3{}, 0, {1.0, 0.0}, {0.5, 0.5});
    } catch (const std::invalid_argument& e) {
        std::cout << "caught: " << e.what() << '\n';
    }                     
}