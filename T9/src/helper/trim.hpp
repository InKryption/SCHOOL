#ifndef __T9_ACTIVITY__TRIM_FUNCTION__HEADER_FILE_
#define __T9_ACTIVITY__TRIM_FUNCTION__HEADER_FILE_

#include "common.hpp"

namespace ink {
	
	void trim(std::string&);
	std::string trim(const std::string&);
	std::string trim(std::string&&);
	
}

#endif