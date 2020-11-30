//main entry point source file
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#define loop while(true)

using std::string;

const string EXIT_CMD = "fin";

bool get_input(string& buffer);

//procesa el input, y llena "output" con el resultado. Devuelve falso si todo va bien, y verdadero si algo va mal. 
bool process_numerical(string& buffer, size_t& output);

//sirve para descartar whitespace, facilitando el procesamiento de cualquier input
static inline void trim(std::string& str);

int main() {
	string buffer;
	size_t count, cycles;
	
	loop {
		printf("Introduzca hasta que numero deseas contar: ");
		if ( get_input(buffer) ) break;
		if (process_numerical(buffer, count)) continue;
		
		printf("\n");
		
		printf("Introduzca cuantas veces deseas contar hasta '%llu': ", count);
		if ( get_input(buffer) ) break;
		if (process_numerical(buffer, cycles)) continue;
		
		for(int i = 0; i < cycles; i++) {
			printf("(%llu)\n", i);
			for(int j = 1; j <= count; j++) printf("\t%llu\n", j);
		}
		
		printf("(Introduzca 'fin' para finalizar la programa.)\n");
	}
	
	return 0;
}

bool get_input(string& buffer) {
	std::cin >> buffer; trim(buffer);
	return (buffer == EXIT_CMD);
}

bool process_numerical(string& buffer, size_t& output) {
	try { output = std::stoull(buffer); }
	catch (...) {
		printf("\nLo introducido es demasiado grande, o no es un numero.\n");
		return true;
	}
	return false;
}

static inline void trim(string& s) {
    s.erase(
		s.begin(),
		std::find_if(
			s.begin(),
			s.end(),
			[](unsigned char ch) {
				return !std::isspace(ch);
			}
		)
	);
	s.erase(
		std::find_if(
			s.rbegin(), 
			s.rend(), 
			[](unsigned char ch) {
				return !std::isspace(ch);
				}
		).base(), 
		s.end()
	);
}
