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
		virtual int attack(char * p) = 0;
		virtual char isa() = 0;
		void desk();
		static bool deskout(char * p);
};

class King : virtual public Figure {
	public:
		King() {};
		King(char * p) : Figure(p) {};
		int attack(char * p);
};

class Rook : virtual public Figure {
	public:
		Rook() {};
		Rook(char * p) : Figure(p) {};
		int attack(char * p);
};

class Lord : public King, public Rook {
	public:
		Lord(char * p) : Figure(p) {};
		char isa() {return 'L';};
		int attack(char*);
};

bool Figure::deskout(char * p) {
	return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8'));
}

void Figure::desk() {
	int i, j;
	char s[2];
	const char * mark = ".+x";
	char m;
	cout << "  a b c d e f g h\n";
	for (i = 8; i > 0; i--) {
		cout << i << ' ';
		s[1] = '0' + i;
		for (j=0; j < 8; j++) {
			s[0] = 'a' + j;
			m = (!(*this == s)) ? mark[attack(s)] : isa();
			cout << m << " ";
		}
		cout << i << '\n';
	}
	cout << "  a b c d e f g h\n";
	return;
}

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

int main(int argc, char * argv[]) {
	if (argc < 2)
		return -1;
	
	Lord k(argv[1]);
	k.desk();
}
