#include "get_input.hpp"

using std::string;

string get_input() {
	string output;
	std::getline(std::cin, output, '\n');
	return output;
}
