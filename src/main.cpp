#define INT_MAX 2147483647 // no magic numbers please
#include <iostream>
#include <ctime>
#include "random.h"

using namespace linearcong;

void parseargs(int argnum, char *args[], char& delim, int& numOfIter, bool& help, unsigned long int& seed, long int& maxVal);
void printhelp(char *args[]);

int main(int argc, char *argv[]) {
    
    // default arguments allow program to be called with no arguments to output a single random number in the range 0-INT_MAX
    char delim = '\n';
    int numOfIter = 1;
    bool help = false;
    unsigned long int seed = time(NULL); // default seed is current system time
    long int maxVal = INT_MAX; // looks much nicer than some 2.1 billion figure that you may not recognize at first glance

    parseargs(argc, argv, delim, numOfIter, help, seed, maxVal); // set variables based on passed arguments. note that if -h is passed, no numbers are generated

    if(help) {
        printhelp(argv);
    }
    
    else {
        rng derp;
        derp.begin(seed);
    
        for (int i = 0; i < numOfIter; i++) {
            std::cout << derp.nextval()%maxVal << delim; 
        }
    }
    if (delim != '\n') {
        std::cout << '\n'; // if delimiter was not a newline, print a newline after program ends so that prompt is not on same line as last number
    }
    return 0;
}

void parseargs(int argnum, char *args[], char& delim, int& numOfIter, bool& help, unsigned long int& seed, long int& maxVal) {
    if (argnum == 0) { return; } // if argnum == 0 or 1, the only argument passed was the program name. If argnum%2 == 0, one argument was passed but no value given
    if (argnum%2 == 0 || argnum == 1) {
        help = true;
        return;
    }
    
    for (int i = 1; i < argnum; i += 2) {  
        if (args[i] == "-h") { // this gets accomplished by the final else statement but I figured this would be a good "just in case"
            help = true;
            break;
        }
    
        else if (args[i] == "-d") {
            delim = args[i+1];
        }

        else if (args[i] == "-n") {
            numOfIter = std::stoi(args[i+1]);
        }

        else if (args[i] == "-m") {
            maxVal = std::stol(args[i+1]);
        }

        else if (args[i] == "-s") {
            seed = std::stol(args[i+1]);
        }

        else { 
            help = true;
            break;
        }
    }
}

void printhelp(char *args[]) {
    std::cout << "Usage: " << args[0] << " [-option1] [-option2] ... \n";
    std::cout << "Outputs a list of random numbers using linear congruential algorithm \n";
    std::cout << "Options: \n";
    std::cout << "-n [iterations] Number of random numbers to output (default 1)\n";
    std::cout << "-d [delimiter] Select character to place between numbers (default \\n)\n";
    std::cout << "-m [max value] Maximum value of each number (default INT_MAX)\n";
    std::cout << "-s [seed] Sets seed to be used for number generation (default system time)\n";
    std::cout << "-h Prints this help message\n";
    std::cout << "Refer to README.md for more details.";
}

