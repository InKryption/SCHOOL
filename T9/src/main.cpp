#include "main.hpp"

using std::string;
using std::vector;
using std::unordered_map;



int main() {
	
	unordered_map<string, ink::CMD> cmd;
	cmd.emplace(
		ink::CMD("list", 
			[]() -> ink::FCallback {
				
				printf("help - See this menu.\n");
				
				return ink::FCallback::IGNORE;
			}
		)
	);
	
	string raw_buff;
	vector<string> formatted_buff;
	
	while (true) {
		
		raw_buff = ink::prompt_input();
		if (raw_buff == "__exit__") break; // Temp exit portal
		
		formatted_buff = ink::split_tokens(raw_buff);
		
		// Ensure that there are no more than two args.
		if (formatted_buff.size() > 2 || formatted_buff.size() == 0) {
			printf("Invalid number of tokens. Use 'help' to view valid commands.");
			continue;
		}
		
		ink::FCallback fcallback = cmd[formatted_buff[0]](formatted_buff[1]);
		
		if ( fcallback == ink::FCallback::BREAK ) break;
		
	}
	
	return 0;
}
