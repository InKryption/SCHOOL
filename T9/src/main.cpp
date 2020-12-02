#include "main.hpp"

using std::string;
using std::unordered_map;



int main() {
	
	std::string raw_buff;
	
	while (true) {
		raw_buff = ink::prompt_input();
		if (raw_buff == "__exit__") break; // Temp exit portal
		
		
		
	}
	
	return 0;
}
