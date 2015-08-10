__Concise, user-friendly C++ console coloring__

* Single-header library
* All ECMA-48 control sequences, xterm-256 and 24-bit colors
* Concise syntax with easy scoped color changes

Quick preview:

```cpp
#include <iostream>
#include "dye.hpp"

int main() {
  std::cout << dye::red << "Red";
  std::cout << ~dye::rgb(0,136,255) << dye::white << "White on blue";
  std::cout << dye::jet(1/100) << "Jet colormap";
  std::cout << dye::green("Green") << " not green anymore";
}
```

Installation
============

* Place `dye.hpp` in one of your include directories.
* `#include "dye.hpp"`

Example
=======

![Example output as per example.cpp](/../illustrations/example.png?raw=true)

API
===

All color manipulators can be made into background color manipulator with the ~ unary operator.

Indexed named colors
--------------------

Standard xterm indexed colors:
* `dye::black`
* `dye::red`
* `dye::green`
* `dye::yellow`
* `dye::blue`
* `dye::magenta`
* `dye::cyan`
* `dye::white`
* `dye::reset`

Numerical colors
----------------

24-bit/xterm-256 auto-switching:
* `dye::rgb(r,g,b)`
* `dye::hsv(h,s,v)`

Forcing of 24-bit colors:
* `dye::rgb24bit(r,g,b)`
* `dye::hsv24bit(h,s,v)`

Forcing of xterm-256 colors:
* `dye::rgb256(r,g,b)`
* `dye::hsv256(r,g,b)`

Colormaps
---------

Functions taking a percentage and outputting C++ standard stream manipulators to
output ECM48 color codes.

* `dye::hot`
* `dye::jet`
* `dye::hsv`
* `dye::good`
* `dye::gray`

Fast, pre-evaluated lookup table colormaps:
* `dye::hot100`
* `dye::jet100`
* `dye::hsv100`
* `dye::good100`
* `dye::gray100`

Utility functions
-----------------

* `dye::terminal_is_24bit_capable()`
* `dye::xterm256::ECMA48_from_rgb(r,g,b)`

ECMA-48 sequences
-----------------

