#include "../lowercase.hpp"

namespace ink::helper {
	
	void lowercase(std::string& str_ref) {
		for (auto& c : str_ref)
		c = std::tolower(c);
	}
	
	std::string lowercase(const std::string& str) {
		lowercase(str);
		return str;
	}
	
	std::string lowercase(std::string&& str) {
		lowercase(str);
		return str;
	}
	
	
}