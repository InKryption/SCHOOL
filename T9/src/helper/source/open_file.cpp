#include "../open_file.hpp"

namespace ink::helper {
	
	FILE* open_file(std::string FILENAME) {
		FILE* file;
		try			{ file = fopen(FILENAME.c_str(), "r+"); } // try to open file for I/O
		catch(...)	{ file = fopen(FILENAME.c_str(), "w+"); } // if file doesn't exist, create it, and open it for I/O
		return file;
	}
	
}
