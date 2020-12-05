#include "char_encryption.hpp"

namespace ink {
	
	// Very basic, not really useful encryption method, that transforms each character in a string into its numerical value.
	
	std::string char_encrypt(const std::string& str) {
		std::string buff;
		for (auto c : str)
		buff.append( std::to_string(int(c)) + ' ' );
		buff.pop_back();
		return buff;
	}
	
	std::string char_decrypt(const std::string& str) {
		std::string buff;
		for (auto c_val : helper::split_char(' ', str))
		buff.push_back( char(std::stoi(c_val)) );
		return buff;
	}
	
}