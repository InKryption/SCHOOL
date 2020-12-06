#ifndef __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_

#include "common.hpp"
#include "string/string.hpp"
#include "char_encryption/char_encryption.hpp"

namespace ink {
	
	struct UserHash {
		
		// User - password - info
		struct User {
			
			friend struct UserHash;
			
			User() {}
			
			// Register a new user
			User(const string& name, const string& password);
			
			// Read user info from a string, comprised of a curly bracket seperated list of char encrypted strings
			User(const string& char_encrypted_string);
			
			// Implicit conversion from user into raw string of information that can be parsed back into a user later
			operator string();
			
			// Get this user's name
			string get_name();
			
			private:
			string name;
			string info;
			string password;
			
			// Commands for while being logged in
			
			
		};
		
		UserHash() {}
		
		// Return true on success to register new user, false on failure to do so.
		bool register_user(string username, string password);
		
		// Parse user from a string, likely having been previously registered, and stored in a file, to be imported into the program via this process.
		void parse_user(const string& str);
		
		private:
		std::unordered_map<std::string, User> __inner;
	};
	
}

#endif