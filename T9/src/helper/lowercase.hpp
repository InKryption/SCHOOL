#ifndef __T9_ACTIVITY__TO_LOWER_STR_FUNCTION__HEADER_FILE_
#define __T9_ACTIVITY__TO_LOWER_STR_FUNCTION__HEADER_FILE_

#include "common.hpp"

namespace ink::helper {
	
	void lowercase(std::string& str_ref);
	std::string lowercase(const std::string& str);
	std::string lowercase(std::string&& str);
	
}

#endif