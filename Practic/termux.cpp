#include <iostream>
#include <algorithm>
#include <fstream>
#define SIZE 1000
using std::cin, std::cout, std::cerr;
class ATM{
        int nominal;
        int count;
        public:
            ATM() {nominal = 0; count = 0;};
            ATM(int n, int c): nominal(n), count(c){}
            int getNom() {return nominal;}
            int getCount() {return count;}
            int getRes() {return nominal*count;}
            ATM operator-(int);
            ATM operator+(int);
};

ATM ATM::operator-(int _money) {
    return ATM(nominal, count - _money);
}
ATM ATM::operator+(int _money) {
    return ATM(nominal, count + _money);
}

bool compare(ATM a, ATM b){
    return a.getNom() > b.getNom();
}
void init(ATM* atms, int& size){
    std::ifstream fin;
    fin.open("example.txt");
    if (!fin){
        exit(-1);
    }
    int nom, count;
    while (fin >> nom >> count){
         if (nom < 0 || count < 0){
            fin.close();
            cerr << "ERROR" << std::endl;
            exit(-1);
         }
         atms[size++] = ATM(nom, count);
    }
    fin.close();
}

void write_info(ATM* atm, int& size){
    std::ofstream fout;
    fout.open("example.txt");
    for (int i = 0; i < size; i++){
        fout << atm[i].getNom() << ' ' <<  atm[i].getCount() << std::endl;
    }
    fout.close();
}
void get_money(ATM* atm, int& size) {
    int c, count, money;
    cout << "How many rubles do you want?\n";
    if(!(cin >> money)) {
        cerr << "ERROR" << std::endl;
        exit(-1);
    }
    int* temp = new int[size];
    for (int i = 0; i < size; i++){
        if (money < atm[size].getNom()) break; 
        if (atm[i].getCount() == 0) {
            temp[i] = 0;
            continue;
        }
        c = money / atm[i].getNom();
        count = c > atm[i].getCount() ? atm[i].getCount() : c;
        temp[i] = count;
        money -= atm[i].getNom() * c;
    }
    if (money != 0) {
        cout << "FAIL" << std::endl;
    }
    else{
        cout << "Извлечено: " << std::endl;
        for (int i = 0; i < size; i++) {
            atm[i] = atm[i] - temp[i];
            if (temp[i] != 0) {
                cout << atm[i].getNom() << " - " << temp[i] << std::endl;
            }
        }
    }
    delete []temp;
}

void get_info(ATM* atm, int& size){
    cout << "Nominal - Count" << std::endl;
    for (int i = 0; i < size; i++){
        cout << atm[i].getNom() << " - " << atm[i].getCount() << std::endl;
    }
}

void push_money(ATM *atm, int& size){
    int money = 0;
    for (int i = 0; i < size; i++){
        cout << "How many " << atm[i].getNom() << " do you want to push?\n";
        if (!(cin >> money) || money < 0){
            cerr << "ERROR" << std::endl;
            exit(-1);
        }
        atm[i] = atm[i] + money;
    }
}

int main() {
    ATM* atms = new ATM[SIZE];
    int size  = 0;
    init(atms, size);
    std::sort(atms, atms + size, compare);
    int option;
    while (true){
        cout << "SELECT: 1 - Take money, 2 - Get info, 3 - Push money\n";
        if(!(cin >> option)) {
            cerr << "ERROR" << std::endl;
            exit(-1);
        }
        if (cin.eof()) {
            exit(-1);
        }
        switch(option){
        case 1 :    
                    get_money(atms, size);
                    write_info(atms, size);
                    break;
        case 2 :    get_info(atms, size);
                    break;
        case 3 :    push_money(atms, size);
                    write_info(atms, size);
                    break;
        default :   cout << "ERROR\n";
			        break;
        }
    }
    delete []atms;
}
