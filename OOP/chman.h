#ifndef CHESSMAN
#define CHESSMAN

#include <iostream>
#include <string>
using std::string;

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

#endif