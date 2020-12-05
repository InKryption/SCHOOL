#ifndef __T9_ACTIVITY__CHAR_ENCRYPTION__HEADER_FILE_
#define __T9_ACTIVITY__CHAR_ENCRYPTION__HEADER_FILE_

#include "common.hpp"
#include "helper/split_char.hpp"

namespace ink {
	std::string char_encrypt(const std::string& str);
	std::string char_decrypt(const std::string& str);
}

#endif