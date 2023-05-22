#ifndef CHESSLIB
#define CHESSLIB

#include "chman.h"

class King : virtual public Figure {
	public:
		King() {};
		King(char * p) : Figure(p) {};
		char isa() {return 'K';};
		int attack(char * p);
};

class Rook : virtual public Figure {
	public:
		Rook() {};
		Rook(char * p) : Figure(p) {};
		char isa() {return 'R';};
		int attack(char * p);
};

class Lord : public King, public Rook {
	public:
		Lord(char * p) : Figure(p) {};
		char isa() {return 'L';};
		int attack(char*);
};


#endif