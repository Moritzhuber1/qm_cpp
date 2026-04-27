#include <iostream>
#include <numbers>
#include <math.h>

namespace phys_const {
    const double h = 6.62607015e-34;
    const double h_bar = h/(2*M_PI);  
}

using namespace phys_const;
using namespace std; 

// ====================================
//           - functions -
// ====================================


template<typename... Args>
void print(Args&&... args) {
	((cout << args), ...);
}

template <typename T>
double round_to(T a, int dec) {
	double mult = 1.0;
	for (int i = 0; i < dec; i++) {
		mult *= 10.0;
	}

	double scaled = a * mult;
	double rounded = round(scaled);

	return rounded / mult;
}

// ====================================
//           - Particle class -
// ====================================

class ParticleInABox {
    private:

    	float calc_energy(float length, float mass, int n) {
        	return (pow((n * M_PI * h_bar),2)) / (2 * mass * pow(length,2));
    	}

    	float length;
    	float mass = 1.6735575*10e-27;   
    	float h_bar = h/(2*M_PI);
		int n;

		float energy;
    
    public:

		void set_length(float new_length) {
			length = new_length;
			print("New length is set to: ", round_to(length, 2), " nm\n");
		}
};

// ====================================
//           - main function -
// ====================================

int main() {
    float length;
    cout << "Length of the box in [nm]: " << "\n";
    cin >> length;
    ParticleInABox partile_1; 
    partile_1.set_length(length);
    return 0;
} 

