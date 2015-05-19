//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#pragma once
#ifndef DYE_GUARD
#define DYE_GUARD

#include <algorithm>
#include <cassert>
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

			size_t LENGTH = 2; // Number of bytes in a C1 control function

			// ––––––––––––––––––––––––––––––––––––––––––––––––––
			// Helper functions for defining C1 control functions

			std::string _C1(std::string code) {
				assert(code.size()==1);
				return C0::ESC + code;
			}

			// –––––––––––––––––––––––––––––––
			// C1 control function definitions

			const std::string APC = _C1("_");  // Application Program Command §8.3.2
			const std::string BPH = _C1("2");  // Break Permitted Here        §8.3.4
			const std::string CCH = _C1("T");  // Cancel Character            §8.3.8
			const std::string CSI = _C1("[");  // Control Sequence Introducer §8.3.16
			const std::string DCS = _C1("P");  // Device Control String       §8.3.27
			const std::string EPA = _C1("W");  // End of Guarded Area         §8.3.46
			const std::string ESA = _C1("G");  // End of Selected Area        §8.3.47
			const std::string HTJ = _C1("I");  // Character Tabulation With Justification §8.3.61
			const std::string HTS = _C1("H");  // Character Tabulation Set    §8.3.62
			const std::string MW  = _C1("U");  // Message Waiting             §8.3.83
			const std::string NBH = _C1("C");  // No Break Here               §8.3.85
			const std::string NEL = _C1("E");  // Next Line                   §8.3.86
			const std::string OSC = _C1("]");  // Operating System Command    §8.3.89
			const std::string PLD = _C1("K");  // Partial Line Forward        §8.3.92
			const std::string PLU = _C1("L");  // Partial Line Backward       §8.3.93
			const std::string PM  = _C1("^");  // Privacy Message             §8.3.94
			const std::string PU1 = _C1("Q");  // Private Use 1               §8.3.100
			const std::string PU2 = _C1("R");  // Private Use 2               §8.3.101
			const std::string RI  = _C1("M");  // Reverse Line Feed           §8.3.104
			const std::string SCI = _C1("Z");  // Single Character Introducer §8.3.109
			const std::string SOS = _C1("X");  // Start Of String             §8.3.128
			const std::string SPA = _C1("V");  // Start of Guarded Area       §8.3.129
			const std::string SSA = _C1("F");  // Start of Selected Area      §8.3.138
			const std::string SS2 = _C1("N");  // Single Shift Two            §8.3.141
			const std::string SS3 = _C1("O");  // Single Shift Three          §8.3.142
			const std::string ST  = _C1("\\"); // String Terminator           §8.3.143
			const std::string STS = _C1("S");  // Set Transmit State          §8.3.145
			const std::string VTS = _C1("J");  // Line Tabulation Set         §8.3.162
		}

		namespace ControlSequence {
			// Control sequences are specified in §5.4, pp. 10-12

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x4·

			// TODO ICH Insert Character          §8.3.64
			// TODO CUU Cursor Up                 §8.3.22
			// TODO CUD Cursor Down               §8.3.19
			// TODO CUF Cursor Right              §8.3.20
			// TODO CUB Cursor Left               §8.3.18
			// TODO CNL Cursor Next Line          §8.3.12
			// TODO CPL Cursor Preceding Line     §8.3.13
			// TODO CHA Cursor Character Absolute §8.3.9
			// TODO CUP Cursor Position           §8.3.21
			// TODO CHT Cursor Forward Tabulation §8.3.10
			// TODO ED  Erase in Page             §8.3.39
			// TODO EL  Erase in Line             §8.3.41
			// TODO IL  Insert Line               §8.3.67
			// TODO DL  Delete Line               §8.3.32
			// TODO EF  Erase in Field            §8.3.40
			// TODO EA  Erase in Area             §8.3.37

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x5·

			// TODO DCH  Delete Character                   §8.3.26
			// TODO SEE  Select Editing Extent              §8.3.115
			// TODO CPR  Active Position Report             §8.3.14
			// TODO SU   Scroll Up                          §8.3.147
			// TODO SD   Scroll Down                        §8.3.113
			// TODO NP   Next Page                          §8.3.87
			// TODO PP   Previous Page                      §8.3.95
			// TODO CTC  Cursor Tabulation Control          §8.3.17
			// TODO ECH  Erase Character                    §8.3.38
			// TODO CVT  Cursor Line Tabulation             §8.3.23
			// TODO CBT  Cursor Backward Tabulation         §8.3.7
			// TODO SRS  Start Reversed String              §8.3.137
			// TODO PTX  Parallel Texts                     §8.3.99
			// TODO SDS  Start Directer String              §8.3.114
			// TODO SIMD Select Implicit Movement Direction §8.3.120

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x6·

			// TODO HPA Character Position Absolute §8.3.57
			// TODO HPR Character Position Forward  §8.3.59
			// TODO REP Repeat                      §8.3.103
			// TODO DA  Device Attributes           §8.3.24
			// TODO VPA Line Position Absolute      §8.3.158
			// TODO VPR Line Position Forward       §8.3.160
			// TODO HVP Character and Line Position §8.3.63
			// TODO TBC Tabulation Clear            §8.3.154
			// TODO SM  Set Mode                    §8.3.125
			// TODO MC  Media Copy                  §8.3.82
			// TODO HPB Character Position Backward §8.3.58
			// TODO VPB Line Position Backward      §8.3.159
			// TODO RM  Reset Mode                  §8.3.106

			// Select Graphic Rendition §8.3.117
			std::string SGR(const std::string& code) {return C1::CSI + code + "m";}

			// TODO DSR Device Status Report      §8.3.35
			// TODO DAQ Define Area Qualification §8.3.25

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x4·

			// TODO SL   Scroll Left                    §8.3.121
			// TODO SR   Scroll Right                   §8.3.135
			// TODO GSM  Graphic Size Modification      §8.3.55
			// TODO GSS  Graphic Size Selection         §8.3.56
			// TODO FNT  Font Selection                 §8.3.53
			// TODO TSS  Thin Space Specification       §8.3.157
			// TODO JFY  Justify                        §8.3.73
			// TODO SPI  Spacing Increment              §8.3.132
			// TODO QUAD Quad                           §8.3.102
			// TODO SSU  Select Size Unit               §8.3.139
			// TODO PFS  Page Format Selection          §8.3.91
			// TODO SHS  Select Character Spacing       §8.3.118
			// TODO SVS  Select Line Spacing            §8.3.149
			// TODO IGS  Identify Graphic Subrepertoire §8.3.66
			// TODO IDCS Identify Device Control String §8.3.65

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x5·

			// TODO PPA  Page Position Absolute              §8.3.96
			// TODO PPR  Page Position Forward               §8.3.98
			// TODO PPB  Page Position Backward              §8.3.97
			// TODO SPD  Select Presentation Directions      §8.3.126
			// TODO DTA  Dimension Text Area                 §8.3.36
			// TODO SLH  Set Line Home                       §8.3.122
			// TODO SLL  Set Line Limit                      §8.3.123
			// TODO FNK  Function Key                        §8.3.52
			// TODO SPQR Select Print Quality and Rapidity   §8.3.134
			// TODO SEF  Sheet Eject and Feed                §8.3.116
			// TODO PEC  Presentation Expand or Contract     §8.3.90
			// TODO SSW  Select Space Width                  §8.3.140
			// TODO SACS Set Additional Character Separation §8.3.107
			// TODO SAPV Select Alternative Presentation Variants §8.3.108
			// TODO STAB Selective Tabulation                §8.3.144
			// TODO GCC  Graphic Character Combination       §8.3.54

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x6·

			// TODO TATE Tabulation Aligned Trailing Edge §8.3.153
			// TODO TALE Tabulation Aligned Leading Edge  §8.3.152
			// TODO TAC  Tabulation Aligned Centred       §8.3.151
			// TODO TCC  Tabulation Centred on Character  §8.3.155
			// TODO TSR  Tabulation Stop Remove           §8.3.156
			// TODO SCO  Set Character Orientation        §8.3.110
			// TODO SRCS Set Reduced Character Separation §8.3.136
			// TODO SCS  Set Character Spacing            §8.3.112
			// TODO SLS  Set Line Spacing                 §8.3.124
			// TODO SPH  Set Page Home                    §8.3.131
			// TODO SPL  Set Page Limit                   §8.3.133
			// TODO SCP  Select Character Path            §8.3.111

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

			const std::string DMI  = C0::ESC + "`"; // Disable Manual Input      §8.3.34
			const std::string INT  = C0::ESC + "a"; // Escape                    §8.3.68
			const std::string EMI  = C0::ESC + "b"; // Enable Manual Input       §8.3.43
			const std::string RIS  = C0::ESC + "c"; // Reset to Initial State    §8.3.105
			const std::string CMD  = C0::ESC + "d"; // Coding Method Delimiter   §8.3.11
			const std::string LS2  = C0::ESC + "n"; // Locking-Shift Two         §8.3.78
			const std::string LS3  = C0::ESC + "o"; // Locking-Shift Three       §8.3.80
			const std::string LS3R = C0::ESC + "|"; // Locking-Shift Three Right §8.3.81
			const std::string LS2R = C0::ESC + "}"; // Locking-Shift Two Right   §8.3.79
			const std::string LS1R = C0::ESC + "~"; // Locking-Shift One Right   §8.3.77
		}

		namespace ControlString {
			// Control strings are specified in §5.6, p-p. 13

			size_t DELIMITER_LENGTH = C1::LENGTH;

			bool is_opening_delimiter(const std::string& s) {
				return s == C1::APC
				    || s == C1::DCS
				    || s == C1::OSC
				    || s == C1::PM
				    || s == C1::SOS;
			}

			bool is_command_string_character(const char c) {
				return (c >= '\x08' && c <= '\x0d')
				    || (c >= '\x20' && c <= '\x7e');
			}


			bool is_command_string(const std::string::const_iterator& begin,
				                   const std::string::const_iterator& end) {
				for (std::string::const_iterator c = begin ; c != end ; ++c) {
					if (is_command_string_character(*c)) return false;
				}

				return true;
			}

			bool is_command_string(const std::string& s) {
				return is_command_string(s.begin(), s.end());
			}

			bool is_character_string(const std::string::const_iterator& begin,
				                     const std::string::const_iterator& end) {
				static const std::string not_character_string = C1::SOS + C1::ST;
				return std::find_first_of(begin,
				                          end,
				                          not_character_string.begin(),
				                          not_character_string.end()) == end;
			}

			bool is_character_string(const std::string& s) {
				return s.find_first_of(C1::SOS + C1::ST) == std::string::npos;
			}

			bool is_control_string(const std::string& s) {
				return s.size() >= 2 * C1::LENGTH
				    && s.substr(0, DELIMITER_LENGTH) == C1::SOS
				    && s.substr(s.size() - DELIMITER_LENGTH, DELIMITER_LENGTH) == C1::ST
				    && (is_character_string(s.begin() + DELIMITER_LENGTH,
				                            s.end()   - DELIMITER_LENGTH)
				     || is_command_string(s.begin() + DELIMITER_LENGTH,
				                          s.end()   - DELIMITER_LENGTH));
			}

			std::string APC(const std::string& s) { return C1::APC + s + C1::ST; }
			std::string DCS(const std::string& s) { return C1::DCS + s + C1::ST; }
			std::string OSC(const std::string& s) { return C1::OSC + s + C1::ST; }
			std::string  PM(const std::string& s) { return C1::PM  + s + C1::ST; }
			std::string SOS(const std::string& s) { return C1::SOS + s + C1::ST; }
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
