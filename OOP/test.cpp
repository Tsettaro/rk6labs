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

bool Figure::deskout(char * p) {
	return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8')); // && 
}

void Figure::desk() {
	int i, j;
	char s[2];
	const char mark = '.';
	char m;
	cout << "  a b c d e f g h\n";
	for (i = 8; i > 0; i--) {
		cout << i << ' ';
		s[1] = '0' + i;
		for (j=0; j < 8; j++) {
			s[0] = 'a' + j;
			m = (!(*this == s)) ? mark : isa();
			cout << m << " ";
		}
		cout << i << '\n';
	}
	cout << "  a b c d e f g h\n";
	return;
}

class Rook : virtual public Figure {
	private:
		int cur_player;
	public:
		Rook(char * p) : Figure(p), cur_player(1) {};
        char isa() {return 'R';};
		int attack(char * p);
		void game();
};

void Rook::game(){
	this->desk();
	if (cur_player == 1) {
            std::cout << "Ход игрока (Введите число полей для перестановки): ";
            int move;
            std::cin >> move;

            if (!makeMove(move)) {
                std::cout << "Неверный ход! Игра завершается." << std::endl;
                return;
            }
        } else {
            std::cout << "Ход компьютера: ";
            int move = -1;
            while (move < 0 || move > 7) {
                move = rand() % 9 - 1;
            }
            makeMove(move);
            std::cout << move << std::endl;
        }

        cur_player = (cur_player == 1) ? 2 : 1;
}

int Rook::attack(char * p) {
    
}
int main() {
	Rook k("h8");
	k.game();
}