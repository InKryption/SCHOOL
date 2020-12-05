#ifndef __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__USER_STRUCT__HEADER_FILE_

#include "common.hpp"
#include "helper/split_char.hpp"

namespace ink {
	
	// User - password - info
	struct User {
		
		void LOGGED_IN_UI();
		
		bool log_in(const std::string& password)
		{ return logged_in = this->password == password; }
		
		std::string get_username() const
		{ return this->name; }
		
		User() {};
		User(const std::string& USER_LINE_STRING);
		std::string DATA();
		
		private:
		
		std::string name;
		std::string info;
		std::string password;
		bool logged_in = false;
		
	};
}

#endif