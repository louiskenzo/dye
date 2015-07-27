//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//                                                                            //
//                                     Dye                                    //
//                                                                            //
//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#pragma once
#ifndef DYE_GUARD
#define DYE_GUARD

// Standard library
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
// POSIX
#include <unistd.h>

// The ECMA48 standard is available in PDF form at:
// http://www.ecma-international.org/publications/files/ECMA-ST/Ecma-048.pdf
// Control functions are specified in §5. Their meaning and representation are
// described in §8.3, pp. 33-74.

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                 ECMA-48 C0                                 //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace ECMA48 {
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
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                 ECMA-48 C1                                 //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace ECMA48 {
		namespace C1 {
			// The C1 set of control functions is specified in §5.3, pp. 8-10.

			// ·················
			// Utility functions

			namespace {
				inline std::string C1(std::string code) {
					assert(code.size()==1);
					return C0::ESC + code;
				}
			}

			// –––––––––––––––––––––––––––––––
			// C1 control function definitions

			const size_t LENGTH = 2; // Number of bytes in a C1 control function

			const std::string APC = C1("_");  // Application Program Command §8.3.2
			const std::string BPH = C1("2");  // Break Permitted Here        §8.3.4
			const std::string CCH = C1("T");  // Cancel Character            §8.3.8
			const std::string CSI = C1("[");  // Control Sequence Introducer §8.3.16
			const std::string DCS = C1("P");  // Device Control String       §8.3.27
			const std::string EPA = C1("W");  // End of Guarded Area         §8.3.46
			const std::string ESA = C1("G");  // End of Selected Area        §8.3.47
			const std::string HTJ = C1("I");  // Character Tabulation With Justification §8.3.61
			const std::string HTS = C1("H");  // Character Tabulation Set    §8.3.62
			const std::string MW  = C1("U");  // Message Waiting             §8.3.83
			const std::string NBH = C1("C");  // No Break Here               §8.3.85
			const std::string NEL = C1("E");  // Next Line                   §8.3.86
			const std::string OSC = C1("]");  // Operating System Command    §8.3.89
			const std::string PLD = C1("K");  // Partial Line Forward        §8.3.92
			const std::string PLU = C1("L");  // Partial Line Backward       §8.3.93
			const std::string PM  = C1("^");  // Privacy Message             §8.3.94
			const std::string PU1 = C1("Q");  // Private Use 1               §8.3.100
			const std::string PU2 = C1("R");  // Private Use 2               §8.3.101
			const std::string RI  = C1("M");  // Reverse Line Feed           §8.3.104
			const std::string SCI = C1("Z");  // Single Character Introducer §8.3.109
			const std::string SOS = C1("X");  // Start Of String             §8.3.128
			const std::string SPA = C1("V");  // Start of Guarded Area       §8.3.129
			const std::string SSA = C1("F");  // Start of Selected Area      §8.3.138
			const std::string SS2 = C1("N");  // Single Shift Two            §8.3.141
			const std::string SS3 = C1("O");  // Single Shift Three          §8.3.142
			const std::string ST  = C1("\\"); // String Terminator           §8.3.143
			const std::string STS = C1("S");  // Set Transmit State          §8.3.145
			const std::string VTS = C1("J");  // Line Tabulation Set         §8.3.162
		}
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                          ECMA-48 Control Sequences                         //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace ECMA48 {
		namespace ControlSequence {
			// Control sequences are specified in §5.4, pp. 10-12

			// ···························································
			// Helper classes and functions for defining control sequences

			namespace {
				inline std::string to_string(size_t n) {
					std::ostringstream s; s<<n; return s.str();
				};

				class numerical_parameter {
					public:
						// Constructors

						numerical_parameter()
							: has_default_(false)
							, default_value_()
							{}

						numerical_parameter(size_t default_value)
							: has_default_(true)
							, default_value_(default_value)
							{}

						static numerical_parameter no_default() {
							return numerical_parameter();
						}

						// Accessors

						inline bool has_default() const {
							return has_default_;
						}

						inline size_t default_value() const {
							assert(has_default());
							return default_value_;
						}

						// Utility functions

						inline bool is_default(size_t n) const {
							return has_default_ && n == default_value_;
						}

					private:
						bool   has_default_;
						size_t default_value_;
				};

				typedef numerical_parameter n;

				class selective_parameter {
					public:
						// Constants

						static const size_t NO_MAX = std::numeric_limits<size_t>::max();

						// Constuctors

						selective_parameter()
							: has_default_(false)
							, default_value_()
							, max_(NO_MAX)
							{}

						selective_parameter(size_t default_value,
						                    size_t max = NO_MAX)
							: has_default_(true)
							, default_value_(default_value)
							, max_(max)
							{}

						static selective_parameter no_default() {
							return selective_parameter();
						}

						static selective_parameter no_default(size_t new_max) {
							return selective_parameter().max(new_max);
						}

						// Accessors

						inline bool has_default() const {
							return has_default_;
						}

						inline size_t default_value() const {
							assert(has_default());
							return default_value_;
						}

						inline size_t max() const {
							return max_;
						}

						// Setters

						selective_parameter& max(size_t new_max) {
							max_ = new_max;
							return *this;
						}

						selective_parameter& default_value(size_t new_default_value) {
							default_value_ = new_default_value;
							return *this;
						}

						// Utility functions

						inline bool is_default(size_t value) const {
							return has_default_ && value == default_value_;
						}

					private:
						bool   has_default_;
						size_t default_value_;
						size_t max_;
				};

				typedef selective_parameter s;

				// (Pn) §8.1.d
				class Pn {
					public:
						Pn(const std::string& end_delimiter)
							: end_delimiter_(end_delimiter)
							, n_(false)
							{}

						Pn(const std::string& end_delimiter, size_t default_n)
							: end_delimiter_(end_delimiter)
							, n_(default_n)
							{}

						inline std::string operator()(size_t v) const {
							if (n_.is_default(v))
								return C1::CSI + end_delimiter_;
							else
								return C1::CSI + to_string(v) + end_delimiter_;
						}

						inline const std::string& operator()() const {
							assert(n_.has_default());
							static const std::string default_parameter_result
							= operator()(n_.default_value());
							return default_parameter_result;
						}

					private:
						const std::string end_delimiter_;
						const numerical_parameter n_;
				};

				// (Pn1;Pn2) §8.1.e
				class Pn1Pn2 {
					public:
						Pn1Pn2(const std::string& end_delimiter)
							: end_delimiter_(end_delimiter)
							, n1_()
							, n2_()
							{}

						Pn1Pn2(const std::string& end_delimiter,
							    size_t default_v1,
							    size_t default_v2)
							: end_delimiter_(end_delimiter)
							, n1_(default_v1)
							, n2_(default_v2)
							{}


						Pn1Pn2(const std::string& end_delimiter,
							    const numerical_parameter& n1,
							    const numerical_parameter& n2)
							  : end_delimiter_(end_delimiter)
							  , n1_(n1)
							  , n2_(n2)
							  {}

						inline std::string operator()(size_t v1, size_t v2) const {
							if (n1_.is_default(v1) && n2_.is_default(v2))
								return C1::CSI + ";" + end_delimiter_;
							else if (n1_.is_default(v1) && !n2_.is_default(v2))
								return C1::CSI + ";" + to_string(v2) + end_delimiter_;
							else if (!n1_.is_default(v1) && n2_.is_default(v2))
								return C1::CSI + to_string(v1) + ";" + end_delimiter_;
							else
								return C1::CSI
								     + to_string(v1) + ";" + to_string(v2)
								     + end_delimiter_;
						}

						inline const std::string& operator()() const {
							assert(n1_.has_default());
							assert(n2_.has_default());
							static const std::string default_parameter_result
							= operator()(n1_.default_value(), n2_.default_value());
							return default_parameter_result;
						}

					private:
						const std::string end_delimiter_;
						const numerical_parameter n1_;
						const numerical_parameter n2_;
				};

				// (Ps) §8.1.g
				class Ps {
					public:
						Ps(const std::string& end_delimiter)
							: end_delimiter_(end_delimiter)
							, s_()
							{}

						Ps(const std::string& end_delimiter,
						   const selective_parameter& s)
							: end_delimiter_(end_delimiter)
							, s_(s)
							{}

						Ps(const std::string& end_delimiter,
						   size_t default_s)
							: end_delimiter_(end_delimiter)
							, s_(default_s)
							{}

						Ps(const std::string& end_delimiter,
						   size_t default_s,
						   size_t max_s)
							: end_delimiter_(end_delimiter)
							, s_(default_s, max_s)
							{}

						inline std::string operator()(size_t s) const {
							assert(s <= s_.max());
							if (s_.is_default(s))
								return C1::CSI + end_delimiter_;
							else
								return C1::CSI + to_string(s) + end_delimiter_;
						}

						inline const std::string& operator()() const {
							assert(s_.has_default());
							static const std::string default_parameter_result
							= operator()(s_.default_value());
							return default_parameter_result;
						}

					private:
						const std::string end_delimiter_;
						const selective_parameter s_;
				};

				// (Ps1;Ps2) §8.1.h
				class Ps1Ps2 {
					public:
						Ps1Ps2(const std::string& end_delimiter,
						       const selective_parameter& s1,
						       const selective_parameter& s2)
							  : end_delimiter_(end_delimiter)
							  , s1_(s1)
							  , s2_(s2)
							  {}

						inline std::string operator()(size_t v1, size_t v2) const {
							assert(v1 <= s1_.max());
							assert(v2 <= s2_.max());
							if (s1_.is_default(v1) && s2_.is_default(v2))
								return C1::CSI + ";" + end_delimiter_;
							else if (s1_.is_default(v1) && !s2_.is_default(v2))
								return C1::CSI + ";" + to_string(v2) + end_delimiter_;
							else if (!s1_.is_default(v1) && s2_.is_default(v2))
								return C1::CSI + to_string(v1) + ";" + end_delimiter_;
							else
								return C1::CSI
								     + to_string(v1) + ";" + to_string(v2)
								     + end_delimiter_;
						}

						inline const std::string& operator()() const {
							assert(s1_.has_default());
							assert(s2_.has_default());
							static const std::string default_parameter_result
							= operator()(s1_.default_value(), s2_.default_value());
							return default_parameter_result;
						}

					private:
						const std::string end_delimiter_;
						const selective_parameter s1_;
						const selective_parameter s2_;
				};

				// (Ps...) §8.1.i
				class Psx {
					public:
						Psx(const std::string& end_delimiter)
							: end_delimiter_(end_delimiter)
							, s_()
							{}

						Psx(const std::string& end_delimiter,
							 size_t default_s)
							: end_delimiter_(end_delimiter)
							, s_(default_s)
							{}

						Psx(const std::string& end_delimiter,
							 size_t default_s,
							 size_t max_s)
							: end_delimiter_(end_delimiter)
							, s_(default_s, max_s)
							{}

						inline const std::string& operator()() const {
							static std::string default_parameter_result;
							if (s_.has_default())
								default_parameter_result = operator()(s_.default_value());
							else
								default_parameter_result = C1::CSI + end_delimiter_;
							return default_parameter_result;
						}

						inline std::string operator()(size_t s) const {
							return C1::CSI + to_string(s)
							               + end_delimiter_;
						}

						inline std::string operator()(size_t s1, size_t s2) const {
							return C1::CSI + to_string(s1)
							         + ";" + to_string(s2)
							               + end_delimiter_;
						}

						inline std::string operator()(size_t s1, size_t s2, size_t s3) const {
							return C1::CSI + to_string(s1)
							         + ";" + to_string(s2)
							         + ";" + to_string(s3)
							               + end_delimiter_;
						}

						inline std::string operator()(size_t s1, size_t s2, size_t s3, size_t s4) const {
							return C1::CSI + to_string(s1)
							         + ";" + to_string(s2)
							         + ";" + to_string(s3)
							         + ";" + to_string(s4)
							               + end_delimiter_;
						}

						inline
						std::string operator()(size_t s1,
						                       size_t s2,
						                       size_t s3,
						                       size_t s4,
						                       size_t s5) const {
							return C1::CSI + to_string(s1)
							         + ";" + to_string(s2)
							         + ";" + to_string(s3)
							         + ";" + to_string(s4)
							         + ";" + to_string(s5)
							               + end_delimiter_;
						}

					private:
						const std::string end_delimiter_;
						const selective_parameter s_;
				};
			}

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x4·

			const Pn ICH("@", 1); // Insert Character          §8.3.64
			const Pn CUU("A", 1); // Cursor Up                 §8.3.22
			const Pn CUD("B", 1); // Cursor Down               §8.3.19
			const Pn CUF("C", 1); // Cursor Right              §8.3.20
			const Pn CUB("D", 1); // Cursor Left               §8.3.18
			const Pn CNL("E", 1); // Cursor Next Line          §8.3.12
			const Pn CPL("F", 1); // Cursor Preceding Line     §8.3.13
			const Pn CHA("G", 1); // Cursor Character Absolute §8.3.9
			const Pn1Pn2 CUP("H", 1, 1); // Cursor Position    §8.3.21
			const Pn CHT("I", 1); // Cursor Forward Tabulation §8.3.10
			const Pn  ED("J", 0); // Erase in Page             §8.3.39
			const Pn  EL("K", 0); // Erase in Line             §8.3.41
			const Pn  IL("L", 1); // Insert Line               §8.3.67
			const Pn  DL("M", 1); // Delete Line               §8.3.32
			const Pn  EF("N", 0); // Erase in Field            §8.3.40
			const Pn  EA("O", 0); // Erase in Area             §8.3.37

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x5·

			const Pn     DCH("P",  1);    // Delete Character                   §8.3.26
			const Ps     SEE("Q",  0, 4); // Select Editing Extent              §8.3.115
			const Pn1Pn2 CPR("R",  1, 1); // Active Position Report             §8.3.14
			const Pn      SU("S",  1);    // Scroll Up                          §8.3.147
			const Pn      SD("T",  1);    // Scroll Down                        §8.3.113
			const Pn      NP("U",  1);    // Next Page                          §8.3.87
			const Pn      PP("V",  1);    // Previous Page                      §8.3.95
			const Psx    CTC("W",  0, 6); // Cursor Tabulation Control          §8.3.17
			const Pn     ECH("X",  1);    // Erase Character                    §8.3.38
			const Pn     CVT("Y",  1);    // Cursor Line Tabulation             §8.3.23
			const Pn     CBT("Z",  1);    // Cursor Backward Tabulation         §8.3.7
			const Ps     SRS("[",  0, 1); // Start Reversed String              §8.3.137
			const Ps     PTX("\\", 0, 5); // Parallel Texts                     §8.3.99
			const Ps     SDS("]",  0, 2); // Start Directer String              §8.3.114
			const Ps    SIMD("^",  0, 1); // Select Implicit Movement Direction §8.3.120

			// –––––––––––––––––––––––––––––––––––––––––
			// Control sequences with final byte in 0x6·

			const Pn     HPA("`", 1);    // Character Position Absolute §8.3.57
			const Pn     HPR("a", 1);    // Character Position Forward  §8.3.59
			const Pn     REP("b", 1);    // Repeat                      §8.3.103
			const Ps      DA("c", 0);    // Device Attributes           §8.3.24
			const Pn     VPA("d", 1);    // Line Position Absolute      §8.3.158
			const Pn     VPR("e", 1);    // Line Position Forward       §8.3.160
			const Pn1Pn2 HVP("f", 1, 1); // Character and Line Position §8.3.63
			const Ps     TBC("g", 0, 5); // Tabulation Clear            §8.3.154
			const Ps      SM("h", s().max(22)); // Set Mode             §8.3.125
			const Ps      MC("i", 0, 7); // Media Copy                  §8.3.82
			const Pn     HPB("j", 1);    // Character Position Backward §8.3.58
			const Pn     VPB("k", 1);    // Line Position Backward      §8.3.159
			const Ps      RM("l", s().max(22)); // Reset Mode           §8.3.106
			const Psx    SGR("m", 0, 65); // Select Graphic Rendition   §8.3.117
			const Ps     DSR("n", 0, 6);  // Device Status Report       §8.3.35
			const Ps     DAQ("o", 0, 11); // Define Area Qualification  §8.3.25

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x4·

			const Pn      SL(" @", 1);     // Scroll Left                    §8.3.121
			const Pn      SR(" A", 1);     // Scroll Right                   §8.3.135
			const Pn1Pn2 GSM(" B", 100, 100); // Graphic Size Modification   §8.3.55
			const Pn     GSS(" C");        // Graphic Size Selection         §8.3.56
			const Ps1Ps2 FNT(" D", s(0).max(9), s(0)); // Font Selection     §8.3.53
			const Pn     TSS(" E");        // Thin Space Specification       §8.3.157
			const Psx    JFY(" F", 0, 8);  // Justify                        §8.3.73
			const Pn1Pn2 SPI(" G");        // Spacing Increment              §8.3.132
			const Psx   QUAD(" H", 0, 6);  // Quad                           §8.3.102
			const Ps     SSU(" I", 0, 8);  // Select Size Unit               §8.3.139
			const Ps     PFS(" J", 0, 15); // Page Format Selection          §8.3.91
			const Ps     SHS(" K", 0, 6);  // Select Character Spacing       §8.3.118
			const Ps     SVS(" L", 0, 9);  // Select Line Spacing            §8.3.149
			const Ps     IGS(" M");        // Identify Graphic Subrepertoire §8.3.66
			const Ps    IDCS(" O", s().max(2));// Identify Device Control String §8.3.65

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x5·

			const Pn     PPA(" P", 1);     // Page Position Absolute                   §8.3.96
			const Pn     PPR(" Q", 1);     // Page Position Forward                    §8.3.98
			const Pn     PPB(" R", 1);     // Page Position Backward                   §8.3.97
			const Ps1Ps2 SPD(" S", s(0,7), s(0,3)); // Select Presentation Directions  §8.3.126
			const Pn1Pn2 DTA(" T");        // Dimension Text Area                      §8.3.36
			const Pn     SLH(" U");        // Set Line Home                            §8.3.122
			const Pn     SLL(" V");        // Set Line Limit                           §8.3.123
			const Pn     FNK(" W");        // Function Key                             §8.3.52
			const Ps    SPQR(" X", 0, 2);  // Select Print Quality and Rapidity        §8.3.134
			const Ps1Ps2 SEF(" Y", s(0,2), s(0,2)); // Sheet Eject and Feed            §8.3.116
			const Ps     PEC(" Z", 0, 2);  // Presentation Expand or Contract          §8.3.90
			const Pn     SSW(" [");        // Select Space Width                       §8.3.140
			const Pn    SACS(" \\", 0);    // Set Additional Character Separation      §8.3.107
			const Psx   SAPV(" ]", 0, 22); // Select Alternative Presentation Variants §8.3.108
			const Ps    STAB(" ^");        // Selective Tabulation                     §8.3.144
			const Ps     GCC(" _", 0, 2);  // Graphic Character Combination            §8.3.54

			// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
			// Control sequences with intermediate byte 0x20 and final byte in 0x6·

			const Pn    TATE("`");             // Tabulation Aligned Trailing Edge  §8.3.153
			const Pn    TALE("a");             // Tabulation Aligned Leading Edge   §8.3.152
			const Pn     TAC("b");             // Tabulation Aligned Centred        §8.3.151
			const Pn1Pn2 TCC("c", n(), n(32)); // Tabulation Centred on Character   §8.3.155
			const Pn     TSR("d");             // Tabulation Stop Remove            §8.3.156
			const Ps     SCO("e", 0, 7);       // Set Character Orientation         §8.3.110
			const Pn    SRCS("f", 0);          // Set Reduced Character Separation  §8.3.136
			const Pn     SCS("g");             // Set Character Spacing             §8.3.112
			const Pn     SLS("h");             // Set Line Spacing                  §8.3.124
			const Pn     SPH("i");             // Set Page Home                     §8.3.131
			const Pn     SPL("j");             // Set Page Limit                    §8.3.133
			const Ps1Ps2 SCP("k", s().max(2), s().max(2)); // Select Character Path §8.3.111

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
		inline std::string foreground_256(size_t code) { return ControlSequence::SGR(38,5,code); }
		inline std::string foreground_24bit(size_t r, size_t g, size_t b) { return ControlSequence::SGR(38,2,r,g,b); }
		const std::string default_color = ControlSequence::SGR(39);

		const std::string   black_background = ControlSequence::SGR(40);
		const std::string     red_background = ControlSequence::SGR(41);
		const std::string   green_background = ControlSequence::SGR(42);
		const std::string  yellow_background = ControlSequence::SGR(43);
		const std::string    blue_background = ControlSequence::SGR(44);
		const std::string magenta_background = ControlSequence::SGR(45);
		const std::string    cyan_background = ControlSequence::SGR(46);
		const std::string   white_background = ControlSequence::SGR(47);
		inline std::string background_256(size_t code) { return ControlSequence::SGR(48,5,code); }
		inline std::string background_24bit(size_t r, size_t g, size_t b) { return ControlSequence::SGR(48,2,r,g,b); }
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
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                    ECMA-48 Independent Control Functions                   //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace ECMA48 {
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
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                           ECMA-48 Control Strings                          //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	namespace ECMA48 {
		namespace ControlString {
			// Control strings are specified in §5.6, p-p. 13

			const size_t DELIMITER_LENGTH = C1::LENGTH;

			inline bool is_opening_delimiter(const std::string& s) {
				return s == C1::APC
				    || s == C1::DCS
				    || s == C1::OSC
				    || s == C1::PM
				    || s == C1::SOS;
			}

			inline bool is_command_string_character(const char c) {
				return (c >= '\x08' && c <= '\x0d')
				    || (c >= '\x20' && c <= '\x7e');
			}


			inline
			bool is_command_string(const std::string::const_iterator& begin,
			                       const std::string::const_iterator& end) {
				for (std::string::const_iterator c = begin ; c != end ; ++c) {
					if (is_command_string_character(*c)) return false;
				}

				return true;
			}

			inline bool is_command_string(const std::string& s) {
				return is_command_string(s.begin(), s.end());
			}

			inline
			bool is_character_string(const std::string::const_iterator& begin,
			                         const std::string::const_iterator& end) {
				static const std::string not_character_string = C1::SOS + C1::ST;
				return std::find_first_of(begin,
				                          end,
				                          not_character_string.begin(),
				                          not_character_string.end()) == end;
			}

			inline bool is_character_string(const std::string& s) {
				return s.find_first_of(C1::SOS + C1::ST) == std::string::npos;
			}

			inline bool is_control_string(const std::string& s) {
				return s.size() >= 2 * C1::LENGTH
				    && s.substr(0, DELIMITER_LENGTH) == C1::SOS
				    && s.substr(s.size() - DELIMITER_LENGTH, DELIMITER_LENGTH) == C1::ST
				    && (is_character_string(s.begin() + DELIMITER_LENGTH,
				                            s.end()   - DELIMITER_LENGTH)
				     || is_command_string(s.begin() + DELIMITER_LENGTH,
				                          s.end()   - DELIMITER_LENGTH));
			}

			inline std::string APC(const std::string& s) { return C1::APC + s + C1::ST; }
			inline std::string DCS(const std::string& s) { return C1::DCS + s + C1::ST; }
			inline std::string OSC(const std::string& s) { return C1::OSC + s + C1::ST; }
			inline std::string  PM(const std::string& s) { return C1::PM  + s + C1::ST; }
			inline std::string SOS(const std::string& s) { return C1::SOS + s + C1::ST; }
		}
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                  RGB model                                 //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	class RGB {
		public:
			float r,g,b;

			RGB(float r, float g, float b)
				: r(r), g(g), b(b)
				{}

			RGB operator*(float m) {
				return RGB(r*m, g*m, b*m);
			}

			float norm() const {
				return std::sqrt(std::pow(r,2) + std::pow(g,2) + std::pow(b,2));
			}

			float distance(const RGB& other) const {
				return std::sqrt(std::pow(other.r-r,2.0f)
				               + std::pow(other.g-g,2.0f)
				               + std::pow(other.b-b,2.0f));
			}

			float distance_to_identity_line() const {
			    // Returns the distance of the 3D point with coordinates (r,g,b) to the r=g=b line.
			    // Simplification of http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
			    return std::sqrt(std::pow(b-g,2.0f) + std::pow(b-r,2.0f) + std::pow(g-r,2.0f))
			         / std::sqrt(3.0f);
			}

			float distance_along_identity_line() const {
				return std::sqrt(std::pow(norm(),2.0f) - std::pow(distance_to_identity_line(),2.0f));
			}

			RGB projection_on_identity_line() const {
				const float d = distance_along_identity_line();
				return RGB(d,d,d);
			}

		private:
			bool _valid() const {
				return (r>=0.0f && r<=255.0f) &&
				       (g>=0.0f && g<=255.0f) &&
				       (b>=0.0f && b<=255.0f);
			}
	};

	inline
	std::ostream& operator<<(std::ostream& stream, const RGB& rgb) {
		stream << "(" << rgb.r << "," << rgb.g << "," << rgb.b << ")";
		return stream;
	}
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
		//   in 6 lines of 36 codes, with a first value at 0, second at 95, then
		//   uniformly increasing red values from 0 to 255; each line is subdivided in 6
		//   blocks of 6 codes with a first value at 0, second at 95, then uniformly
		//   increasing green values from 0 to 255; each block is made of 6 codes, with
		//   a first value at 0, second at 95, then uniformly increasing blue values
		//   from 0 to 255. Note that 6 of those colors are also grey levels.
		// - The last 24 colors are levels of grey, from black to white, *excluding*
		//   black and white.

		// –––––––––
		// Constants

		// Index ranges

		const size_t STANDARD_START = 0;
		const size_t STANDARD_END   = 15;
		const size_t STANDARD_RANGE = STANDARD_END - STANDARD_START + 1;
		const size_t STANDARD_LEVELS = STANDARD_RANGE;

		const size_t STANDARD_DIM_START = 0;
		const size_t STANDARD_DIM_END   = 7;

		const size_t STANDARD_BRIGHT_START = 8;
		const size_t STANDARD_BRIGHT_END   = 15;

		const size_t EXTENDED_START  = 16;
		const size_t EXTENDED_END    = 231;
		const size_t EXTENDED_RANGE  = EXTENDED_END - EXTENDED_START + 1;
		const size_t EXTENDED_LEVELS = 6;

		const size_t GREY_START  = 232;
		const size_t GREY_END    = 255;
		const size_t GREY_RANGE  = GREY_END - GREY_START + 1;
		const size_t GREY_LEVELS = GREY_RANGE;

		// RGB space structure

		const float RGB_EXTENT = 255.0f;

		const float SECOND_EXTENDED_VALUE = 95.0f;
		const float EXTENDED_STEP = (RGB_EXTENT - SECOND_EXTENDED_VALUE) / (EXTENDED_LEVELS - 2);

		const float FIRST_GREY_VALUE = 8.0f;
		const float  LAST_GREY_VALUE = 238.0f;
		const float GREY_EXTENT = LAST_GREY_VALUE - FIRST_GREY_VALUE;
		const float GREY_STEP = GREY_EXTENT / (GREY_LEVELS - 1);

		// ·················
		// Utility functions

		namespace {
			const float _UNIT_CUBE_DIAGONAL = std::sqrt(3.0f);
			const float  _RGB_CUBE_DIAGONAL = RGB_EXTENT * _UNIT_CUBE_DIAGONAL;
			const float _GREY_CUBE_DIAGONAL_STEP = GREY_EXTENT * _UNIT_CUBE_DIAGONAL / (GREY_LEVELS - 1);
			const float _FIRST_GREY_DIAGONAL_VALUE = FIRST_GREY_VALUE * _UNIT_CUBE_DIAGONAL;
			const float  _LAST_GREY_DIAGONAL_VALUE =  LAST_GREY_VALUE * _UNIT_CUBE_DIAGONAL;

			inline int round(float x) {
				assert(x >= 0.0f);
				return std::floor(x + 0.5f);
			}

			inline size_t quantize(float x, float step) {
				return round(x/step);
			}

			struct ExtendedLevels {
				size_t r, g, b;
				ExtendedLevels(size_t r, size_t g, size_t b) : r(r), g(g), b(b) {};
			};

			inline float extended_value_from_extended_level(size_t l) {
				if (l == 0) return 0.0f;
				else if (l == 1) return SECOND_EXTENDED_VALUE;
				else return SECOND_EXTENDED_VALUE + (l-1)*EXTENDED_STEP;
			}

			inline size_t extended_level_from_extended_value(float v) {
				if (v <= SECOND_EXTENDED_VALUE/2.0f) return 0;
				else if (v <= SECOND_EXTENDED_VALUE + EXTENDED_STEP/2.0f) return 1;
				else return 1 + quantize(v - SECOND_EXTENDED_VALUE, EXTENDED_STEP);
			}

			inline ExtendedLevels closest_extended_levels_from_RGB(const RGB& rgb) {
				return ExtendedLevels(extended_level_from_extended_value(rgb.r),
				                      extended_level_from_extended_value(rgb.g),
				                      extended_level_from_extended_value(rgb.b));
			}

			inline size_t closest_grey_level_from_RGB(const RGB& rgb) {
				const float d_along_xyz = rgb.distance_along_identity_line();
				if (d_along_xyz <= _FIRST_GREY_DIAGONAL_VALUE) return 0;
				size_t q_level = quantize(d_along_xyz - _FIRST_GREY_DIAGONAL_VALUE,
				                          _GREY_CUBE_DIAGONAL_STEP);
				if (q_level >= GREY_LEVELS) return GREY_LEVELS - 1;
				else return q_level;
			}
		}

		// ––––––––––––––––
		// Public interface

		inline RGB rgb_from_grey_level(size_t l) {
			assert(l >= 0 && l < GREY_LEVELS);
			if (l == GREY_LEVELS) return RGB(255.0f,255.0f,255.0f);
			const float grey_value = FIRST_GREY_VALUE + l*GREY_STEP;
			return RGB(grey_value, grey_value, grey_value);
		}

		inline RGB rgb_from_extended_levels(size_t rl, size_t gl, size_t bl) {
			assert(rl >= 0 && rl < EXTENDED_LEVELS);
			assert(gl >= 0 && gl < EXTENDED_LEVELS);
			assert(bl >= 0 && bl < EXTENDED_LEVELS);
			return RGB(extended_value_from_extended_level(rl),
			           extended_value_from_extended_level(gl),
			           extended_value_from_extended_level(bl));
		}

		inline RGB rgb_from_extended_levels(const ExtendedLevels& levels) {
			return rgb_from_extended_levels(levels.r, levels.g, levels.b);
		}

		inline size_t ECMA48_from_grey_level(size_t l) {
			assert(l >= 0 && l < GREY_LEVELS);
			return GREY_START + l;
		}

		inline size_t ECMA48_from_extended_levels(size_t rl, size_t gl, size_t bl) {
			assert(rl >= 0 && rl < EXTENDED_LEVELS);
			assert(gl >= 0 && gl < EXTENDED_LEVELS);
			assert(bl >= 0 && bl < EXTENDED_LEVELS);
			return EXTENDED_START + rl*36 + gl*6 + bl;
		}

		inline size_t ECMA48_from_extended_levels(const ExtendedLevels& levels) {
			return ECMA48_from_extended_levels(levels.r, levels.g, levels.b);
		}

		inline size_t ECMA48_from_rgb(size_t r, size_t g, size_t b) {
			const RGB rgb(r,g,b);

			const ExtendedLevels closest_extended_levels = closest_extended_levels_from_RGB(rgb);
			const RGB closest_extended = rgb_from_extended_levels(closest_extended_levels);

			const size_t closest_grey_level = closest_grey_level_from_RGB(rgb);
			const RGB closest_grey = rgb_from_grey_level(closest_grey_level);

			if (rgb.distance(closest_grey) < rgb.distance(closest_extended)) {
				return ECMA48_from_grey_level(closest_grey_level);
			} else {
				return ECMA48_from_extended_levels(closest_extended_levels);
			}
		}
	}
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                Manipulators                                //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	// ··································
	// Utility functions for manipulators

	namespace {
		inline bool is_stdout_stderr_tty(const std::ostream& s) {
			return (s.rdbuf()==std::cout.rdbuf() && isatty(fileno(stdout)))
			    || (s.rdbuf()==std::cerr.rdbuf() && isatty(fileno(stderr)));
		}
	}

	// ––––––––––––––––––––––––
	// Public manipulator tools

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
	inline
	std::ostream& operator<<(std::ostream& stream, const ObjectManipulator<ObjectType>& m) {
		if (is_stdout_stderr_tty(stream)) {
			stream << m.control_sequence()
			       << m.object()
			       << ECMA48::default_color << ECMA48::default_background;
		} else {
			stream << m.object();
		}
		return stream;
	}

	class Manipulator {
		const std::string _control_sequence;
		public:
			Manipulator(const std::string& control_sequence) : _control_sequence(control_sequence) {}
			template <typename ObjectType>
			ObjectManipulator<ObjectType> operator()(const ObjectType& object) const {
				return ObjectManipulator<ObjectType>(_control_sequence, object);
			}
			const std::string& control_sequence() const {return _control_sequence; }
	};

	inline std::ostream& operator<<(std::ostream& stream, const Manipulator& m) {
		if (is_stdout_stderr_tty(stream))
			stream << m.control_sequence();
		return stream;
	}

	// ––––––––––––––––––––
	// 8-color manipulators

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

	// –––––––––––––––––––––––––
	// xterm256 RGB manipulators

	inline Manipulator fg256(size_t i) {
		assert(i <= 255);
		return ECMA48::foreground_256(i);
	}

	inline Manipulator fg256(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::foreground_256(xterm256::ECMA48_from_rgb(r,g,b));
	}

	inline Manipulator bg256(size_t i) {
		assert(i <= 255);
		return ECMA48::background_256(i);
	}

	inline Manipulator bg256(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::background_256(xterm256::ECMA48_from_rgb(r,g,b));
	}

	// –––––––––––––––––––––––
	// 24-bit RGB manipulators

	inline Manipulator fg24bit(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::foreground_24bit(r,g,b);
	}

	inline Manipulator bg24bit(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		return ECMA48::background_24bit(r,g,b);
	}

	// ––––––––––––––––––
	// Auto-selecting RGB

	inline bool terminal_is_24bit_capable() {
		// libvte based 24-bit terminals

		char const* VTE_VERSION = std::getenv("VTE_VERSION");
		bool VTE_24 = VTE_VERSION != 0 // VTE_VERSION is defined
	              && ((VTE_VERSION[0]!=0 && VTE_VERSION[0] >= '4') // Version >= 4
	               || (VTE_VERSION[0]!=0 && VTE_VERSION[0] == '3'
	                && VTE_VERSION[1]!=0 && VTE_VERSION[1] >= '6')); // Version >= 3.6

	    return VTE_24;
	}

	const bool _is_24bit_capable = terminal_is_24bit_capable();

	// RGB manipulators auto-selecting 256 color or 24-bit color base on capabilities

	inline Manipulator fg(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		if (_is_24bit_capable)
			return fg24bit(r,g,b);
		else
			return fg256(r,g,b);
	}

	inline Manipulator fg(const RGB& rgb) { return fg(rgb.r, rgb.g, rgb.b); }

	inline 	Manipulator bg(size_t r, size_t g, size_t b) {
		assert(r <= 255);
		assert(g <= 255);
		assert(b <= 255);
		if (_is_24bit_capable)
			return bg24bit(r,g,b);
		else
			return bg256(r,g,b);
	}

	inline Manipulator bg(const RGB& rgb) { return bg(rgb.r, rgb.g, rgb.b); }
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //
//                                 Color maps                                 //
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– //

