#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

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

void write_info(std::vector <ATM> &atm){
	FILE *fp;
	fp = fopen("example.txt", "w");
	if (fp == NULL) exit(-1);
	for (int i = 0; i < atm.size(); i++){
		fprintf(fp, "%d - %d\n", atm[i].getNom(), atm[i].getCount());
	}
	fclose(fp);
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
        std::cin >> option;

        if (std::cin.eof()) {
            exit(-1);
        }

        if (option == 1) {
            int money;
            std::cout << "How many rubles do you want?\n";
            std::cin >> money;

            if (std::cin.eof()) exit(-2); 
			else {
                get_money(atms, money);
				write_info(atms);
            }
        } else if (option == 2) {
            get_info(atms);
        }
    }

}
