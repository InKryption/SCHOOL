#include "User.hpp"

namespace ink {
	
	#pragma region User
	
	#pragma region Constructors
	
	UserHash::User::User(const string& name, const string& password)
		: name(name), password(password), info("")
	{}
	
	UserHash::User::User(const string& user_line_string) {
		
		size_t
		start1 = user_line_string.find_first_of('{') + 1,
		end1 = user_line_string.find_first_of('}', start1 + 1),
		start2 = user_line_string.find_first_of('{', end1 + 1) + 1,
		end2 = user_line_string.find_first_of('}', start2 + 1),
		start3 = user_line_string.find_first_of('{', end2 + 1) + 1,
		end3 = user_line_string.find_first_of('}', start3 + 1);
		
		name = char_decrypt(user_line_string.substr(start1, end1-start1));
		password = char_decrypt(user_line_string.substr(start2, end2-start2));
		info = char_decrypt(user_line_string.substr(start3, end3-start3));
		
	}
	
	UserHash::User::operator string() {
		return
			'{'+	char_encrypt(name)		+'}'
			+
			'{'+	char_encrypt(password)	+'}'
			+
			'{'+	char_encrypt(info)		+'}'
		;
	}
	
	#pragma endregion
	
	// Getters
	
	string UserHash::User::get_name() { return name; }
	
	#pragma endregion
	
	#pragma region UserHash
	
	bool UserHash::register_user(string username, string password) {
		bool flag;
		if (flag = (__inner.find(username) != __inner.end()))
		__inner.insert(std::pair<std::string, User>(username, User(username, password)));
		
		return flag;
	}
	
	void UserHash::parse_user(const string& str) {
		auto importedUser = User(str);
		__inner.insert(std::pair<std::string, User>(importedUser.get_name(), importedUser));
	}
	
	
	
	#pragma endregion
	
}