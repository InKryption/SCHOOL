#include "../trim.hpp"

namespace ink::helper {
	
	void trim(std::string& str_ref) {
		size_t first_nospace = str_ref.find_first_not_of(" \n\t");
		size_t last_nospace = str_ref.find_last_not_of(" \n\t");
		
		if (str_ref.empty() || first_nospace == std::string::npos)
		{ str_ref = ""; return; }
		
		str_ref = str_ref.substr(first_nospace, last_nospace - first_nospace + 1);
	}

	std::string trim(const std::string& str) {
		trim(str);
		return str;
	}

	std::string trim(std::string&& str) {
		trim(str);
		return str;
	}
	
}
