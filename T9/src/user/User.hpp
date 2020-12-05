#ifndef __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_

#include "common.hpp"
#include "char_encryption/char_encryption.hpp"
#include "hashtable.h"

namespace ink {
	
	// User - password - info
	struct User {
		
		// Register a new user
		User(const std::string& name, const std::string& password);
		
		// Read user info from a string, comprised of a curly bracket seperated list of char encrypted strings
		User(const std::string& char_encrypted_string);
		
		// Implicit conversion from user into raw string of information that can be parsed back into a user later
		operator std::string();
		
		// Get this user's name
		std::string get_name();
		
		private:
		std::string name;
		std::string info;
		std::string password;
		
		// Commands for while being logged in
		
		
	};
	
	struct UserHash 
	: public std::unordered_map<std::string, int> {
		class User {};
	};
	
}

#endif