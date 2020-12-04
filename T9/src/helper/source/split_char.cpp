#include "../split_char.hpp"

using std::string;
using std::vector;

namespace ink::helper {
		
	vector<string> split_char(char chr, string str) {
		vector<string> output;
		size_t 
		begin = 0,
		end = 0;
		for (auto c : str) {
			if (chr == c) {
				output.push_back(
					str.substr(begin, end-begin)
				);
				begin = end + 1;
			}
			end++;
		}
		output.push_back(
			str.substr(begin, end-begin)
		);
		
		return output;
	}
	
}