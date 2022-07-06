#include <iostream>
#include <vector>
#include <sstream>

#include "StateVectorManagedCPU.cpp"

using namespace Pennylane;

std::string bits_to_str(size_t size, size_t k) {
    std::vector<char> str(size, '\0');
    for(size_t i = 0; i < size; i++) {
        str[i] = '0' + ((k >> i) & 1);
    }
    return std::string(str.begin(), str.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, StateVectorManagedCPU<T>& sv) {
    const auto& v = sv.getDataVector();
    const size_t num_qubits = sv.getNumQubits();

    std::vector<std::string> terms;
    for(size_t i = 0; i < v.size(); i++) {
        std::ostringstream ss;
        if (v[i] != 0.0) {
            ss << '(' << std::real(v[i]) << '+' << std::imag(v[i]) << "I)|" << bits_to_str(num_qubits, i) << '>';
            terms.emplace_back(ss.str());
        }
    }

    for(size_t i = 0; i < terms.size(); i++) {
        os << terms[i];
        if (i != terms.size() - 1 && terms[i+1][0] != '-') {
            os << '+';
        }
    }
    return os;
}

int main() {
    const size_t num_qubits = 3;
    StateVectorManagedCPU<double> sv(num_qubits); // initialized to |000>

    sv.applyOperation("Hadamard", {2}); // apply Hadamard gate to the 2nd qubit

    std::cout << sv << '\n';
    return 0;
}
