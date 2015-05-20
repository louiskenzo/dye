//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "dye.hpp"
#include <chrono>
#include <iostream>
#include <thread>

void cadence(size_t ms=750) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

int main() {
	// Basic colors

	std::cout << dye::black   << "black"   << std::endl;
	std::cout << dye::red     << "red"     << std::endl;
	std::cout << dye::green   << "green"   << std::endl;
	std::cout << dye::yellow  << "yellow"  << std::endl;
	std::cout << dye::blue    << "blue"    << std::endl;
	std::cout << dye::magenta << "magenta" << std::endl;
	std::cout << dye::cyan    << "cyan"    << std::endl;
	std::cout << dye::white   << "white"   << std::endl;

	// 256 palette colors

	std::cout << dye::reset << std::endl;

	for (size_t i=0; i<256; ++i)
		std::cout << dye::bg(i)(" ");
	std::cout << std::endl;

	// 24-bit colors
	std::cout << std::endl;

	for (size_t i=0; i<256; ++i)
		std::cout << dye::bg(i,0,i)(" ");
	std::cout << std::endl;
}

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
