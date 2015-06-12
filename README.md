# pseudoRandom

#Usage

Available options are as follows:

| Option | Usage |
|--------|-------|
| -n [iterations] | Number of random numbers to output. e.g. if -n 5 is passed, 5 random numbers will be output. The default value is 1. |
| -d [delimiter] | Character to print between each number. e.g. if -d , is passed, a comma will be placed between each number. By default, this value is \n, printing each number on its own line.|
| -m [max value] | Maximum value each number can take. e.g. if -m 100 is passed, the number(s) output will be any value between 0 and 99. This is to be consistent with the behavior of random number generators in other environments. By default, the max value is INT_MAX, equal to (2^31)-1 = 2 147 483 647.|
| -s [seed] | Seed to be used for random number generation. By default, this is the current system time, in milliseconds.|
| -h | Prints a help message. |

#Installation

A makefile has been provided. Simply run `make` in the directory containing all the files and an executable named "random" will be generated. 

Thank you for using this tool. Constructive feedback is always appreciated.