namespace dye {
	// ·································
	// Utilities functions for colormaps

	namespace {
		inline float upramp(float x, float center, float width) {
		    return 255.0f * (1.0f + std::tanh(6.0f / width * (x - center))) / 2.0f;
		}

		inline float downramp(float x, float center, float width) {
		    return 255.0f * (1.0f - std::tanh(6.0f / width * (x - center))) / 2.0f;
		}
	}

	// ·············
	// Colormap data

	namespace {
		inline RGB hot_function(float x) {
			return RGB(upramp(x, 1/6.0, 1/3.0),
			           upramp(x, 1/2.0, 1/3.0),
			           upramp(x, 5/6.0, 1/3.0));
		}

	    inline RGB jet_function(float x) {
	        if (x <= 0.5)
	            return RGB(upramp(x, 5/8.0, 1/4.0),
	                       upramp(x, 1/8.0, 1/4.0),
	                     downramp(x, 3/8.0, 1/4.0));
	        else
	            return RGB(upramp(x, 5/8.0, 1/4.0),
	                     downramp(x, 7/8.0, 1/4.0),
	                     downramp(x, 3/8.0, 1/4.0));
	    }

	    inline RGB hsv_function(float x) {
	        if (x<=1/3.0)
	            return RGB(downramp(x, 3/12.0, 1/6.0),
	                         upramp(x, 1/12.0, 1/6.0),
	                       0.0);
	        else if (x<=2/3.0)
	            return RGB(0.0,
	                       downramp(x, 7/12.0, 1/6.0),
	                         upramp(x, 5/12.0, 1/6.0));
	        else
	            return RGB(upramp(x, 9/12.0, 1/6.0),
	                       0.0,
	                       downramp(x, 11/12.0, 1/6.0));
	    }

