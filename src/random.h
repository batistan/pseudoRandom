#define INT_MAX 2147483647
#ifndef RANDOM_H     // Prevent duplicate definition
#define RANDOM_H
namespace linearcong {
    
    class rng {
        private:
            long int current_val, mod;
            int mult, inc;
        
        public:
            rng(const unsigned long int& modulo=INT_MAX, const long int& multiplier=1103515245, const long int& increment=12345);
            void begin(const long int& seed);
            long int nextval(void);
    };
}
#endif
