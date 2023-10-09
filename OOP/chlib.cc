#include "chlib.h"

const char* Player::get_name(){
    return name;
}

int Player::request(){
    if (*rook == (char*)"a1"){
        return 0;
    } else{
        return 1;
    }
}

int Human::strategy(){
    cout << "Ход игрока: ";
    char s[3];
    char* pos = rook->get_pos();
    std::cin >> s[0] >> s[1];
    s[0] = tolower(s[0]);
    if (rook->deskout(s) || (pos[0] == s[0] && pos[1] == s[1]) || (pos[0] != s[0] && pos[1] != s[1]) || (pos[0] == s[0] && s[1] > pos[1]) || (pos[1] == s[1] && s[0] > pos[0])){
        return 0;
    }
    *rook = s;
    return 1;
}


int AI::strategy(){
    char s[2];
    char *pos = rook->get_pos();
    if (int(pos[0]) - 96 > int(pos[1]) - 48){
        s[0] = char('a' + int(pos[1])-49);
        s[1] = pos[1];
    } else{
        s[0] = pos[0];
        s[1] = char('1' + (int(pos[0]) - 97));
    }
    cout << "Ход компьютера: " << s[0] << s[1] << std::endl;
    *rook = s;
    return 1;
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
