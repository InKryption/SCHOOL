#ifndef __T9_ACTIVITY__HELPER_FUNCTION_LIST_CMDS__HEADER_FILE_
#define __T9_ACTIVITY__HELPER_FUNCTION_LIST_CMDS__HEADER_FILE_

#include "common.hpp"

namespace ink::helper {
	std::string 
	list_cmds(
		std::vector<
		std::pair <std::string , std::string>
		> cmds,
		std::string each_begin = "\t",
		std::string each_end = ""
	);
}

#endif