As defined in the [ECMA-48 standard](http://www.ecma-international.org/publications/files/ECMA-ST/Ecma-048.pdf).

C0 set:
* `dye::ECMA48::C0::NUL`
* `dye::ECMA48::C0::SOH`
* `dye::ECMA48::C0::STX`
* `dye::ECMA48::C0::ETX`
* `dye::ECMA48::C0::EOT`
* `dye::ECMA48::C0::ENQ`
* `dye::ECMA48::C0::ACK`
* `dye::ECMA48::C0::BEL`
* `dye::ECMA48::C0::BS`
* `dye::ECMA48::C0::HT`
* `dye::ECMA48::C0::LF`
* `dye::ECMA48::C0::VT`
* `dye::ECMA48::C0::FF`
* `dye::ECMA48::C0::CR`
* `dye::ECMA48::C0::SO`
* `dye::ECMA48::C0::SI`
* `dye::ECMA48::C0::LS1`
* `dye::ECMA48::C0::LS0`
* `dye::ECMA48::C0::DLE`
* `dye::ECMA48::C0::DC1`
* `dye::ECMA48::C0::DC2`
* `dye::ECMA48::C0::DC3`
* `dye::ECMA48::C0::DC4`
* `dye::ECMA48::C0::NAK`
* `dye::ECMA48::C0::SYN`
* `dye::ECMA48::C0::ETB`
* `dye::ECMA48::C0::CAN`
* `dye::ECMA48::C0::EM`
* `dye::ECMA48::C0::SUB`
* `dye::ECMA48::C0::ESC`
* `dye::ECMA48::C0::IS1`
* `dye::ECMA48::C0::IS2`
* `dye::ECMA48::C0::IS3`
* `dye::ECMA48::C0::IS4`

C1 set:
* `dye::ECMA48::C1::APC`
* `dye::ECMA48::C1::BPH`
* `dye::ECMA48::C1::CCH`
* `dye::ECMA48::C1::CSI`
* `dye::ECMA48::C1::DCS`
* `dye::ECMA48::C1::EPA`
* `dye::ECMA48::C1::ESA`
* `dye::ECMA48::C1::HTJ`
* `dye::ECMA48::C1::HTS`
* `dye::ECMA48::C1::MW`
* `dye::ECMA48::C1::NBH`
* `dye::ECMA48::C1::NEL`
* `dye::ECMA48::C1::OSC`
* `dye::ECMA48::C1::PLD`
* `dye::ECMA48::C1::PLU`
* `dye::ECMA48::C1::PM`
* `dye::ECMA48::C1::PU1`
* `dye::ECMA48::C1::PU2`
* `dye::ECMA48::C1::RI`
* `dye::ECMA48::C1::SCI`
* `dye::ECMA48::C1::SOS`
* `dye::ECMA48::C1::SPA`
* `dye::ECMA48::C1::SSA`
* `dye::ECMA48::C1::SS2`
* `dye::ECMA48::C1::SS3`
* `dye::ECMA48::C1::ST`
* `dye::ECMA48::C1::STS`
* `dye::ECMA48::C1::VTS`

Control sequences:
* `dye::ECMA48::ControlSequences::ICH`
* `dye::ECMA48::ControlSequences::CUU`
* `dye::ECMA48::ControlSequences::CUD`
* `dye::ECMA48::ControlSequences::CUF`
* `dye::ECMA48::ControlSequences::CUB`
* `dye::ECMA48::ControlSequences::CNL`
* `dye::ECMA48::ControlSequences::CPL`
* `dye::ECMA48::ControlSequences::CHA`
* `dye::ECMA48::ControlSequences::CUP`
* `dye::ECMA48::ControlSequences::CHT`
* `dye::ECMA48::ControlSequences::ED`
* `dye::ECMA48::ControlSequences::EL`
* `dye::ECMA48::ControlSequences::IL`
* `dye::ECMA48::ControlSequences::DL`
* `dye::ECMA48::ControlSequences::EF`
* `dye::ECMA48::ControlSequences::EA`
* `dye::ECMA48::ControlSequences::DCH`
* `dye::ECMA48::ControlSequences::SEE`
* `dye::ECMA48::ControlSequences::CPR`
* `dye::ECMA48::ControlSequences::SU`
* `dye::ECMA48::ControlSequences::SD`
* `dye::ECMA48::ControlSequences::NP`
* `dye::ECMA48::ControlSequences::PP`
* `dye::ECMA48::ControlSequences::CTC`
* `dye::ECMA48::ControlSequences::ECH`
* `dye::ECMA48::ControlSequences::CVT`
* `dye::ECMA48::ControlSequences::CBT`
* `dye::ECMA48::ControlSequences::SRS`
* `dye::ECMA48::ControlSequences::PTX`
* `dye::ECMA48::ControlSequences::SDS`
* `dye::ECMA48::ControlSequences::SIMD`
* `dye::ECMA48::ControlSequences::HPA`
* `dye::ECMA48::ControlSequences::HPR`
* `dye::ECMA48::ControlSequences::REP`
* `dye::ECMA48::ControlSequences::DA`
* `dye::ECMA48::ControlSequences::VPA`
* `dye::ECMA48::ControlSequences::VPR`
* `dye::ECMA48::ControlSequences::HVP`
* `dye::ECMA48::ControlSequences::TBC`
* `dye::ECMA48::ControlSequences::SM`
* `dye::ECMA48::ControlSequences::MC`
* `dye::ECMA48::ControlSequences::HPB`
* `dye::ECMA48::ControlSequences::VPB`
* `dye::ECMA48::ControlSequences::RM`
* `dye::ECMA48::ControlSequences::SGR`
* `dye::ECMA48::ControlSequences::DSR`
* `dye::ECMA48::ControlSequences::DAQ`
* `dye::ECMA48::ControlSequences::SL`
* `dye::ECMA48::ControlSequences::SR`
* `dye::ECMA48::ControlSequences::GSM`
* `dye::ECMA48::ControlSequences::GSS`
* `dye::ECMA48::ControlSequences::FNT`
* `dye::ECMA48::ControlSequences::TSS`
* `dye::ECMA48::ControlSequences::JFY`
* `dye::ECMA48::ControlSequences::SPI`
* `dye::ECMA48::ControlSequences::QUAD`
* `dye::ECMA48::ControlSequences::SSU`
* `dye::ECMA48::ControlSequences::PFS`
* `dye::ECMA48::ControlSequences::SHS`
* `dye::ECMA48::ControlSequences::SVS`
* `dye::ECMA48::ControlSequences::IGS`
* `dye::ECMA48::ControlSequences::IDCS`
* `dye::ECMA48::ControlSequences::PPA`
* `dye::ECMA48::ControlSequences::PPR`
* `dye::ECMA48::ControlSequences::PPB`
* `dye::ECMA48::ControlSequences::SPD`
* `dye::ECMA48::ControlSequences::DTA`
* `dye::ECMA48::ControlSequences::SLH`
* `dye::ECMA48::ControlSequences::SLL`
* `dye::ECMA48::ControlSequences::FNK`
* `dye::ECMA48::ControlSequences::SPQR`
* `dye::ECMA48::ControlSequences::SEF`
* `dye::ECMA48::ControlSequences::PEC`
* `dye::ECMA48::ControlSequences::SSW`
* `dye::ECMA48::ControlSequences::SACS`
* `dye::ECMA48::ControlSequences::SAPV`
* `dye::ECMA48::ControlSequences::STAB`
* `dye::ECMA48::ControlSequences::GCC`
* `dye::ECMA48::ControlSequences::TATE`
* `dye::ECMA48::ControlSequences::TALE`
* `dye::ECMA48::ControlSequences::TAC`
* `dye::ECMA48::ControlSequences::TCC`
* `dye::ECMA48::ControlSequences::TSR`
* `dye::ECMA48::ControlSequences::SCO`
* `dye::ECMA48::ControlSequences::SRCS`
* `dye::ECMA48::ControlSequences::SCS`
* `dye::ECMA48::ControlSequences::SLS`
* `dye::ECMA48::ControlSequences::SPH`
* `dye::ECMA48::ControlSequences::SPL`
* `dye::ECMA48::ControlSequences::SCP`

Independent control functions:
* `dye::ECMA48::IndependentControlFunctions::DMI`
* `dye::ECMA48::IndependentControlFunctions::INT`
* `dye::ECMA48::IndependentControlFunctions::EMI`
* `dye::ECMA48::IndependentControlFunctions::RIS`
* `dye::ECMA48::IndependentControlFunctions::CMD`
* `dye::ECMA48::IndependentControlFunctions::LS2`
* `dye::ECMA48::IndependentControlFunctions::LS3`
* `dye::ECMA48::IndependentControlFunctions::LS3R`
* `dye::ECMA48::IndependentControlFunctions::LS2R`
* `dye::ECMA48::IndependentControlFunctions::LS1R`

Control strings:
* `dye::ECMA48::ControlString::APC`
* `dye::ECMA48::ControlString::DCS`
* `dye::ECMA48::ControlString::OSC`
* `dye::ECMA48::ControlString::PM`
* `dye::ECMA48::ControlString::SOS`

ECMA-48 SGR shortands
---------------------

* `dye::ECMA48::ControlSequence::reset`
* `dye::ECMA48::ControlSequence::bold`
* `dye::ECMA48::ControlSequence::faint`
* `dye::ECMA48::ControlSequence::italic`
* `dye::ECMA48::ControlSequence::underlined`
* `dye::ECMA48::ControlSequence::slow_blinking`
* `dye::ECMA48::ControlSequence::rapid_blinking`
* `dye::ECMA48::ControlSequence::negative`
* `dye::ECMA48::ControlSequence::concealed`
* `dye::ECMA48::ControlSequence::crossed`
* `dye::ECMA48::ControlSequence::font0`
* `dye::ECMA48::ControlSequence::font1`
* `dye::ECMA48::ControlSequence::font2`
* `dye::ECMA48::ControlSequence::font3`
* `dye::ECMA48::ControlSequence::font4`
* `dye::ECMA48::ControlSequence::font5`
* `dye::ECMA48::ControlSequence::font6`
* `dye::ECMA48::ControlSequence::font7`
* `dye::ECMA48::ControlSequence::font8`
* `dye::ECMA48::ControlSequence::font9`
* `dye::ECMA48::ControlSequence::fraktur`
* `dye::ECMA48::ControlSequence::doubly_underlined`
* `dye::ECMA48::ControlSequence::not_bold_not_faint`
* `dye::ECMA48::ControlSequence::not_italic_not_fraktur`
* `dye::ECMA48::ControlSequence::not_underlined`
* `dye::ECMA48::ControlSequence::not_blinking`
* `dye::ECMA48::ControlSequence::positive_image`
* `dye::ECMA48::ControlSequence::revealed`
* `dye::ECMA48::ControlSequence::not_crossed`
* `dye::ECMA48::ControlSequence::black`
* `dye::ECMA48::ControlSequence::red`
* `dye::ECMA48::ControlSequence::green`
* `dye::ECMA48::ControlSequence::yellow`
* `dye::ECMA48::ControlSequence::blue`
* `dye::ECMA48::ControlSequence::magenta`
* `dye::ECMA48::ControlSequence::cyan`
* `dye::ECMA48::ControlSequence::white`
* `dye::ECMA48::ControlSequence::foreground_256`
* `dye::ECMA48::ControlSequence::foreground_24bit`
* `dye::ECMA48::ControlSequence::default_color`
* `dye::ECMA48::ControlSequence::black_background`
* `dye::ECMA48::ControlSequence::red_background`
* `dye::ECMA48::ControlSequence::green_background`
* `dye::ECMA48::ControlSequence::yellow_background`
* `dye::ECMA48::ControlSequence::blue_background`
* `dye::ECMA48::ControlSequence::magenta_background`
* `dye::ECMA48::ControlSequence::cyan_background`
* `dye::ECMA48::ControlSequence::white_background`
* `dye::ECMA48::ControlSequence::background_256`
* `dye::ECMA48::ControlSequence::background_24bit`
* `dye::ECMA48::ControlSequence::default_background`
* `dye::ECMA48::ControlSequence::framed`
* `dye::ECMA48::ControlSequence::encircled`
* `dye::ECMA48::ControlSequence::overlined`
* `dye::ECMA48::ControlSequence::not_framed_not_encircled`
* `dye::ECMA48::ControlSequence::not_overlined`
* `dye::ECMA48::ControlSequence::ideogram_underline`
* `dye::ECMA48::ControlSequence::ideogram_double_underline`
* `dye::ECMA48::ControlSequence::ideogram_overline`
* `dye::ECMA48::ControlSequence::ideogram_double_overline`
* `dye::ECMA48::ControlSequence::ideogram_stress_marking`
* `dye::ECMA48::ControlSequence::not_ideogram`
* `dye::ECMA48::ControlSequence::right_side_line`
* `dye::ECMA48::ControlSequence::double_right_side_line`
* `dye::ECMA48::ControlSequence::left_side_line`
* `dye::ECMA48::ControlSequence::double_left_side_line`
* `dye::ECMA48::ControlSequence::not_side_line`

Gotchas
=======

Scoped vs. state-changing manipulators
--------------------------------------

Dye  manipulators can take 2 forms:
* manipulator (e.g. `dye::red`)
* manipulator("some text") (e.g. `dye::red("Self-contained")`)

This includes functional manipulators which already take an argument, like RGB manipulators: `dye::rgb(255,0,0)("Scoped")`
