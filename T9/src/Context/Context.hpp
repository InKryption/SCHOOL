#ifndef __T9_ACTIVITY__CONTEXT_STRUCT__HEADER_FILE_
#define __T9_ACTIVITY__CONTEXT_STRUCT__HEADER_FILE_

#include "common.hpp"

namespace ink {
	
	// ABI struct
	struct PRIMITIVE_PROC {
		
		typedef void(*proc)(PRIMITIVE_PROC*);
		
		// This should return false when returned from an object initialized as a basic process, but
		// as overridden in the Context struct, will return true. This allows us to differentiate the
		// primitive pointer types.
		virtual bool takes_ownership() const = 0;
		
		// Run the operation associated with this object.
		virtual void run() { op(this); }
		
		protected:
		proc op;
		PRIMITIVE_PROC(const proc& function_ptr)	: op( function_ptr ) {}
		PRIMITIVE_PROC(proc&& function_ptr)			: op( std::move(function_ptr) ) {}
	};
	
}

namespace ink {
	
	struct Command :
	public PRIMITIVE_PROC{
		
		bool takes_ownership() const override
		{ return false; }
		
		// Constructors
		
		Command(const proc& function_ptr)
		: PRIMITIVE_PROC( function_ptr ) {}
		
		Command(proc&& function_ptr)
		: PRIMITIVE_PROC( std::move(function_ptr) ) {}
	};
	
	
	struct Context :
	public PRIMITIVE_PROC {
		bool takes_ownership() const override { return true; }
		
		// Constructors
		
		Context(const std::unordered_map<std::string, PRIMITIVE_PROC*>& branches, const PRIMITIVE_PROC::proc& function_ptr);
		Context(std::unordered_map<std::string,PRIMITIVE_PROC*>&& branches, PRIMITIVE_PROC::proc&& function_ptr);
		Context(const std::unordered_map<std::string,PRIMITIVE_PROC*>& branches, PRIMITIVE_PROC::proc&& function_ptr);
		Context(std::unordered_map<std::string,PRIMITIVE_PROC*>&& branches, const PRIMITIVE_PROC::proc& function_ptr);
		
		// Set key for the next basic process/context to take place
		void set_next(std::string next_key);
		
		// Go to next basic process/context
		void next();
		
		// Go to previous context; if exit at the root, close the program
		void exit();
		
		private:
		void init(Context*);
		
		std::	unordered_map <std::string , PRIMITIVE_PROC*> branches;
		std::	string _next;
		Context* prev = NULL;
		
	};
	
}

#endif