	    inline RGB good_function(float x) {
	        return RGB(downramp(x, 8/12.0, 2/3.0),
	                     upramp(x, 4/12.0, 2/3.0),
	                   0.0);
	    }

	    inline RGB gray_function(float x) {
	        return RGB(x,x,x) * 255.0f;
	    }
	}

	// –––––––––––––––––––––
	// Colormap public tools

	typedef RGB (*ColormapFunction)(float);

	class Colormap {
		private:
			inline float normalize(float x) const {
				if (x < 0.0f) x = 0.0f;
				if (x > 1.0f) x = 1.0f;
				return x;
			}

		public:
			Colormap(ColormapFunction f) : f_(f) {}

			// fg

			inline Manipulator fg(float x) const {
				return dye::fg(f_(normalize(x)));
			}

			inline Manipulator fg(size_t percentage) const {
				return fg(percentage / 100.0f);
			}

			inline Manipulator fg(int percentage) const {
				return fg(percentage / 100.0f);
			}

			// bg

			inline Manipulator bg(float x) const {
				return dye::bg(f_(normalize(x)));
			}

			inline Manipulator bg(size_t percentage) const {
				return bg(percentage / 100.0f);
			}

			inline Manipulator bg(int percentage) const {
				return bg(percentage / 100.0f);
			}

