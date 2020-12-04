#include "main.hpp"
#pragma region USING
using std::string;
using std::vector;
using std::unordered_map;
using std::vector;
#pragma endregion

void no_such_CMD();
void tm_attempts();

bool 
Help		(unordered_map<string, ink::User*>&	),
List		(unordered_map<string, ink::User*>&	),
Login		(unordered_map<string, ink::User*>&	),
Register	(unordered_map<string, ink::User*>&	);

int main() {
	// Ensure that the LOGS directory exists
	if (!ink::helper::path_exists("LOGS")) system("mkdir LOGS");
	
	// Vector of all registered users
	unordered_map<string, ink::User*>
	UserHash = []{
		unordered_map<string, ink::User*> o;
		
		std::fstream file_stream;
		file_stream.open("LOGS/users.txt");
		
		string line;
		ink::User* usBuffer;
		for (long long c; std::getline(file_stream,line); c += line.length()) {
			usBuffer = new ink::User(line);
			o.insert(std::pair<string, ink::User*>(usBuffer->get_username(), usBuffer));
		}
		
		return o;
	}();
	
	std::unordered_map<string, bool(*)(unordered_map<string, ink::User*>&)> CMD = {
		{"help", Help},
		{"list", List},
		{"login", Login},
		{"register", Register},
		{"exit", [](unordered_map<string, ink::User*>&) {return false;} },
	};
	
	printf("Type 'help' to display available commands.\n");
	
	string str_buff;
	while (true) {
		str_buff = ink::helper::lowercase(ink::helper::trim(ink::helper::get_input()));
		if (str_buff.empty()) continue;
		else if (CMD.find(str_buff) == CMD.end()) {
			no_such_CMD();
			continue;
		}
		if (!CMD[str_buff](UserHash)) break;
	}
	
	printf("Closing session. Logging information. Goodbye. . .\n");
	
	/* CLEAN "users.txt" FILE. OVERWRITE IT USING NEW INFO IN THE "UserHash" OBJECT. */
	
	return 0;
}


bool Help(unordered_map<string, ink::User*>&) {
	printf("Commands:\n\thelp - Display this listing.\n\tlist - Display a list of all registered users.\n\tlogin - Log in to your account.\n\tregister - Register a new account.\n\texit - Close this session.\n");
}

bool List(unordered_map<string, ink::User*>& hash) {
	printf("Registered Users:\n");
	for (auto p : hash)
	printf("\t%s\n", p.first.c_str());
}

bool Login(unordered_map<string, ink::User*>& hash) {
	
	string username, password;
	
	int counter = 0;
	while (true) {
		List(hash);
		
		printf("Username:\n");
		username = ink::helper::lowercase(ink::helper::trim(ink::helper::get_input()));
		
		if (hash.find(username) == hash.end()) counter++;
		else break;
		
		if (counter == 3) {
			tm_attempts();
			return true;
		}
	}
	
	counter = 0;
	while (true) {
		printf("Password:\n");
		password = ink::helper::lowercase(ink::helper::trim(ink::helper::get_input()));
		if (hash[username]->log_in(password)) {
			hash[username]->LOGGED_IN_UI();
			return true; // debugging purposes
		} else counter++;
		
		if (counter == 3) {
			tm_attempts();
			return true;
		}
	}
	
	return true;
}

bool Register(unordered_map<string, ink::User*>& hash) {
	
}

void tm_attempts() {
	printf("Too many failed attempts.\n\n");
}

void no_such_CMD() {
	printf("No such command in current context.\n");
}
