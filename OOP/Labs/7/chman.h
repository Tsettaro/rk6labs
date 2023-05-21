#ifndef CHESSMAN
#define CHESSMAN

#include <iostream>

class Figure {
	protected:
	char pos[2];
	public:
	Figure() {};
	Figure(char * p) {
		pos[0] = p[0];
		pos[1] = p[1];
	};
	inline bool operator==(char * p) {
		return (pos[0] == p[0]) && (pos[1] == p[1]);
	};
	virtual int attack(char * p) = 0;
	virtual char isa() = 0;
	void desk();
	static bool deskout(char * p);
};

#endif