#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class ATM{
        int nominal;
        int count;
        public:
                ATM(int n, int c): nominal(n), count(c){}
                int getNom() {return nominal;}
                int getCount() {return count;}
                int getRes() {return nominal*count;}
                ATM operator-(int);
};

ATM ATM::operator-(int _money) {
    return ATM(nominal, count - _money);
}

bool compare(ATM &a, ATM &b){
        return a.getNom() > b.getNom();
}
void init(std::vector <ATM> &atms){
    std::ifstream fin;
    fin.open("example.txt");
    if (!fin){
        exit(-1);
    }
    int nom, count;
        std::vector<int> v;
    while (fin >> nom >> count){
        if (nom < 0 || count < 0 || std::find(v.begin(), v.end(), nom) != v.end()) exit(-1);
        atms.push_back(ATM(nom, count));
        v.push_back(nom);
    }
    v.clear();
    fin.close();
}

void write_info(std::vector <ATM> &atm){
    std::ofstream fout;
    fout.open("example.txt");
    for (int i = 0; i < atm.size(); i++){
        fout << atm[i].getNom() << " - " << atm[i].getCount() << std::endl;
    }
    fout.close();
}
void get_money(std::vector<ATM>& atm, int money) {
    int c, count;
    std::vector<int> temp;
    for (int i = 0; i < atm.size(); i++) {
        if (money < atm[atm.size()].getNom()) break; // under construction
        if (atm[i].getCount() == 0) {
            temp.push_back(0);
            continue;
        }
        c = money / atm[i].getNom();
        count = c > atm[i].getCount() ? atm[i].getCount() : c;
        temp.push_back(count);
        money -= atm[i].getNom() * c;
    }

    if (money != 0) std::cout << "FAIL" << std::endl;
    else{
        std::cout << "Извлечено: " << std::endl;
        for (int i = 0; i < atm.size(); i++) {
            atm[i] = atm[i] - temp[i];
            if (temp[i] != 0) {
                std::cout << atm[i].getNom() << " - " << temp[i] << std::endl;
            }
        }
    }
}


void get_info(std::vector <ATM> &atm){
        std::cout << "Nominal - Count" << std::endl;
        for (int i = 0; i < atm.size(); i++){
                std::cout << atm[i].getNom() << " - " << atm[i].getCount() << std::endl;
        }
}

int main() {
    int option;
    std::vector<ATM> atms;
    init(atms);
    std::sort(atms.begin(), atms.end(), compare);

    while (true) {
        std::cout << "SELECT\n";
        while(!(std::cin >> option)){
	    option = 3;
	    std::cin.clear();
	}
        if (std::cin.eof()) {
            exit(-1);
        }
        switch(option){
        	case 1 :  int money;
                          std::cout << "How many rubles do you want?\n";
                          std::cin >> money; 
                          if (std::cin.eof()) exit(-2);
                          else {
                              get_money(atms, money);
                              write_info(atms);
            		  }
			  break;
                case 2 : get_info(atms);
			 break;
                default : std::cout << "NO\n";
			  break;
        }
	}
}
