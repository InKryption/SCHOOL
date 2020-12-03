#include "Context.hpp"

using proc = ink::PRIMITIVE_PROC::proc;
using std::string;
using BPP_HASH = std::unordered_map<std::string , ink::PRIMITIVE_PROC* >;

namespace ink {
	
	void Context::
	set_next(std::string next_key)
	{
		this->_next = next_key;
	}
	
	
	
	void Context::
	next()
	{
		this->branches.at(_next)->run();
	}
	
	
	
	void Context::
	exit()
	{
		if (!this->prev) {
			printf("Closing session. Goodbye. . .\n");
			return;
		}
		this->prev->run();
	}
	
	
	
	Context::
	Context(const BPP_HASH& branches, const proc& function_ptr):
		PRIMITIVE_PROC	( function_ptr ),
		branches		( branches )
	{}
	
	
	
	Context::
	Context(BPP_HASH&& branches, proc&& function_ptr):
		PRIMITIVE_PROC	( std::move(function_ptr) ),
		branches		( std::move(branches) )
	{}
	
	
	
	Context::
	Context(const BPP_HASH& branches, proc&& function_ptr):
		PRIMITIVE_PROC	( std::move(function_ptr) ),
		branches		( branches )
	{}
	
	
	
	Context::
	Context(BPP_HASH&& branches, const proc& function_ptr):
		PRIMITIVE_PROC	( function_ptr ),
		branches		( std::move(branches) )
	{}
	
	
	
	void Context::
	init(Context*)
	{
		
	}
}