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
	
	bool UserHash::register_user(const string& name, const string& password) {
		if ( __inner.find(name) != __inner.end() ) return false;
		__inner.emplace(name, User(this, name, password, ""));
		return true;
	}
	
	bool UserHash::log_in(const string& user) {
		if ( __inner.find(user) == __inner.end() ) return false;
		
		auto& USER = __inner[user];
		bool logged_in = true;
		
		string input_buff;
		while (logged_in) {
			input_buff = string(ink::helper::get_input());
			input_buff.lowercase();
			logged_in = (USER.*USER.CMD[input_buff])();
		}
		
		return true;
	}
	
}