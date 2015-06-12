#include "random.h"

namespace linearcong {
        
    long int current_val, mod;
    int mult, inc;

    rng::rng(const unsigned long int& modulo, const long int& multiplier, const long int& increment) {
        mod = modulo;
        mult = multiplier;
        inc = increment;
    }

    void rng::begin(const long int& seed) {
        current_val = ((mult * seed) + inc)%mod;
    }
        
    long int rng::nextval(void) {
        current_val = ((mult*current_val) + inc)%mod;
        return current_val;
    }
}