			// operator()

			Manipulator operator()(float x) const {
				return fg(x);
			}

			Manipulator operator()(size_t percentage) const {
				return fg(percentage);
			}

			Manipulator operator()(int percentage) const {
				return fg(percentage);
			}

		private:
			ColormapFunction f_;
	};

	template <size_t SIZE>
	class ColormapLUT {
		private:
			inline size_t index(float x) const {
				if (x < 0.0f) return 0;
				if (x > 1.0f) return SIZE-1;
				return x*(SIZE-1);
			}

			void computeLUT_(const Colormap& c) {
				fg_lut_.clear();
				bg_lut_.clear();
				fg_lut_.reserve(SIZE);
				bg_lut_.reserve(SIZE);

				for (size_t i=0; i<SIZE; ++i) {
					fg_lut_.push_back(c.fg(i / float(SIZE-1)));
					bg_lut_.push_back(c.bg(i / float(SIZE-1)));
				}
			}

		public:
			ColormapLUT(ColormapFunction f) {
				computeLUT_(Colormap(f));
			}

			ColormapLUT(const Colormap& c) {
				computeLUT_(c);
			}

			// fg

			inline Manipulator fg(float x) const {
				return fg_lut_[index(x)];
			}

			inline Manipulator fg(size_t percentage) const {
				return fg(percentage / 100.0f);
			}

