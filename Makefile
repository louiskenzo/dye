all: bin/demo

bin:
	mkdir -p $@

bin/demo: src/demo.cpp src/dye.hpp bin
	g++ -Wall src/demo.cpp -o $@
