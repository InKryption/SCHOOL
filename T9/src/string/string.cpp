#include "string.hpp"

namespace ink {
	
	#pragma region Trim
	void string::trim_left() { this->erase(0, this->find_first_not_of(" \t\n\v\f\r")); }
	void string::trim_right() { this->erase(this->find_last_not_of(" \t\n\v\f\r") + 1); }
	void string::trim() { trim_left(); trim_right(); }
	
	string string::trim_copy_left() const {
		string out = *this;
		out.trim_left();
		return out;
	}
	string string::trim_copy_right() const {
		string out = *this;
		out.trim_right();
		return out;
	}
	string string::trim_copy() const {
		string out = *this;
		out.trim();
		return out;
	}
	#pragma endregion
	
	#pragma region Case Change
	void string::lowercase() {
		for (auto& c : *this) c = std::tolower(c);
	}
	void string::uppercase() {
		for (auto& c : *this) c = std::toupper(c);
	}
	
	string string::lowercase_copy() const {
		string out = *this;
		out.lowercase();
		return out;
	}
	string string::uppercase_copy() const {
		string out = *this;
		out.uppercase();
		return out;
	}
	#pragma endregion
	
	
	
	// string string::as_lowercase() const {
	// 	string buff;
	// 	for (auto c : *this) buff.push_back(std::tolower(c));
	// 	return buff;
	// }
	
}