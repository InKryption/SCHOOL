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
		
		// Conversion to string and null-terminated string
		
		#pragma region CONSTRUCTORS
		
		string(const char* __s) : std::string(__s) {}
		string() : std::string() {}
		string(const std::allocator<char>& __a) : std::string(__a) {}
		string(std::string&& __str) : std::string(__str) {}
		string(const std::string& __str) : std::string(__str) {}
		string(const char* __s, const std::allocator<char>& __a) : std::string(__s, __a) {}
		string(std::initializer_list<char> __l, const std::allocator<char>& __a) : std::string(__l, __a) {}
		string(std::string&& __str, const std::allocator<char>& __a) : std::string(__str, __a) {}
		string(const std::string& __str, const std::allocator<char>& __a) : std::string(__str, __a) {}
		
		template<typename _InputIterator>
		string(_InputIterator __beg, _InputIterator __end, const std::allocator<char>& __a) : std::string(__beg, __end, __a) {}
		
		string(std::size_t __n, char __c, const std::allocator<char>& __a) : std::string(__n, __c, __a) {}
		string(const char* __s, std::size_t __n, const std::allocator<char>& __a) : std::string(__s, __n, __a) {}
		string(const std::string& __str, std::size_t __pos, std::size_t __n) : std::string(__str, __pos, __n) {}
		string(const std::__cxx11::string& __str, std::size_t __pos, std::size_t __n, const std::allocator<char>& __a) : std::string(__str, __pos, __n) {}
		#pragma endregion
	};
	
}

#endif