#include "split_tokens.hpp"

using std::vector;
using std::string;

vector<string> ink::split_tokens(string input) {
	vector<string> output;
	
	bool is_space;
	for (size_t s = 0, e = 0; e <= input.length(); e++) {
		if (e - s > 0)
		if (isspace(input[e]) || e == input.length()) {
			output.push_back(input.substr(s, e - s));
			s = e + 1;
		}
	}
	return output;
}
