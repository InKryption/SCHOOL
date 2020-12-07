#include "../yes_no_prompt.hpp"

namespace ink::helper {
	
	bool Y_N_Prompt(std::string message) {
		printf("%s", message.c_str());
		char y_n;
		while (true) {
			y_n = ink::helper::get_input()[0];
			y_n = tolower(y_n);
			if (y_n == 'y' || y_n == 'n') break;
		}
		if (y_n == 'y') return true;
	}
	
}