#ifndef __T9_ACTIVITY__HELPER_FUNCTION__SPLIT_BY_CHAR__HEADER_FILE_
#define __T9_ACTIVITY__HELPER_FUNCTION__SPLIT_BY_CHAR__HEADER_FILE_

#include "common.hpp"
#include "helper/trim.hpp"

namespace ink::helper {
	
	std::vector<std::string> 
	split_char(char c, std::string str);
	
}

#endif