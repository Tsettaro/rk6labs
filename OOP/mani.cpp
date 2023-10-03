#include <iostream>

using std::cout;

class Figure {
	protected:
		char pos[2];
	public:
		Figure() {};
		Figure(std::string p) {
			pos[0] = p[0];
			pos[1] = p[1];
		};
		bool operator==(std::string p) { return (pos[0] == p[0]) && (pos[1] == p[1]); };
		virtual int attack(std::string p) = 0;
		virtual char isa() = 0;
		void desk();
		static bool deskout(std::string p);
};

bool Figure::deskout(std::string p) {
	return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8'));
}

void Figure::desk() {
	int i, j;
	char s[2];
	const char * mark = ".+";
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

class Rook : virtual public Figure {
	private:
		int cur_player;
	public:
		Rook() : Figure("h8"), cur_player(1) {};
		char isa() {return 'R';};
		int attack(std::string p);
		void game();
		void makeMove(std::string p);
};

void Rook::game(){
	std::string move;
	while (pos[0] != 'a' && pos[1] != '1'){
		this->desk();
		if (cur_player == 1) {
            std::cout << "Ход игрока: ";
            std::cin >> move;
            if (deskout(move) || (pos[0] != move[0] && pos[1] != move[1]) || (pos[0] == move[0] && move[1] > pos[1]) || (pos[1] == move[1] && move[0] > pos[0])) {
                std::cout << "Неверный ход! Игра завершается." << std::endl;
                exit(-1);
            }
			makeMove(move);
        } else {
			if (int(pos[0]) - 96 > int(pos[1]) - 48){
				move = char('a' + int(pos[1])-49);
				move+=pos[1];
			} else{
				move = pos[0];
				move+=char('1' + (int(pos[0]) - 97));
			}
			std::cout << "Ход компьютера: " << move << std::endl;
            makeMove(move);
        }
        cur_player = (cur_player == 1) ? 2 : 1;
	}
}

int Rook::attack(std::string p) {
	if (deskout(p) || (p[1] == pos[1] && p[0] > pos[0]) || (p[0] == pos[0] && p[1] > pos[1]))
		return 0;
	int x = abs(p[0] - pos[0]);
	int y = abs(p[1] - pos[1]);
	if ((x + y > 0 && y == 0) || (x + y > 0 && x == 0))
		return 1;
	return 0;
}

void Rook::makeMove(std::string p){
	pos[0] = p[0];
	pos[1] = p[1];
}

int main(int argc, char * argv[]) {
	Rook k;
	k.game();
}