			inline Manipulator fg(int percentage) const {
				return fg(percentage / 100.0f);
			}

			// bg

			inline Manipulator bg(float x) const {
				return bg_lut_[index(x)];
			}

			inline Manipulator bg(size_t percentage) const {
				return bg(percentage / 100.0f);
			}

			inline Manipulator bg(int percentage) const {
				return bg(percentage / 100.0f);
			}

			// operator()

			Manipulator operator()(float x) const {
				return fg(x);
			}

			Manipulator operator()(size_t percentage) const {
				return fg(percentage);
			}

			Manipulator operator()(int percentage) const {
				return fg(percentage);
			}

		private:
			std::vector<Manipulator> fg_lut_;
			std::vector<Manipulator> bg_lut_;
	};

	// –––––––––
	// Colormaps

	Colormap  hot(hot_function);
	Colormap  jet(jet_function);
	Colormap  hsv(hsv_function);
	Colormap good(good_function);
	Colormap gray(gray_function);

	ColormapLUT<100>  hot100(hot);
	ColormapLUT<100>  jet100(jet);
	ColormapLUT<100>  hsv100(hsv);
	ColormapLUT<100> good100(good);
	ColormapLUT<100> gray100(gray);
}

#endif

//–––––––––––––––––––––––––––––––––––– ∎ –––––––––––––––––––––––––––––––––––––//
