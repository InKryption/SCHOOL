#include "split_tokens.hpp"

using std::pair;
using std::string;

pair<string, string> ink::split_tokens(string input) {
	pair<string, string> output;
	
	output.first = input.substr(0, input.find_first_of(" \n\t"));
	output.second = input.substr(input.find_first_of(" \n\t"));
	
	return output;
}
