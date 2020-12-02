#include "cmd.hpp"

ink::CMD::
CMD(std::string name, FCallback(*func_ptr)())
: name(name), fpointer(func_ptr) {}

ink::FCallback ink::CMD::
operator()() {
	return fpointer();
}

ink::CMD::
operator std::pair<const std::string&, FCallback(*)()>() {
	return { name, fpointer };
}
