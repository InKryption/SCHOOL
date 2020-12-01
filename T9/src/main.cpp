#include "main.hpp"

static bool ent = false;
static long counter = 0;


void w1() {
	
	while (true) 
		if (!ent) {
		printf("%i\n", counter);
		counter++;
	} else return;
	
}

int main() {
	
	std::thread worker1(w1);
	printf("%s", get_input().c_str());
	std::this_thread::sleep_for(std::chrono::seconds(5));
	ent = true;
	
	worker1.join();
	
	
	return 0;
}
