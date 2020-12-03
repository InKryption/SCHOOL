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

int main() {
	system("mkdir LOGS"); // Ensure that the LOGS directory exists
	
	Command exit(
		//{},
		[](PRIMITIVE_PROC* ths) {
			
			printf("%i\n", ths->takes_ownership());
			
		}
	);
	
	exit.run();
	
	
	return 0;
}


