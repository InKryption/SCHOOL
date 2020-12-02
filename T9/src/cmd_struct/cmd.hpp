#ifndef __T9_ACTIVITY__CMD_STRUCT_HEADER_FILE_
#define __T9_ACTIVITY__CMD_STRUCT_HEADER_FILE_

#include "common.hpp"

namespace ink {
	
	enum class FCallback { RETURN_0 , CONTINUE , BREAK , IGNORE };
	
	struct CMD {
		CMD( std::string name , FCallback(*func_ptr)() );
		operator std::pair< const std::string& , FCallback(*)() >();
		FCallback operator()();
		
		private:
		std::string name;
		FCallback(*fpointer)();
	};
	
}

#endif