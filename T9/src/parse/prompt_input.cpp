#include "prompt_input.hpp"

using std::string;

string ink::prompt_input() {
	string output;
	std::getline(std::cin, output, '\n');
	return output;
}
