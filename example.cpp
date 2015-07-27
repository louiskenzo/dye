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
	          << dye::white("white")     << std::endl;

	// –––––––––––––––––––––––
	// xterm256 indexed colors

	std::cout << std::endl;
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

	std::cout << std::endl;

	// ––––––––––––––––––
	// RGB-triplet colors

	std::cout << std::endl;
	std::cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
	             "RGB-triplets (24-bit if available, xterm256 approximation fallback)\n\n";

	for (float v=1.0f; v>=0.0f; v-=0.05f) {
		for (float h=0.0f; h<360.0f; h+=3.0f)
			std::cout << dye::bgHSV(h,0.8f,v)(" ");
		std::cout << std::endl;
	}

	// ––––––––––
	// Color maps

	std::cout << std::endl;
	std::cout << "––––––––––\n"
	             "Color maps\n\n";

	std::cout << std::setw(5) << "Hot" << ": ";
	for (size_t i=0; i<100; ++i)
		std::cout << dye::hot.bg(i)(" ");
	std::cout << std::endl;

	std::cout << std::setw(5) << "Jet" << ": ";
	for (size_t i=0; i<100; ++i)
		std::cout << dye::jet.bg(i)(" ");
	std::cout << std::endl;

	std::cout << std::setw(5) << "HSV" << ": ";
	for (size_t i=0; i<100; ++i)
		std::cout << dye::hsv.bg(i)(" ");
	std::cout << std::endl;

	std::cout << std::setw(5) << "Good" << ": ";
	for (size_t i=0; i<100; ++i)
		std::cout << dye::good.bg(i)(" ");
	std::cout << std::endl;

	std::cout << std::setw(5) << "Gray" << ": ";
	for (size_t i=0; i<100; ++i)
		std::cout << dye::gray.bg(i)(" ");
	std::cout << std::endl;
}

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
