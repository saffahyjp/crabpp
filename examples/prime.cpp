#include <iostream>
#include <vector>
#include "crabpp.hpp"
using namespace std;
using namespace crabpp;

constexpr let N = 100;  // find all primes less than N

int main() {
    let_mut known_primes = vector<int>();
    for (ref i : range(2, N + 1)) {
        let_mut is_prime = true;
        for (ref prime : known_primes)
            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        if (is_prime) {
            known_primes.push_back(i);
            cout << "found prime: " << i << endl;
        }
    }
    return 0;
}
