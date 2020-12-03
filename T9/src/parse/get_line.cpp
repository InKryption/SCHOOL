#include "prompt_input.hpp"

using std::string;

string ink::get_line() {
	string output;
	std::getline(std::cin, output, '\n');
	return output;
}
