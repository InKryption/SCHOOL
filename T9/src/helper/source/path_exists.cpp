#include "../path_exists.hpp"

namespace ink::helper {
		
	bool path_exists(const std::string& str) {
		struct stat buffer;
		return stat(str.c_str(), &buffer) == 0;
	}
	
}