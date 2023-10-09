#include "chlib.h"

int main() {
    int i = 1;
    Rook k((char*)"h8");
    Player* player[] = {new Human(&k, "Human"), new AI(&k, "Computer")};
    while (player[i]->request()){
        i = (i == 1) ? 0 : 1;
        k.desk();
        if (!(player[i]->strategy())){
            cout << player[i]->get_name() << " made mistake. " << player[(i+1 == 1) ? 1 : 0]->get_name() << " has won!\n";
            exit(-1);
        }
    }
    k.desk();
    if (i == 0){
        cout << player[0]->get_name() << " WINS!" << '\n';
    } else{
        cout << player[1]->get_name() << " WINS!" << '\n';
    }
    delete player[0];
    delete player[1];
}