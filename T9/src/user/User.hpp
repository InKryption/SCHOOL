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
				info(info)
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
						\r\tDELETE - (CAUTION) Delete this account.\n"
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
				
				int empty_count = 0;
				string input;
				while (empty_count < 2) {
					info.push_back('\n');
					input = ink::helper::get_input();
					if (input.empty()) empty_count++; else empty_count = 0;
					info.append(input);
				}
				info.pop_back();
				
				return true;
			}
			
			bool clear() {
				bool erase_all = helper::Y_N_Prompt
				("WARNING: You are about to erase all logged information from this account. Are you sure you want to do this? (Y/N)\n");
				if (erase_all) this->info.clear();
				return true;
			}
			
			bool UNREGISTER() {
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
				{"UNREGISTER", UNREGISTER}
			};
			
			public:
			User() {}
		};
		friend class User;
		
		// Constructor
		UserHash():
			__inner({})
		{}
		
		// Return false on failure to import user, true otherwise
		bool import_user(const string& user_information_line);
		
		// Return false on failure to register user, true otherwise
		bool register_user(const string& name, const string& password);
		
		// Log into specified account
		bool log_in(const string& user);
		
		void list_users() {
			printf("Users:\n");
			for (auto usr : __inner)
			printf("\t%s\n", usr.first.c_str());
		}
		
		private:
		std::unordered_map<std::string, User> __inner{};
	};
	
}

#endif