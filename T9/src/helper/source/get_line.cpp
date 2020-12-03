#include "../get_line.hpp"

using std::string;

namespace ink::helper {
	
	string get_line() {
		string output;
		std::getline(std::cin, output, '\n');
		return output;
	}
	
}