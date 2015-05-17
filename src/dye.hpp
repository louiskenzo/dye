//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#pragma once
#ifndef DYE_GUARD
#define DYE_GUARD

#include <ostream>
#include <string>

namespace dye {
	namespace ECMA48 {
		// The ECMA48 standard is available in PDF form at:
		// http://www.ecma-international.org/publications/files/ECMA-ST/Ecma-048.pdf

		// –––––––––––––––––
		// Control functions

		// Control functions are specified in §5. Their meaning and representation are
		// described in §8.3, pp. 33-74.

		namespace C0 {
			// The C0 set of control functions is specified in §5.2, p. 8.

			const std::string NUL = "\x00"; // Null                 §8.3.88
			const std::string SOH = "\x01"; // Start Of Heading     §8.3.127
			const std::string STX = "\x02"; // Start Of Text        §8.3.146
			const std::string ETX = "\x03"; // End of Text          §8.3.50
			const std::string EOT = "\x04"; // End of Transmission  §8.3.45
			const std::string ENQ = "\x05"; // Enquiry              §8.3.44
			const std::string ACK = "\x06"; // Acknowledge          §8.3.1
			const std::string BEL = "\x07"; // Bell                 §8.3.3
			const std::string BS  = "\x08"; // Backspace            §8.3.5
			const std::string HT  = "\x09"; // Character Tabulation §8.3.60
			const std::string LF  = "\x0a"; // Line Feed            §8.3.74
			const std::string VT  = "\x0b"; // Line Tabulation      §8.3.161
			const std::string FF  = "\x0c"; // Form Feed            §8.3.51
			const std::string CR  = "\x0d"; // Carriage Return      §8.3.15
			const std::string SO  = "\x0e"; // Shift-In             §8.3.119
			const std::string SI  = "\x0f"; // Shift-Out            §8.3.126
			const std::string LS1 =   SO  ; // Locking-Shift Zero   §8.3.75
			const std::string LS0 =   SI  ; // Locking-Shift One    §8.3.76

			const std::string DLE = "\x10"; // Data Link Escape            §8.3.33
			const std::string DC1 = "\x11"; // Device Control One          §8.3.28
			const std::string DC2 = "\x12"; // Device Control Two          §8.3.29
			const std::string DC3 = "\x13"; // Device Control Three        §8.3.30
			const std::string DC4 = "\x14"; // Device Control Four         §8.3.31
			const std::string NAK = "\x15"; // Negative Acknowledge        §8.3.84
			const std::string SYN = "\x16"; // Synchronous Idle            §8.3.150
			const std::string ETB = "\x17"; // End of Transmission Block   §8.3.49
			const std::string CAN = "\x18"; // Cancel                      §8.3.6
			const std::string EM  = "\x19"; // End of Medium               §8.3.42
			const std::string SUB = "\x1a"; // Substitute                  §8.3.148
			const std::string ESC = "\x1b"; // Escape                      §8.3.48
			const std::string IS4 = "\x1c"; // Information Separator One   §8.3.69
			const std::string IS3 = "\x1d"; // Information Separator Two   §8.3.70
			const std::string IS2 = "\x1e"; // Information Separator Three §8.3.71
			const std::string IS1 = "\x1f"; // Information Separator Four  §8.3.72
		}

		namespace C1 {
			// The C1 set of control functions is specified in §5.3, pp. 8-10.

			const std::string APC = C0::ESC + "_";  // Application Program Command §8.3.2
			const std::string BPH = C0::ESC + "2";  // Break Permitted Here        §8.3.4
			const std::string CCH = C0::ESC + "T";  // Cancel Character            §8.3.8
			const std::string CSI = C0::ESC + "[";  // Control Sequence Introducer §8.3.16
			const std::string DCS = C0::ESC + "P";  // Device Control String       §8.3.27
			const std::string EPA = C0::ESC + "W";  // End of Guarded Area         §8.3.46
			const std::string ESA = C0::ESC + "G";  // End of Selected Area        §8.3.47
			const std::string HTJ = C0::ESC + "I";  // Character Tabulation With Justification §8.3.61
			const std::string HTS = C0::ESC + "H";  // Character Tabulation Set    §8.3.62
			const std::string MW  = C0::ESC + "U";  // Message Waiting             §8.3.83
			const std::string NBH = C0::ESC + "C";  // No Break Here               §8.3.85
			const std::string NEL = C0::ESC + "E";  // Next Line                   §8.3.86
			const std::string OSC = C0::ESC + "]";  // Operating System Command    §8.3.89
			const std::string PLD = C0::ESC + "K";  // Partial Line Forward        §8.3.92
			const std::string PLU = C0::ESC + "L";  // Partial Line Backward       §8.3.93
			const std::string PM  = C0::ESC + "^";  // Privacy Message             §8.3.94
			const std::string PU1 = C0::ESC + "Q";  // Private Use 1               §8.3.100
			const std::string PU2 = C0::ESC + "R";  // Private Use 2               §8.3.101
			const std::string RI  = C0::ESC + "M";  // Reverse Line Feed           §8.3.104
			const std::string SCI = C0::ESC + "Z";  // Single Character Introducer §8.3.109
			const std::string SOS = C0::ESC + "X";  // Start Of String             §8.3.128
			const std::string SPA = C0::ESC + "V";  // Start of Guarded Area       §8.3.129
			const std::string SSA = C0::ESC + "F";  // Start of Selected Area      §8.3.138
			const std::string SS2 = C0::ESC + "N";  // Single Shift Two            §8.3.141
			const std::string SS3 = C0::ESC + "O";  // Single Shift Three          §8.3.142
			const std::string ST  = C0::ESC + "\\"; // String Terminator           §8.3.143
			const std::string STS = C0::ESC + "S";  // Set Transmit State          §8.3.145
			const std::string VTS = C0::ESC + "J";  // Line Tabulation Set         §8.3.162
		}

