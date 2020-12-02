#include "trim.hpp"

void ink::trim(std::string& ref) {
	size_t first_nospace = ref.find_first_not_of(" \n\t");
	size_t last_nospace = ref.find_last_not_of(" \n\t");
	try {
		ref = ref.substr( first_nospace , last_nospace - first_nospace + 1 );
	} catch (...) {
		// Any errors thrown, just make the ref into a blank string, since it's likely due to being a blank string in the first place.
		// Or some other characters that are unsupported, so this empty str can generally be used as an indication of generic mal-use on the
		// part of the user, whether that be pressing enter without typing anything, or what have you.
		ref = "";
	}
}

std::string ink::trim(const std::string& cref) {
	ink::trim(cref);
	return cref;
}

std::string ink::trim(std::string&& rval) {
	ink::trim(rval);
	return rval;
}
