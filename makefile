all:
	g++ -o random -std=c++11 src/main.cpp src/random.cxx

debug:
	g++ -o random -g -std=c++11 src/main.cpp src/random.cxx
