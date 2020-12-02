#include "main.hpp"

using std::string;
using std::vector;
using std::pair;

int main() {
	
	string input_buff;
	ink::cmd_arg parsed_cmd;
	
	while (true) {
		input_buff = ink::trim(ink::prompt_input()); // Prompt input, and trim any esoteric whitespace
		for (auto c : input_buff) c = std::tolower(c); // Make input possess all lowercase, to make the process of parsing it easier.
		
		if (input_buff == "_exit") break; // Temporary exit portal #_DEBUG
		
		parsed_cmd = ink::split_tokens(input_buff);
		
		
		
	}
	
	return 0;
}
