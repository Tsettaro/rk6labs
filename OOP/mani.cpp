#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;

class Figure {
    private:
        char pos[2];
        int cur_player;
    public:
        Figure() : cur_player(1) {pos[0] = 'h'; pos[1] = '8';};
        bool operator==(string p) { return (pos[0] == p[0]) && (pos[1] == p[1]); };
        static bool deskout(string p);
        int attack(string p);
        char isa() {return 'R';};
        void desk();
        void game();
        void makeMove(string p);
};

bool Figure::deskout(string p) {
    return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8'));
}

int Figure::attack(string p) {
    if (deskout(p) || (p[1] == pos[1] && p[0] > pos[0]) || (p[0] == pos[0] && p[1] > pos[1]))
        return 0;
    int x = abs(p[0] - pos[0]);
    int y = abs(p[1] - pos[1]);
    if ((x + y > 0 && y == 0) || (x + y > 0 && x == 0))
        return 1;
    return 0;
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

void Figure::game(){
    string move;
    while (true){
		this->desk();
        if (cur_player == 1) {
            cout << "Ход игрока: ";
            std::cin >> move;
            if (deskout(move) || *this == move ||(pos[0] != move[0] && pos[1] != move[1]) || (pos[0] == move[0] && move[1] > pos[1]) || (pos[1] == move[1] && move[0] > pos[0])) {
                cout << "Game over!" << std::endl;
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
            cout << "Ход компьютера: " << move << std::endl;
            makeMove(move);
        }
        cur_player = (cur_player == 1) ? 2 : 1;
        if (*this == "a1") break;
    }
    if (cur_player == 1){
        cout << "Победил игрок!" << std::endl;
    } else {
        cout << "Победил компьютер!" << std::endl;
    }
}

void Figure::makeMove(string p){
    pos[0] = p[0];
    pos[1] = p[1];
}

int main() {
    Figure k;
    k.game();
}