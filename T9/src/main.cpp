#include "main.hpp"

using ink::string;
using std::vector;

int main() {
	// Ensure that the LOGS directory exists
	if (!ink::helper::path_exists("LOGS")) system("mkdir LOGS");
	
	ink::string test = "	  \n tE  st 	\n";
	
	return 0;
}


