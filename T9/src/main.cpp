#include "main.hpp"

using ink::string;
using std::vector;

const string USER_FILE_PATH = "LOGS/users.txt";

bool 
help(ink::UserHash&),
exit(ink::UserHash&),
list(ink::UserHash&),
login(ink::UserHash&),
Register(ink::UserHash&);

int main() {
	// Ensure that the LOGS directory exists
	if (!ink::helper::path_exists("LOGS")) system("mkdir LOGS");
	
	ink::UserHash uHash;
	
	// String of the contents of the file at USER_FILE_PATH
	string UFStr = []() {
		string o;
		std::fstream fs;
		fs.open(USER_FILE_PATH);
		while (std::getline(fs, o, char(0)));
		fs.close();
		return o;
	}();
	
	for (auto str : ink::helper::split_char('\n', UFStr))
	uHash.import_user(str);
	
	const std::unordered_map<std::string, bool(*)(ink::UserHash&)> CMD = {
		{ "help", help },
		{ "exit", exit },
		{ "list", list },
		{ "login", login },
		{ "register", Register },
	};
	
	string input_buff;
	bool running = true;
	printf("Type 'help' to see commands.\n\n\n");
	while (running) {
		input_buff = ink::helper::get_input();
		input_buff.lowercase();
		input_buff.trim();
		
		if (CMD.find(input_buff) != CMD.end() )
		running = CMD.at(input_buff)(uHash);
		else printf("No such command exists in the current context.\n");
		
	}
	
	return 0;
}

bool help(ink::UserHash& uHash) {
	
	printf(
		"Commands:\n\
		\r\thelp - Display this listing.\n\
		\r\texit - Close this session.\n\
		\r\tlist - List all registered users.\n\
		\r\tlogin - Log in to your account.\n\
		\r\tregister - Register a new account.\n"
	);
	
}

bool exit(ink::UserHash& uHash) {
	printf("Closing session. Goodbye. . .\n");
	return false;
}

bool list(ink::UserHash& uHash) {
	uHash.list_users();
	return true;
}

bool login(ink::UserHash& uHash) {
	
	
	
	return true;
}

bool Register(ink::UserHash& uHash) {
	
	
	
	return true;
}
