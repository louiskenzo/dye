//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "dye.hpp"
#include <chrono>
#include <iostream>
#include <thread>

void cadence(size_t ms=750) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

int main() {
	std::cout << dye::black   << "black"   << std::endl; cadence();
	std::cout << dye::red     << "red"     << std::endl; cadence();
	std::cout << dye::green   << "green"   << std::endl; cadence();
	std::cout << dye::yellow  << "yellow"  << std::endl; cadence();
	std::cout << dye::blue    << "blue"    << std::endl; cadence();
	std::cout << dye::magenta << "magenta" << std::endl; cadence();
	std::cout << dye::cyan    << "cyan"    << std::endl; cadence();
	std::cout << dye::white   << "white"   << std::endl; cadence();
}

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
