#ifndef __T9_ACTIVITY__HELPER_FUNCTION_TRIM__HEADER_FILE_
#define __T9_ACTIVITY__HELPER_FUNCTION_TRIM__HEADER_FILE_

#include "common.hpp"

namespace ink::helper {
	
	void trim(std::string& str_ref);
	std::string trim(const std::string& str);
	std::string trim(std::string&& str);
	
}

#endif