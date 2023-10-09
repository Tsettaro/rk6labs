#ifndef CHESSLIB
#define CHESSLIB
#include "chman.h"

class Player{
    protected:
        Rook* rook;
        const char* name;
    public:
        Player(Rook* p) {
            rook = p;
        }
        virtual int strategy() = 0;
        int request();
        const char* get_name();
};

class Human : public Player{
    public:
        Human(Rook* rook, const char*p) : Player(rook){name = p;};
        int strategy();
};

class AI : public Player{
    public:
        AI(Rook* rook, const char* p) : Player(rook){name = p;};
        int strategy();
};

#endif