		namespace ControlSequence {
			// Control sequences are specified in §5.4, pp. 10-12

			// Select Graphic Rendition §8.3.117
			std::string SGR(const std::string& code) {return C1::CSI + code + "m";}
		}

		// –––––––––––––––––––––
		// SGR control sequences

		const std::string reset = ControlSequence::SGR("");

		const std::string bold           = ControlSequence::SGR("1");
		const std::string faint          = ControlSequence::SGR("2");
		const std::string italic         = ControlSequence::SGR("3");
		const std::string underline      = ControlSequence::SGR("4");
		const std::string slow_blinking  = ControlSequence::SGR("5");
		const std::string rapid_blinking = ControlSequence::SGR("6");
		const std::string negative       = ControlSequence::SGR("7");
		const std::string concealed      = ControlSequence::SGR("8");
		const std::string crossed        = ControlSequence::SGR("9");

		const std::string font0 = ControlSequence::SGR("11");
		const std::string font1 = ControlSequence::SGR("11");
		const std::string font2 = ControlSequence::SGR("12");
		const std::string font3 = ControlSequence::SGR("13");
		const std::string font4 = ControlSequence::SGR("14");
		const std::string font5 = ControlSequence::SGR("15");
		const std::string font6 = ControlSequence::SGR("16");
		const std::string font7 = ControlSequence::SGR("17");
		const std::string font8 = ControlSequence::SGR("18");
		const std::string font9 = ControlSequence::SGR("19");
		const std::string fraktur = ControlSequence::SGR("20");
		const std::string double_underline = ControlSequence::SGR("21");
		const std::string nobold_nofaint = ControlSequence::SGR("22");
		const std::string noitalic_nofraktur = ControlSequence::SGR("23");
		const std::string nounderline = ControlSequence::SGR("24");
		const std::string noblinking = ControlSequence::SGR("25");
		const std::string positiveimage = ControlSequence::SGR("27");
		const std::string revealed = ControlSequence::SGR("28");
		const std::string notcrossed = ControlSequence::SGR("29");

		const std::string black   = ControlSequence::SGR("30");
		const std::string red     = ControlSequence::SGR("31");
		const std::string green   = ControlSequence::SGR("32");
		const std::string yellow  = ControlSequence::SGR("33");
		const std::string blue    = ControlSequence::SGR("34");
		const std::string magenta = ControlSequence::SGR("35");
		const std::string cyan    = ControlSequence::SGR("36");
		const std::string white   = ControlSequence::SGR("37");
		const std::string defaultcolor = ControlSequence::SGR("39");

		const std::string bg_black   = ControlSequence::SGR("40");
		const std::string bg_red     = ControlSequence::SGR("41");
		const std::string bg_green   = ControlSequence::SGR("42");
		const std::string bg_yellow  = ControlSequence::SGR("43");
		const std::string bg_blue    = ControlSequence::SGR("44");
		const std::string bg_magenta = ControlSequence::SGR("45");
		const std::string bg_cyan    = ControlSequence::SGR("46");
		const std::string bg_white   = ControlSequence::SGR("47");
		const std::string bg_default = ControlSequence::SGR("49");

		namespace IndependentControlFunctions {
			// The control sequences set of control functions is specified in §5.5, pp. 12-13
		}

		namespace ControlStrings {
			// Control strings are specified in §5.6, p-p. 13
		}
		
	}

	// ––––––––––––
	// Manipulators

	class Manipulator {
		std::string _control_sequence;
		public:
			Manipulator(const std::string& control_sequence) : _control_sequence(control_sequence) {}
			const std::string& control_sequence() const {return _control_sequence;}
	};

	std::ostream& operator<<(std::ostream& stream, const Manipulator& m) {
		stream << m.control_sequence();
		return stream;
	}

	const Manipulator   black(ECMA48::black);
	const Manipulator     red(ECMA48::red);
	const Manipulator   green(ECMA48::green);
	const Manipulator  yellow(ECMA48::yellow);
	const Manipulator    blue(ECMA48::blue);
	const Manipulator magenta(ECMA48::magenta);
	const Manipulator    cyan(ECMA48::cyan);
	const Manipulator   white(ECMA48::white);
}

#endif

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//