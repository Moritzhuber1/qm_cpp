#include "hf/molecule.hpp"

#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace hf {

// anonym namepsace, only visible in this .cpp file, in contra hf is public 
namespace {

constexpr double ANGSTROM_TO_BOHR = 1.8897261246;
// index = atomic number
const std::vector<std::string> ELEMENTS = {
    "X",
    "H", "He",
    "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
};

// maps element symbol to atomic number 
std::unordered_map<std::string, int> build_proton_table()
{
    std::unordered_map<std::string, int> table;
    for (std::size_t z = 1; z < ELEMENTS.size(); ++z) {
        table[ELEMENTS[z]] = static_cast<int>(z);
    }
    return table;   
}

} //namespace

int atomic_number(const std::string& symbol)
{   
    static const auto table = build_proton_table(); 
// static: built only on the first call, then reused
// const:  the table is never modified
// auto:   compiler deduces the type
    auto it = table.find(symbol); //point at the pair for instance("O", 8)
    if (it == table.end()) {
        throw std::runtime_error("Unknown element symbol: '" + symbol + "'");
    }
    return it->second;
}

// inverse of atomic_number
std::string element_symbol(int Z)
{
    if (Z < 1 || static_cast<std::size_t>(Z) >= ELEMENTS.size()) {
        throw std::runtime_error("Unsupported atomic number: " + std::to_string(Z));
    }
    return ELEMENTS[static_cast<std::size_t>(Z)];
}

int Molecule::n_electrons() const
{
    int n = 0;
    for (const Atom& atom : atoms) {
        n += atom.Z;
    }
    return n - charge;
}

double nuclear_repulsion(const Molecule& mol)
{
    double energy = 0.0;
    const std::size_t n = mol.atoms.size();

    for (std::size_t A = 0; A < n; ++A) {
        for(std::size_t B = A + 1; B < n; ++B) {
            const Atom& a = mol.atoms[A];
            const Atom& b = mol.atoms[B];

            const double R = norm(a.pos - b.pos);
            energy += (a.Z * b.Z) / R; 
        }
    }
    return energy;
}

Molecule read_xyz(const std::string& filename, int charge)
{
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Cannot open file: '" + filename + "'");
    }

    std::size_t n_atoms{}; //read the atom number from file header 
    if (!(in >> n_atoms)) {
        throw std::runtime_error("Cannot read number of atoms in '" + filename + "'");
    }

    std::string line;
    std::getline(in, line); // rest of line 1 
    std::getline(in, line); // comment line 

    Molecule mol;
    mol.charge = charge;

    for (std::size_t i = 0; i < n_atoms; ++i) {
        
        std::string symbol;
        double x{}, y{}, z{};

        if (!(in >> symbol >> x >> y >> z)) {
            throw std::runtime_error("Cannot read atom " + std::to_string(i + 1) + " in '" + filename + "'");
        }

        const int Z = atomic_number(symbol);
        const Vec3 pos_angstrom{x, y, z};
        const Vec3 pos_bohr = ANGSTROM_TO_BOHR * pos_angstrom;

        mol.atoms.push_back({Z, pos_bohr});


    }

    return mol;

}


} //namespace hf