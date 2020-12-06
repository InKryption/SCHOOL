#include "main.hpp"

using ink::string;
using std::vector;

int main() {
	// Ensure that the LOGS directory exists
	if (!ink::helper::path_exists("LOGS")) system("mkdir LOGS");
	
	string f = "d";
	string g = "ie";
	
	auto n = ink::char_encrypt(f);
	
	printf("%s", n.c_str());
	
	return 0;
}


