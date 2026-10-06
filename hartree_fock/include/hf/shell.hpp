#pragma once

#include <cstddef>
#include <vector>
#include "hf/vec3.hpp"

// we are building a Gaussian shell, cartesian function with angular momentum l
// on one center, sharing same exponents and contraction coefficient

namespace hf {

class Shell {
public:
    // public, everything can be used from outside

    // constructor, building the object 
    Shell(Vec3 center, int l, std::vector<double> exponents,
        std::vector<double> coefficients);
    
    const Vec3& center() const { 
        return center_; }

    int l() const { 
        return l_; }

    const std::vector<double>& exponents() const { 
        return exponents_; }
        
    const std::vector<double>& coefficients() const { 
        return coefficients_; }

    std::size_t n_primitives() const {return exponents_.size(); }
    
    std::size_t n_functions() const {
        return static_cast<std::size_t>((l_ + 1) * (l_ + 2) / 2);   
    }

private:

    Vec3 center_;
    int l_;
    std::vector<double> exponents_;
    std::vector<double> coefficients_;


};

}