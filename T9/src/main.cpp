#include "main.hpp"

using std::string;
using std::unordered_map;

void f() {printf("f");}

int main() {
	
	std::thread m(f);
	std::thread m2(f);
	
	printf("%s", get_input().c_str());
	
	m.join();
	m2.join();
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	return 0;
}
