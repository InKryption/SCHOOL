#include "User.hpp"

using std::string;

namespace ink {
	
	// Constructors
	
	User::User(const std::string& name, const std::string& password)
		: name(name), password(password), info("")
	{}
	
	User::User(const std::string& user_line_string) {
		
		size_t
		start1 = user_line_string.find_first_of('{') + 1,
		end1 = user_line_string.find_first_of('}', start1 + 1),
		start2 = user_line_string.find_first_of('{', end1 + 1) + 1,
		end2 = user_line_string.find_first_of('}', start2 + 1),
		start3 = user_line_string.find_first_of('{', end2 + 1) + 1,
		end3 = user_line_string.find_first_of('}', start3 + 1);
		
		name = ink::char_decrypt(user_line_string.substr(start1, end1-start1));
		password = ink::char_decrypt(user_line_string.substr(start2, end2-start2));
		info = ink::char_decrypt(user_line_string.substr(start3, end3-start3));
		
	}
	
	User::operator std::__cxx11::string() {
		return
			'{'+	ink::char_encrypt(name)		+'}'
			+
			'{'+	ink::char_encrypt(password)	+'}'
			+
			'{'+	ink::char_encrypt(info)		+'}'
		;
	}
	
	
	// Getters
	
	std::string User::get_name() {
		return name;
	}
	
	
	
}