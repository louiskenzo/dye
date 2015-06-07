//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "dye.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>

void cadence(size_t ms=750) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

int main() {
	// ––––––––––
	// Basic colors

	std::cout << dye::black("black")     << " "
	          << dye::red("red")         << " "
	          << dye::green("green")     << " "
	          << dye::yellow("yellow")   << " "
	          << dye::blue("blue")       << " "
	          << dye::magenta("magenta") << " "
	          << dye::cyan("cyan")       << " "
	          << dye::white("white")     << "\n\n";

	// –––––––––––––––––––––––
	// xterm256 indexed colors

	std::cout << "––––––––––––––––––––––––\n"
	             "xterm-256 indexed colors\n\n";

	// Standard colors

	std::cout << "Bright colors: ";
	for (size_t i =  dye::xterm256::STANDARD_DIM_START ;
		        i <= dye::xterm256::STANDARD_DIM_END ;
		      ++i)
		std::cout << dye::bg256(i)("     ");
	std::cout << "\n               ";
	for (size_t i =  dye::xterm256::STANDARD_DIM_START ;
		        i <= dye::xterm256::STANDARD_DIM_END ;
		      ++i)
		std::cout << std::setw(5) << std::left << i;

	std::cout << "\n";

	std::cout << "Dim colors:    ";
	for (size_t i =  dye::xterm256::STANDARD_BRIGHT_START ;
		        i <= dye::xterm256::STANDARD_BRIGHT_END ;
		      ++i)
		std::cout << dye::bg256(i)("     ");
	std::cout << "\n               ";
	for (size_t i =  dye::xterm256::STANDARD_BRIGHT_START ;
		        i <= dye::xterm256::STANDARD_BRIGHT_END ;
		      ++i)
		std::cout << std::setw(5) << std::left << i;

	std::cout << "\n\n";

	// Extended colors

	std::cout << "Extended colors:\n";

	for (size_t r=0; r<dye::xterm256::EXTENDED_LEVELS; ++r) {
		std::cout << "\n" << std::setw(3) << dye::xterm256::EXTENDED_START + r*36 << "  ";
		for (size_t g=0; g<dye::xterm256::EXTENDED_LEVELS; ++g)
			for (size_t b=0; b<dye::xterm256::EXTENDED_LEVELS; ++b)
				std::cout << dye::bg256(dye::xterm256::EXTENDED_START + r*36 + g*6 + b)("   ");
	}

	std::cout << "\n";
	std::cout << "   + ";
	for (size_t offset=0; offset<std::pow(dye::xterm256::EXTENDED_LEVELS,2); ++offset)
		std::cout << std::setw(3) << offset;

	std::cout << "\n\n";

	// Gray colors

	std::cout << "Gray colors:\n\n";

	for (size_t i=dye::xterm256::GREY_START; i<=dye::xterm256::GREY_END; ++i)
		std::cout << dye::bg256(i)("    ");
	std::cout << "\n";
	for (size_t i=dye::xterm256::GREY_START; i<=dye::xterm256::GREY_END; ++i)
		std::cout << std::setw(4) << i;

	std::cout << "\n\n";

	// ––––––––––––––––––
	// RGB-triplet colors

	std::cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
	             "RGB-triplets (24-bit if available, xterm256 approximation fallback)\n\n";

	for (size_t r=0; r<256; r+=15) {
		for (size_t g=0; g<256; g+=24)
			for (size_t b=0; b<256; b+=24)
				std::cout << dye::bg(r,g,b)(" ");
		std::cout << "\n";
	}

	std::cout << std::endl;
}

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
