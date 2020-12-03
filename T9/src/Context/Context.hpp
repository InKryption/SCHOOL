#ifndef __T9_ACTIVITY__CONTEXT_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__CONTEXT_STRUCT__HEADER_FILE_

#include "common.hpp"

namespace ink {
	
	class Context {
		
		std::unordered_map
		<std::string,Context*> branches;
		
		std::string _next;
		
		Context* prev = NULL;
		
		void(*op)(Context*);
		
		bool takes_ownership;
		
		void init(Context*);
		
		public:
		Context(bool takes_ownership, decltype(*op), std::unordered_map<std::string,Context*> branches = {});
		
		void next() {
			if ( branches.find(_next) != branches.end() ) {
				
				if (branches.at(_next)->takes_ownership) branches.at(_next)->init();
				
			}
				
			
			
		}
		
	};
	
}

#endif