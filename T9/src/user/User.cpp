#include "User.hpp"

using std::string;

namespace ink {
	
	User::User(const string& USER_LINE_STRING)  {
		
		size_t START1 = USER_LINE_STRING.find_first_of("{") + 1;
		size_t END1 = USER_LINE_STRING.find_first_of('}', START1);
		
		size_t START2 = USER_LINE_STRING.find_first_of('{', END1) + 1;
		size_t END2 = USER_LINE_STRING.find_first_of('}', START2);
		
		size_t START3 = USER_LINE_STRING.find_first_of('{', END2) + 1;
		size_t END3 = USER_LINE_STRING.find_first_of('}', START3);
		
		string
		_name, _password, _info;
		
		for (auto str : ink::helper::split_char(' ', USER_LINE_STRING.substr(START1, END1-START1)))
		_name.push_back((char)std::stoi(str));
		
		for (auto str : ink::helper::split_char(' ', USER_LINE_STRING.substr(START2, END2-START2)))
		_password.push_back((char)std::stoi(str));
		
		for (auto str : ink::helper::split_char(' ', USER_LINE_STRING.substr(START3, END3-START3)))
		_info.push_back((char)std::stoi(str));
		
		
		name = _name;
		password = _password;
		info = _info;
		
	}
	
	string User::DATA()  {
		std::string _name, _password, _info;
		
		for (auto c : name)
		_name.append( std::to_string((int)(c)) + " " );
		_name.pop_back();
		
		for (auto c : password)
		_password.append( std::to_string((int)(c)) + " " );
		_password.pop_back();
		
		for (auto c : info)
		_info.append( std::to_string((int)(c)) + " " );
		_info.pop_back();
		
		return '{' + _name + '}' + '{' + _password + '}' + '{' + _info + '}';
	}
	
	
	
}