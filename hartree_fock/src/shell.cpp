#include "hf/shell.hpp"

#include <stdexcept>
#include <string>
#include <utility>

namespace hf {

Shell::Shell(Vec3 center, int l, std::vector<double> exponents,
             std::vector<double> coefficients)
    : center_(center),
      l_(l),
      exponents_(std::move(exponents)),
      coefficients_(std::move(coefficients))
{
    if (l_ < 0) {
        throw std::invalid_argument("Shell: l must be >= 0, got " +
                                    std::to_string(l_));
    }

    if (exponents_.empty()) {
        throw std::invalid_argument("Shell: needs at least one primitive");
    }

    if (exponents_.size() != coefficients_.size()) {
        throw std::invalid_argument(
            "Shell: number of exponents and coefficients do not match");
    }

    for (double alpha : exponents_) {
        if (alpha <= 0.0) {
            throw std::invalid_argument("Shell: exponents must be > 0, got " + std::to_string(alpha));
        }
    }
}

}  // namespace hf