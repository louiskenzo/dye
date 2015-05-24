//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//                                                                            //
//                                     Dye                                    //
//                                                                            //
//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#pragma once
#ifndef DYE_GUARD
#define DYE_GUARD

#include <algorithm>
#include <cassert>
#include <cmath>
#include <ostream>
#include <string>
#include <sstream>

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                   ECMA-48                                  //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

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

			// –––––––––––––––––––––––––––––––––––––––––––––––
			// Helper functions for defining control sequences

			inline std::string _to_string(size_t n) {
				std::ostringstream s; s<<n; return s.str();
			};

			// (Pn) §8.1.d
			class _Pn {
				public:
					_Pn(std::string end_delimiter, size_t default_n)
						: end_delimiter_(end_delimiter)
						, default_n_(default_n)
						{}

					inline
					std::string operator()(size_t n) const {
						return C1::CSI + _to_string(n) + end_delimiter_;
					}

					inline
					const std::string& operator()() const {
						static const std::string default_parameter_result
						= operator()(default_n_);
						return default_parameter_result;
					}

				private:
					std::string  end_delimiter_;
					const size_t default_n_;
			};

			// (Pn1;Pn2) §8.1.e
			class _Pn1Pn2 {
				public:
					_Pn1Pn2(std::string end_delimiter, size_t default_n1, size_t default_n2)
						  : end_delimiter_(end_delimiter)
						  , default_n1_(default_n1)
						  , default_n2_(default_n2)
						  {}

					inline
					std::string operator()(size_t n1, size_t n2) const {
						return C1::CSI
						     + _to_string(n1) + ";" + _to_string(n2)
						     + end_delimiter_;
					}

					inline
					const std::string& operator()() const {
						static const std::string default_parameter_result
						= operator()(default_n1_, default_n2_);
						return default_parameter_result;
					}

				private:
					std::string  end_delimiter_;
					const size_t default_n1_;
					const size_t default_n2_;
			};

			// (Ps...) §8.1.i
			class _Psx {
				public:
					_Psx(std::string end_delimiter, int default_s = -1)
						: end_delimiter_(end_delimiter)
						, default_s_(default_s)
					{
						assert(default_s >= -1);
					}

					inline
					const std::string& operator()() const {
						static std::string default_parameter_result;
						if (has_default())
							default_parameter_result = operator()(default_s_);
						else
							default_parameter_result = C1::CSI + end_delimiter_;
						return default_parameter_result;
					}

					inline
					std::string operator()(size_t s) const {
						return C1::CSI + _to_string(s)
						               + end_delimiter_;
					}

					inline
					std::string operator()(size_t s1, size_t s2) const {
						return C1::CSI + _to_string(s1)
						         + ";" + _to_string(s2)
						               + end_delimiter_;
					}

					inline
					std::string operator()(size_t s1, size_t s2, size_t s3) const {
						return C1::CSI + _to_string(s1)
						         + ";" + _to_string(s2)
						         + ";" + _to_string(s3)
						               + end_delimiter_;
					}

					inline
					std::string operator()(size_t s1, size_t s2, size_t s3, size_t s4) const {
						return C1::CSI + _to_string(s1)
						         + ";" + _to_string(s2)
						         + ";" + _to_string(s3)
						         + ";" + _to_string(s4)
						               + end_delimiter_;
					}

					inline
					std::string operator()(size_t s1,
					                       size_t s2,
					                       size_t s3,
					                       size_t s4,
					                       size_t s5) const {
						return C1::CSI + _to_string(s1)
						         + ";" + _to_string(s2)
						         + ";" + _to_string(s3)
						         + ";" + _to_string(s4)
						         + ";" + _to_string(s5)
						               + end_delimiter_;
					}

				private:
					std::string end_delimiter_;
					const int   default_s_;

					inline bool has_default() const { return default_s_<0; }
			};

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x4·

			const _Pn ICH("@", 1); // Insert Character          §8.3.64
			const _Pn CUU("A", 1); // Cursor Up                 §8.3.22
			const _Pn CUD("B", 1); // Cursor Down               §8.3.19
			const _Pn CUF("C", 1); // Cursor Right              §8.3.20
			const _Pn CUB("D", 1); // Cursor Left               §8.3.18
			const _Pn CNL("E", 1); // Cursor Next Line          §8.3.12
			const _Pn CPL("F", 1); // Cursor Preceding Line     §8.3.13
			const _Pn CHA("G", 1); // Cursor Character Absolute §8.3.9
			const _Pn1Pn2 CUP("H", 1, 1); // Cursor Position    §8.3.21
			const _Pn CHT("I", 1); // Cursor Forward Tabulation §8.3.10
			const _Pn  ED("J", 0); // Erase in Page             §8.3.39
			const _Pn  EL("K", 0); // Erase in Line             §8.3.41
			const _Pn  IL("L", 1); // Insert Line               §8.3.67
			const _Pn  DL("M", 1); // Delete Line               §8.3.32
			const _Pn  EF("N", 0); // Erase in Field            §8.3.40
			const _Pn  EA("O", 0); // Erase in Area             §8.3.37

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
			_Psx SGR("m", 0); // Select Graphic Rendition §8.3.117
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

		const std::string                  reset = ControlSequence::SGR(0);
		const std::string                   bold = ControlSequence::SGR(1);
		const std::string                  faint = ControlSequence::SGR(2);
		const std::string                 italic = ControlSequence::SGR(3);
		const std::string             underlined = ControlSequence::SGR(4);
		const std::string          slow_blinking = ControlSequence::SGR(5);
		const std::string         rapid_blinking = ControlSequence::SGR(6);
		const std::string               negative = ControlSequence::SGR(7);
		const std::string              concealed = ControlSequence::SGR(8);
		const std::string                crossed = ControlSequence::SGR(9);
		const std::string                  font0 = ControlSequence::SGR(11);
		const std::string                  font1 = ControlSequence::SGR(11);
		const std::string                  font2 = ControlSequence::SGR(12);
		const std::string                  font3 = ControlSequence::SGR(13);
		const std::string                  font4 = ControlSequence::SGR(14);
		const std::string                  font5 = ControlSequence::SGR(15);
		const std::string                  font6 = ControlSequence::SGR(16);
		const std::string                  font7 = ControlSequence::SGR(17);
		const std::string                  font8 = ControlSequence::SGR(18);
		const std::string                  font9 = ControlSequence::SGR(19);
		const std::string                fraktur = ControlSequence::SGR(20);
		const std::string      doubly_underlined = ControlSequence::SGR(21);
		const std::string     not_bold_not_faint = ControlSequence::SGR(22);
		const std::string not_italic_not_fraktur = ControlSequence::SGR(23);
		const std::string         not_underlined = ControlSequence::SGR(24);
		const std::string           not_blinking = ControlSequence::SGR(25);
		const std::string         positive_image = ControlSequence::SGR(27);
		const std::string               revealed = ControlSequence::SGR(28);
		const std::string            not_crossed = ControlSequence::SGR(29);

		const std::string   black = ControlSequence::SGR(30);
		const std::string     red = ControlSequence::SGR(31);
		const std::string   green = ControlSequence::SGR(32);
		const std::string  yellow = ControlSequence::SGR(33);
		const std::string    blue = ControlSequence::SGR(34);
		const std::string magenta = ControlSequence::SGR(35);
		const std::string    cyan = ControlSequence::SGR(36);
		const std::string   white = ControlSequence::SGR(37);
		std::string foreground_256(size_t code) { return ControlSequence::SGR(38,5,code); }
		std::string foreground_24bit(size_t r, size_t g, size_t b) { return ControlSequence::SGR(38,2,r,g,b); }
		const std::string default_color = ControlSequence::SGR(39);

		const std::string   black_background = ControlSequence::SGR(40);
		const std::string     red_background = ControlSequence::SGR(41);
		const std::string   green_background = ControlSequence::SGR(42);
		const std::string  yellow_background = ControlSequence::SGR(43);
		const std::string    blue_background = ControlSequence::SGR(44);
		const std::string magenta_background = ControlSequence::SGR(45);
		const std::string    cyan_background = ControlSequence::SGR(46);
		const std::string   white_background = ControlSequence::SGR(47);
		std::string background_256(size_t code) { return ControlSequence::SGR(48,5,code); }
		std::string background_24bit(size_t r, size_t g, size_t b) { return ControlSequence::SGR(48,2,r,g,b); }
		const std::string default_background = ControlSequence::SGR(49);

		const std::string                   framed = ControlSequence::SGR(51);
		const std::string                encircled = ControlSequence::SGR(52);
		const std::string                overlined = ControlSequence::SGR(53);
		const std::string not_framed_not_encircled = ControlSequence::SGR(54);
		const std::string            not_overlined = ControlSequence::SGR(55);

		const std::string ideogram_underline        = ControlSequence::SGR(60);
		const std::string ideogram_double_underline = ControlSequence::SGR(61);
		const std::string ideogram_overline         = ControlSequence::SGR(62);
		const std::string ideogram_double_overline  = ControlSequence::SGR(63);
		const std::string ideogram_stress_marking   = ControlSequence::SGR(64);
		const std::string not_ideogram              = ControlSequence::SGR(65);

		const std::string        right_side_line = ideogram_underline;
		const std::string double_right_side_line = ideogram_double_underline;
		const std::string         left_side_line = ideogram_overline;
		const std::string  double_left_side_line = ideogram_double_overline;
		const std::string          not_side_line = not_ideogram;

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
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                  RGB model                                 //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	class RGB {
		public:
			float x,y,z;

			RGB(float x, float y, float z)
				: x(x), y(y), z(z) {
				assert(_valid());
			}

			RGB operator*(float m) {
				return RGB(x*m, y*m, z*m);
			}

			float norm() const {
				return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
			}

			float distance(const RGB& other) const {
				return std::sqrt(std::pow(other.x-x,2)
					           + std::pow(other.y-y,2)
					           + std::pow(other.z-z,2));
			}

			float distance_to_identity_line() const {
			    // Returns the distance of the 3D point with coordinates (x,y,z) to the x=y=z line.
			    // Simplification of http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
			    return std::sqrt(std::pow(z-y,2) + std::pow(z-x,2) + std::pow(y-x,2))
			         / std::sqrt(3.0f);
			}

			float distance_along_identity_line() const {
				return std::sqrt(std::pow(norm(),2) - std::pow(distance_to_identity_line(),2));
			}

			RGB projection_on_identity_line() const {
				const float d = distance_along_identity_line();
				return RGB(d,d,d);
			}

		private:
			bool _valid() const {
				return (x>=0.0f && x<=255.0f) &&
				       (y>=0.0f && y<=255.0f) &&
				       (z>=0.0f && z<=255.0f);
			}
	};
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                               XTerm 256-color                              //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace xterm256 {
		// Analysis of how 256-color codes are generated:
		// - The first 16 indices are the standard colors (0-7 for non-bold, 8-15 for
		//   bold).
		// - The middle 216 (6*6*6) colors are extended xterm colors. They are organized
		//   in 6 lines of 36 codes, with internally uniform, increasing red values from
		//   0 to 255; each line is subdivided in 6 blocks of 6 codes with internally
		//   uniform, increasing green values from 0 to 255; each block is made of 6
		//   codes, with increasing blue values from 0 to 255. Thus the RGB colorspace
		//   is quantized in 255/6 = 42.5 increments. Note that 6 of those colors are
		//   also grey levels, that coincide with grey levels in the last 24-color
		//   block.
		// - The last 24 colors are levels of grey, from black to white.

		// –––––––––
		// Constants

		// Index ranges

		const size_t STANDARD_START = 0;
		const size_t STANDARD_END   = 15;
		const size_t STANDARD_RANGE = STANDARD_END - STANDARD_START + 1;
		const size_t STANDARD_LEVELS = STANDARD_RANGE;
		const size_t EXTENDED_START  = 16;
		const size_t EXTENDED_END    = 231;
		const size_t EXTENDED_RANGE  = EXTENDED_END - EXTENDED_START + 1;
		const size_t EXTENDED_LEVELS = 6;
		const size_t GREY_START  = 232;
		const size_t GREY_END    = 255;
		const size_t GREY_RANGE  = GREY_END - GREY_START + 1;
		const size_t GREY_LEVELS = GREY_RANGE;

		// RGB space structure

		const float  RGB_EXTENT = 255.0f;
		const float _UNIT_CUBE_DIAGONAL = std::sqrt(3.0f);
		const float  _RGB_CUBE_DIAGONAL = RGB_EXTENT * _UNIT_CUBE_DIAGONAL;
		const float EXTENDED_STEP = RGB_EXTENT / (EXTENDED_LEVELS - 1);
		const float     GREY_STEP = RGB_EXTENT /     (GREY_LEVELS - 1);

		// –––––––––––––––––
		// Utility functions

		int _round(float x) {
			assert(x >= 0.0f);
			return std::floor(x + 0.5f);
		}

		float _norm(float x, float y, float z) {
			return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
		}

		float _distance(float x1, float y1, float z1,
			            float x2, float y2, float z2) {
			return _norm(x2-x1, y2-y1, z2-z1);
		}

		float distance_to_identity_line(float x, float y, float z) {
		    // Returns the distance of the 3D point with coordinates (x,y,z) to the x=y=z line.
		    // Simplification of http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
		    return std::sqrt(std::pow(z-y,2) + std::pow(z-x,2) + std::pow(y-x,2))
		         / std::sqrt(3.0f);
		}

		size_t _quantize(float x, float step) {
			return _round(x/step);
		}

		size_t _quantize_extended(float x) {
			return _quantize(x, EXTENDED_STEP);
		}

		size_t _quantize_grey(float x) {
			return _quantize(x, GREY_STEP);
		}

		// ––––––––––––––––
		// Public interface

		RGB rgb_from_grey_level(size_t l) {
			assert(l >= GREY_START);
			assert(l <= GREY_END);
			return RGB(l*GREY_STEP, l*GREY_STEP, l*GREY_STEP);
		}

		RGB rgb_from_extended_levels(size_t rl, size_t gl, size_t bl) {
			assert(rl >= 0 && rl <= EXTENDED_LEVELS);
			assert(gl >= 0 && gl <= EXTENDED_LEVELS);
			assert(bl >= 0 && bl <= EXTENDED_LEVELS);
			return RGB(rl*EXTENDED_STEP, gl*EXTENDED_STEP, bl*EXTENDED_STEP);
		}

		size_t ECMA48_from_grey_level(size_t l) {
			return GREY_START + l;
		}

		size_t ECMA48_from_extended_level(size_t rl, size_t gl, size_t bl) {
			return EXTENDED_START + rl*36 + gl*6 + bl;
		}

		size_t ECMA48_from_rgb(size_t r, size_t g, size_t b) {
			const RGB rgb(r,g,b);
			const size_t qr = _quantize_extended(r * EXTENDED_STEP);
			const size_t qg = _quantize_extended(g * EXTENDED_STEP);
			const size_t qb = _quantize_extended(b * EXTENDED_STEP);
			const RGB qrgb(qr,qg,qb);

			float d_along_xyz = rgb.distance_along_identity_line();
			size_t closest_grey_level = _quantize(d_along_xyz, GREY_STEP * _UNIT_CUBE_DIAGONAL);
			RGB closest_grey = rgb_from_grey_level(closest_grey_level);

			float d_to_closest_grey = rgb.distance(closest_grey);
			float d_to_closest_extended = rgb.distance(qrgb);

			if (d_to_closest_grey < d_to_closest_extended)
				return ECMA48_from_grey_level(closest_grey_level);
			else
				return ECMA48_from_extended_level(qr,qg,qb);
		}
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                Manipulators                                //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	template <typename ObjectType>
	class ObjectManipulator {
		const std::string _control_sequence;
		const ObjectType& _object;
		public:
			ObjectManipulator(const std::string& control_sequence, const ObjectType& object)
				: _control_sequence(control_sequence), _object(object) {}
			const std::string& control_sequence() const {return _control_sequence;}
			const ObjectType& object() const {return _object; }
	};

	template <typename ObjectType>
	std::ostream& operator<<(std::ostream& stream, const ObjectManipulator<ObjectType>& m) {
		stream << m.control_sequence()
		       << m.object()
		       << ECMA48::default_color << ECMA48::default_background;
		return stream;
	}

	class Manipulator {
		const std::string _control_sequence;
		public:
			Manipulator(const std::string& control_sequence) : _control_sequence(control_sequence) {}
			template <typename ObjectType>
			ObjectManipulator<ObjectType> operator()(const ObjectType& object) {
				return ObjectManipulator<ObjectType>(_control_sequence, object);
			}
			const std::string& control_sequence() const {return _control_sequence; }
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
	const Manipulator   reset(ECMA48::default_color);

	const Manipulator   black_bg(ECMA48::black_background);
	const Manipulator     red_bg(ECMA48::red_background);
	const Manipulator   green_bg(ECMA48::green_background);
	const Manipulator  yellow_bg(ECMA48::yellow_background);
	const Manipulator    blue_bg(ECMA48::blue_background);
	const Manipulator magenta_bg(ECMA48::magenta_background);
	const Manipulator    cyan_bg(ECMA48::cyan_background);
	const Manipulator   white_bg(ECMA48::white_background);
	const Manipulator   reset_bg(ECMA48::default_background);

	Manipulator fg(size_t i) {
		assert(i <= 255);
		return ECMA48::foreground_256(i);
	}

	Manipulator fg(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::foreground_24bit(r,g,b);
	}

	Manipulator bg(size_t i) {
		assert(i <= 255);
		return ECMA48::background_256(i);
	}

	Manipulator bg(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::background_24bit(r,g,b);
	}
}

#endif

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
