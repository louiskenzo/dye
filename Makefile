all: bin/demo

bin:
	mkdir -p $@

bin/demo: src/demo.cpp src/dye.hpp bin
	g++ -Wall -std=c++11 src/demo.cpp -o $@
