#ifndef __T9_ACTIVITY__CMD_INTERPRETATION__HEADER_FILE_
#define __T9_ACTIVITY__CMD_INTERPRETATION__HEADER_FILE_

#include "common.hpp"

namespace ink {
	
	enum class FCallback { IGNORE, RETURN_0, BREAK, CONTINUE }; // Enum to tell the calling function what to do.
	
	typedef FCallback(*CMD)(void*); // Function pointer that returns an ::FCallback enum; it takes a generic void pointer, as such to operate with anything
	
	typedef std::pair<std::string, std::string> cmd_arg;
	
	typedef std::unordered_map<std::string, CMD> cmdContext; // Hash of CMDs
	
}

#endif