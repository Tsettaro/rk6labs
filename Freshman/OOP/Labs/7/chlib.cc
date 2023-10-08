#include "chlib.h"

int King::attack(char * p) {
	if (deskout(p))
		return 0;
	int x = abs(p[0] - pos[0]);
	int y = abs(p[1] - pos[1]);
	if (x + y < 2 || (x == y && x + y == 2))
		return 1;
	return 0;
}

int Rook::attack(char * p) {
	if (deskout(p))
		return 0;
	int x = abs(p[0] - pos[0]);
	int y = abs(p[1] - pos[1]);
	if ((x + y > 0 && y == 0) || (x + y > 0 && x == 0))
		return 1;
	return 0;
}

int Lord::attack(char * p) {
	if (Rook::attack(p) > 0)
		return 1;
	if (King::attack(p) > 0)
		return 2;
	return 0;
}
