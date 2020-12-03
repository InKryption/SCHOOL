#include "main.hpp"
#pragma region USING
using std::string;
using std::vector;
using std::unordered_map;
using std::vector;
#pragma endregion

using ink::PRIMITIVE_PROC;
using ink::Command;
using ink::Context;

// Initialize a pointer to context as such to be able to declare everything else underneath main.

int main() {
	// Ensure that the LOGS directory exists
	if (!ink::helper::path_exists("LOGS")) system("mkdir LOGS");
	
	Context MAIN_MENU, LOGIN, REGISTER;
	
	MAIN_MENU = Context(
		{},
		[](PRIMITIVE_PROC* THS) {
			using namespace ink::helper;
			
			auto ths = static_cast<Context*>(THS);
			
			std::string formatted_input =
			lowercase(trim(get_line()));
			
			ths->set_next(formatted_input);
			
			ths->next();
		}
	);
	
	MAIN_MENU.run();
	
	printf("Closing session. Goodbye. . .\n");
	
	return 0;
}
