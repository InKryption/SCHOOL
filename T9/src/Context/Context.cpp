#include "Context.hpp"

typedef ink::PRIMITIVE_PROC::proc proc;
using std::string;
using BPP_HASH = std::unordered_map<std::string , ink::PRIMITIVE_PROC* >;

namespace ink {
	
	void Context::
	set_next(std::string next_key)
	{
		if (this->branches.find(next_key) == branches.end()) {
			printf("Specifed command does not exist in the current context.\n");
			return;
		}
		this->_next = next_key;
		
	}
	
	
	
	void Context::
	next()
	{
		if ( this->branches[_next]->takes_ownership() )
		static_cast<Context*>(this->branches[_next])->init(this);
		this->branches[_next]->run();
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
	Context(const BPP_HASH& branches, proc function_ptr):
		PRIMITIVE_PROC	( function_ptr ),
		branches		( branches )
	{}
	
	
	
	Context::
	Context(BPP_HASH&& branches, proc function_ptr):
		PRIMITIVE_PROC	( std::move(function_ptr) ),
		branches		( std::move(branches) )
	{}
	
	
	
	void Context::
	init(Context*)
	{
		
	}
}