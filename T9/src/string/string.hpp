#ifndef __INK_STRING__HEADER_FILE_
#define __INK_STRING__HEADER_FILE_

#include <string>

namespace ink {
	
	// Personal string derivative
	
	class string : public std::string {
	typedef const char* literal;
		public:
		
		#pragma region Trim
		// Trim esoteric whitespace on the left-hand side of the string
		void trim_left();
		// Trim esoteric whitespace on the right-hand side of the string
		void trim_right();
		// Trim esoteric whitespace
		void trim();
		
		// Return a copy of this string with esoteric whitespace trimmed on the left-hand side
		string trim_copy_left() const;
		// Return a copy of this string with esoteric whitespace trimmed on the right-hand side
		string trim_copy_right() const;
		// Return a copy of this string with esoteric whitespace trimmed
		string trim_copy() const;
		#pragma endregion
		
		#pragma region Case Change
		// Convert all characters to lowercase
		void lowercase();
		// Convert all characters to uppercase
		void uppercase();
		
		// Return a copy of this string with all characters converted to lowercase
		string lowercase_copy() const;
		// Return a copy of this string with all characters converted to uppercase
		string uppercase_copy() const;
		
		#pragma endregion
		
		// Two-way conversion/construction between const char*, and std::string
		
		string() : std::string() {}
		string(const literal& str) : std::string(str) {}
		operator literal() { return c_str(); }
		
		string(const std::string& str) : std::string(str) {}
		string(std::string&& str) : std::string(std::move(str)) {}
	};
	
}

#endif