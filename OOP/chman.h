#ifndef CHESSMAN
#define CHESSMAN

#include <iostream>
using std::cout;

class Figure {
	protected:
		char pos[2];
	public:
		Figure() {}; // нужен для реализации мн. наследования
		Figure(char * p) {
			pos[0] = p[0];
			pos[1] = p[1];
		};
		bool operator==(char * p) { return (pos[0] == p[0]) && (pos[1] == p[1]); };
        Figure& operator=(char*);
		virtual int attack(char * p) = 0;
		virtual char isa() = 0;
		void desk();
		static bool deskout(char * p);
        char* get_pos() {return pos;};
};

class Rook: public Figure{
    public:
        Rook(char* p) : Figure(p){};
        int attack(char*);
        char isa() {return 'R';};
};

#endif