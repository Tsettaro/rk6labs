#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using std::cin, std::cout, std::cerr, std::vector;
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
void init(vector <ATM> &atms, const char* filename){
    std::ifstream fin;
    vector <int> temp;
    fin.open(filename);
    if (!fin){
        exit(-1);
    }
    int nom, count;
    while (fin >> nom >> count){
         if (nom < 0 || count < 0 || std::find(temp.begin(), temp.end(), nom) != temp.end()){
            fin.close();
            cerr << "ERROR" << std::endl;
            exit(-1);
         }
         temp.push_back(nom);
         atms.push_back(ATM(nom, count));
    }
    fin.close();
}

void write_info(vector <ATM> &atms, const char* filename){
    std::ofstream fout;
    fout.open(filename);
    for (int i = 0; i < atms.size(); i++){
        fout << atms[i].getNom() << ' ' <<  atms[i].getCount() << std::endl;
    }
    fout.close();
}
void get_money(vector <ATM> &atms) {
    int c, count, money;
    cout << "How many rubles do you want?\n";
    if(!(cin >> money)) {
        cerr << "ERROR" << std::endl;
        exit(-1);
    }
    vector <int> temp;
    for (int i = 0; i < atms.size(); i++){
        if (money < atms[atms.size()].getNom()) break; 
        if (atms[i].getCount() == 0) {
            temp.push_back(0);
            continue;
        }
        c = money / atms[i].getNom();
        count = c > atms[i].getCount() ? atms[i].getCount() : c;
        temp.push_back(count);
        money -= atms[i].getNom() * c;
    }
    if (money != 0) {
        cout << "FAIL" << std::endl;
    }
    else{
        cout << "Извлечено: " << std::endl;
        for (int i = 0; i < atms.size(); i++) {
            atms[i] = atms[i] - temp[i];
            if (temp[i] != 0) {
                cout << atms[i].getNom() << " - " << temp[i] << std::endl;
            }
        }
    }
}

void get_info(vector <ATM> &atms){
    cout << "Nominal - Count" << std::endl;
    for (int i = 0; i < atms.size(); i++){
        cout << atms[i].getNom() << " - " << atms[i].getCount() << std::endl;
    }
}

void push_money(vector <ATM> &atms){
    int money = 0;
    for (int i = 0; i < atms.size(); i++){
        cout << "How many " << atms[i].getNom() << " do you want to push?\n";
        if (!(cin >> money) || money < 0){
            cerr << "ERROR" << std::endl;
            exit(-1);
        }
        atms[i] = atms[i] + money;
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) return -1;
    vector <ATM> atms;
    init(atms, argv[1]);
    std::sort(atms.begin(), atms.end(), compare);
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
                    get_money(atms);
                    write_info(atms, argv[1]);
                    break;
        case 2 :    get_info(atms);
                    break;
        case 3 :    push_money(atms);
                    write_info(atms, argv[1]);
                    break;
        default :   cout << "ERROR\n";
			        break;
        }
    }
}
