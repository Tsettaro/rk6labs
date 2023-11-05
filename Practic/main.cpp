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
};

bool compare(ATM &a, ATM &b){
	return a.getNom() > b.getNom();
}
void init(std::vector <ATM> &atms){
	FILE *fp;
    fp = fopen("example.txt", "r");
	std::vector<int> v;
	if (fp == NULL) exit(-1);
    int nom, count, a;
    while((a = fscanf(fp, "%d - %d", &nom, &count)) != EOF){
		if (a != 2 || nom < 0 || count < 0) exit(-1);
		if (std::binary_search(v.begin(), v.end(), nom) == true) exit(-1);
		v.push_back(nom);
		atms.push_back(ATM(nom, count));
    }
	v.clear();
	fclose(fp);
}

int get_money(std::vector <ATM> &atm, int money){
	int c;
	fp = fopen("example.txt", "w");
	for (int i = 0; i < atm.size(); i++){
		c = money/atm[i].getNom();
		if (c > atm[i].getCount()) money -= atm[i].getRes();
	}
	return money;
}

int main(){
	int money;
	std::vector <ATM> atms;
    init(atms);
	std::sort(atms.begin(), atms.end(), compare);
	while(True){
		std::cout << "How many rubles do you want?" << std::endl;
		std::cin >> money;
	}
}
