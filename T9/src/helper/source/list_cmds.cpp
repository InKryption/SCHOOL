#include "../list_cmds.hpp"

using std::string;
using std::vector;
using std::pair;

namespace ink::helper {
	
	string
	list_cmds(vector<pair<string,string>> cmds, string each_begin, string each_end)
	{
		string output;
		for (auto p : cmds)
		output += each_begin + p.first + " - " + p.second + each_end + '\n';
		return output;
	}
	
}
