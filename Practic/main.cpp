#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::endl;
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
	FILE *fp;
	int nom, count, a;
	std::vector<int> v;
    fp = fopen("example.txt", "r");
	if (fp == NULL) exit(-1);
    while((a = fscanf(fp, "%d - %d", &nom, &count)) != EOF){
		if (a != 2 || nom < 0 || count < 0) exit(-1);
		if (std::binary_search(v.begin(), v.end(), nom) == true) exit(-1);
		v.push_back(nom);
		atms.push_back(ATM(nom, count));
    }
	v.clear();
	fclose(fp);
}

void get_money(std::vector <ATM> &atm, int money){
	int c, count;
	int temp[atm.size()] = {};
	for (int i = 0; i < atm.size(); i++) {
        if (money < atm[atm.size()].getNom()) break; // under construction
        if (atm[i].getCount() == 0) {
            temp[i] = 0;
            continue;
        }
        c = money / atm[i].getNom();
        count = c > atm[i].getCount() ? atm[i].getCount() : c;
        temp[i] = count;
        money -= atm[i].getNom() * c;
    }

    if (money != 0) std::cout << "FAIL" << std::endl; 
    else{
        cout << "Извлечено: " << std::endl;
        for (int i = 0; i < atm.size(); i++) {
            atm[i] = atm[i] - temp[i];
            if (temp[i] != 0) {
                cout << atm[i].getNom() << " - " << temp[i] << endl;
            }
        }
    }
	
}


void get_info(std::vector <ATM> &atm){
	std::cout << "Nominal - Count" << std::endl;
	for (int i = 0; i < atm.size(); i++){
		cout << atm[i].getNom() << " - " << atm[i].getCount() << endl;
	}
}

int main() {
    int option;
    std::vector<ATM> atms;
    init(atms);
    std::sort(atms.begin(), atms.end(), compare);

    while (true) {
        std::cout << "SELECT\n";
        std::cin >> option;

        if (std::cin.eof()) {
            exit(-1);
        }

        if (option == 1) {
            int money;
            std::cout << "How many rubles do you want?\n";
            std::cin >> money;

            if (std::cin.eof()) {
                exit(-2);
            } else {
                get_money(atms, money);
            }
        } else if (option == 2) {
            get_info(atms);
        }
    }
}
