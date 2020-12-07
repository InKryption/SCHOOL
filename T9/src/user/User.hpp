#ifndef __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_

#include "common.hpp"
#include "helper/get_input.hpp"
#include "helper/yes_no_prompt.hpp"

#include "string/string.hpp"
#include "char_encryption/char_encryption.hpp"

namespace ink {
	
	struct UserHash {
		
		// User - password - info
		class User {
			
			friend struct UserHash;
			friend class std::pair<std::string, User>;
			
			User(UserHash* container_ref, string username, string password, string info):
				name(username),
				container_ref(container_ref),
				password(password),
				info( (ink::string(info).trim_copy() == "\\\\#") ? "" : info )
			{}
			
			UserHash* container_ref;
			string name;
			string info;
			string password;
			
			bool help() {
				printf("Commands:\n\
						\r\thelp - Display this listing.\n\
						\r\texit - Log out of this account.\n\
						\r\tread - Read info.\n\
						\r\tedit - Edit info.\n\
						\r\tclear - (CAUTION) Erase all info logged to this account.\n\
						\r\tunregister - (CAUTION) Delete this account.\n"
				);
				return true;
			}
			
			bool exit() {
				printf("-= LOGGED OUT =-\n");
				return false;
			}
			
			bool read() {
				printf(
					"\n\n\
					\r<==============================^==============================>\n\
					\r%s\n\
					\r<==============================^==============================>\n\n",
					info.c_str()
				);
				return true;
			}
			
			bool edit() {
				
				printf("Press ENTER twice to end editing.\n\n");
				
				int empty_count = 0;
				string input;
				while (empty_count < 2) {
					info.push_back('\n');
					input = ink::helper::get_input();
					if (input.empty()) empty_count++; else empty_count = 0;
					info.append(input);
				}
				info.pop_back();
				
				printf("-= END OF EDIT =-\n");
				return true;
			}
			
			bool clear() {
				bool erase_all = true;
				if (info.find_first_of('\n') != info.find_last_of('\n'))
				erase_all = 
				helper::Y_N_Prompt("WARNING: You are about to erase all logged information from this account. Are you sure you want to do this? (Y/N)\n");
				
				if (erase_all) this->info.clear();
				return true;
			}
			
			bool unregister() {
				bool unregister = ink::helper::Y_N_Prompt
				("Are you SURE you want to UNREGISTER this account? (Y/N)\n");
				
				if (unregister) {
					this->container_ref->__inner.erase(name);
					return false;
				} else return true;
			}
			
			std::unordered_map<std::string, bool(User::*)()> CMD{
				{"help", help},
				{"exit", exit},
				{"read", read},
				{"edit", edit},
				{"clear", clear},
				{"unregister", unregister}
			};
			
			public:
			User() {}
			std::string as_data() {
				std::string output;
				
				if (info.empty()) info = "\\\\#";
				
				output.append('{' + ink::char_encrypt(name) + '}');
				output.append('{' + ink::char_encrypt(password) + '}');
				output.append('{' + ink::char_encrypt(info) + '}');
				
				return output;
			}
			
		};
		friend class User;
		
		// Constructor
		UserHash():
			__inner({})
		{}
		
		// Return false on failure to import user, true otherwise
		bool import_user(const string& user_information_line);
		
		// Return false on failure to register, true otherwise
		bool register_user();
		
		// Return false on failure to log in, true otherwise.
		bool log_in();
		
		void list_users() {
			printf("Users:\n");
			for (auto usr : __inner)
			printf("\t%s\n", usr.first.c_str());
		}
		
		std::string DATA() {
			std::string output;
			
			for (auto p : __inner) {
				output.append(p.second.as_data());
				output.push_back('\n');
			}
			
			return output;
		}
		
		private:
		std::unordered_map<std::string, User> __inner{};
	};
	
}

#endif