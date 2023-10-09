#include <iostream>

using std::cout;
using std::cin;

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
        friend std::istream& operator>>(std::istream&, Figure&);
		virtual int attack(char * p) = 0;
		virtual char isa() = 0;
		void desk();
		static bool deskout(char * p);
        char* get_pos() {return pos;};
};

Figure& Figure::operator=(char* s){
    pos[0] = s[0];
    pos[1] = s[1];
    return (*this);
}

std::istream& operator>>(std::istream& in, Figure& A){
    char s[2];
    std::cin.unsetf(std::ios::skipws);
    in >> s[0] >> s[1];
    s[0] = tolower(s[0]);
    in.ignore(64, '\n');
    if ((A.attack(s) == 0) || (A == s)){
        in.clear((std::ios::failbit | in.rdstate()));
    }
    A = s;
    return in;
}

class Rook: public Figure{
    public:
        Rook(char* p) : Figure(p){};
        int attack(char*);
        char isa() {return 'R';};
};

class Player{
    protected:
        char* name;
        Rook* rook;
    public:
        Player(Rook* p) {
            rook = p;
        }
        virtual int strategy() = 0;
        char* get_name();
        int request();
};

int Player::request(){
    if (*rook == (char*)"a1"){
        return 0;
    } else{
        return 1;
    }
}
char* Player::get_name(){
    return name;
}

class Human : public Player{
    Human(Rook* rook, char* p) : Player(rook) {name = p;};
    int strategy();
};

int Human::strategy(){
    cout << "Ход игрока: ";
    return (bool)(cin >> *rook);
}

class AI : public Player{
    AI(Rook* rook, char* p) : Player(rook) {name = p;};
    int strategy();
};

int AI::strategy(){
    cout << "Ход компьютера: ";
    char s[2];
    char *pos = rook->get_pos();
    if (int(pos[0]) - 96 > int(pos[1]) - 48){
        s[0] = char('a' + int(pos[1])-49);
        s[1] = pos[1];
    } else{
        s[0] = pos[0];
        s[1] = char('1' + (int(pos[0]) - 97));
    }
    if (*rook == s){
        return 0;
    } else{
        cout << s[0] << s[1] << std::endl;
        *rook = s;
    }
    return 1;
}
bool Figure::deskout(char* p) {
    return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8'));
}

int Rook::attack(char *p) {
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
/*
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
        if (*this == "a1") break;
        cur_player = (cur_player == 1) ? 2 : 1;
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
*/
int main() {
    Rook k("e5");
    k.desk();
}