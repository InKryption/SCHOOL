#include "User.hpp"

namespace ink {
	
	bool UserHash::import_user(const string& UIL) {
		size_t
			start1 = UIL.find_first_of('{') + 1,
			end1 = UIL.find_first_of('}', start1 + 1),
			start2 = UIL.find_first_of('{', end1 + 1) + 1,
			end2 = UIL.find_first_of('}', start2 + 1),
			start3 = UIL.find_first_of('{', end2 + 1) + 1,
			end3 = UIL.find_first_of('}', start3 + 1)
		;
		
		string
			name,
			passwd,
			info
		;
		
		try {
			name = char_decrypt(UIL.substr(start1, end1-start1));
			passwd = char_decrypt(UIL.substr(start2, end2-start2));
			info = char_decrypt(UIL.substr(start3, end3-start3));
		} catch(...) { return false; }
		
		if ( __inner.find(name) != __inner.end() ) return false;
		
		__inner.emplace(std::pair<std::string, User>(std::string(name), User(this, name, passwd, info)));
		return true;
	}
	
	bool UserHash::register_user() {
		
		string
			name_buff,
			passwd_buff
		;
		short fail_count = 0;
		while (true) {
			printf("Username:\n");
			name_buff = ink::helper::get_input();
			
			if (__inner.find(name_buff) != __inner.end()) {
				printf("Another user already has that name. Please choose another one.\n\n");
				if (fail_count++ == 3) return false;
			}
			else break;
		}
		
		fail_count = 0;
		while (true) {
			printf("Password:\n");
			passwd_buff = ink::helper::get_input();
			if (system("cls") != 0) system("clear");
			printf("Confirm password:\n");
			if ( passwd_buff != ink::helper::get_input() || passwd_buff.empty() ) {
				printf("Passwords do not match.\n\n");
				if (fail_count++ == 3) return false;
			}
			else break;
		}
		
		__inner.emplace(name_buff, User(this, name_buff, passwd_buff, ""));
		return true;
	}
	
	bool UserHash::log_in() {
		list_users(); printf("\n");
		
		string
			username_buff,
			passwd_buff
		;
		
		short fail_count = 0;
		while (true) {
			printf("Username:\n");
			username_buff = ink::helper::get_input();
			
			if (__inner.find(username_buff) == __inner.end()) {
				printf("No user with specified name. Check above listing.\n");
				if (++fail_count == 3) return false;
			} else break;
		}
		
		auto& USER = __inner[username_buff];
		
		fail_count = 0;
		while (true) {
			printf("Password:\n");
			passwd_buff = ink::helper::get_input();
			if (USER.password != passwd_buff) {
				printf("Incorrect password.\n");
				if (++fail_count == 3) return false;
			} else break;
		}
		
		printf("Type 'help' to see commands.\n\n\n");
		
		string input_buff;
		bool logged_in = true;
		while (logged_in) {
			input_buff = string(ink::helper::get_input());
			input_buff.lowercase();
			
			if ( input_buff.empty() ) continue;
			else if ( USER.CMD.find(input_buff) == USER.CMD.end() ) {
				printf("No such command exists in the current context.\n");
				continue;
			}
			
			logged_in = (USER.*USER.CMD[input_buff])();
		}
		
		return true;
	}
	
}
