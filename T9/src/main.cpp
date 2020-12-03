#include "main.hpp"
#pragma region USING
using std::string;
using std::vector;
using std::unordered_map;
using std::vector;
#pragma endregion

typedef void(*FUNC)(void*);
namespace ink::UI { void init(void*); }

struct state {
	string HELP_STR;
	
	FUNC current = ink::UI::init;
	
	bool running = true;
	
	std::string prompt_input()
	{ return ink::helper::lowercase(ink::helper::trim(ink::helper::get_line())); }
	
};

int main() {
	state STATE;
	
	system("mkdir LOGS"); // Ensure that the LOGS directory exists
	
	while (STATE.running)
	STATE.current( (void*)(&STATE) );
	
	return 0;
}



namespace ink::UI {
	
	namespace MAIN {
		
		void exit(void* _STATE) {
			static_cast<state*>(_STATE)->running = false;
			printf("\nLogging out. Goodbye...\n\n");
		}
		
		void help(void* _STATE) {
			printf(static_cast<state*>(_STATE)->HELP_STR.c_str());
		}
		
		void assess(void* _STATE) {
			state* STATE = static_cast<state*>(_STATE);
			std::string buff = STATE->prompt_input();
			if (buff == "help") help(_STATE); else 
			if (buff == "exit") exit(_STATE);
		}
		
	}
	#pragma region FORWARD DECLARATIONS
	
	namespace surface {
		void list(void*);
		void init_register(void*); // Brings us into another branch
		void init_login(void*); // Also brings us into another branch
	}
	
	#pragma endregion

	void init(void* _STATE) {
		state* STATE = static_cast<state*>(_STATE);
		printf("Type 'help' to see commands.\n\n");
		
		
		
		STATE->current = MAIN::assess;
	}
	
	void surface::list(void* _STATE) {
		printf("ADD LIST,USERS FUNCTIONALITY.\n");
	}
	
	
	
	void surface::init_login(void* _STATE) {
		state* STATE = static_cast<state*>(_STATE);
		printf("ADD LOGIN,USERS FUNCTIONALITY.\n");
		STATE->current = MAIN::assess;
	}
	
	void surface::init_register(void* _STATE) {
		state* STATE = static_cast<state*>(_STATE);
		printf("ADD REGISTER,USERS FUNCTIONALITY.\n");
		STATE->current = MAIN::assess;
	}
	
}
