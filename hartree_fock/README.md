# Hartree-Fock in C++
 
A restricted Hartree-Fock (RHF) program written from scratch in C++, as a project to learn
both modern C++ and the quantum chemistry behind it. The goal is a general module that computes
the RHF energy of any closed-shell molecule, starting with the **STO-3G** basis set.

## Status
 
**Checkpoint 1 reached:** molecular geometry and nuclear repulsion work.
 
- [x] Project setup (CMake, compiler warnings, sanitizers)
- [x] `Vec3` vector arithmetic
- [x] `Atom` and `Molecule` (with total charge)
- [x] Element symbol ↔ atomic number, electron count, nuclear repulsion

## Roadmap
 
1. **Molecule:** H₂O test, read geometries from XYZ files
2. **Basis set:** shells, Gaussian94 parser, normalization
3. **One-electron integrals** (s functions): S, T, V
4. **General integrals** (s, p, …): McMurchie-Davidson, electron repulsion integrals
5. **Linear algebra:** Eigen, symmetric orthogonalization
6. **RHF SCF loop:** tested on H₂ and HeH⁺
7. **Larger molecules:** H₂O, DIIS, comparison with PySCF

## Build
```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug && ./build-debug/hf
```

## References
- A. Szabo, N. S. Ostlund, *Modern Quantum Chemistry*, Dover (1996)
- T. Helgaker, P. Jørgensen, J. Olsen, *Molecular Electronic-Structure Theory*, Wiley (2000)

