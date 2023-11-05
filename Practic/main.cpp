#include <iostream>
#include <cstdio>
#include <vector>

class ATM{
	int nominal;
	int count;
	public:
		ATM(int n, int c): nominal(n), count(c){}
		int getNom(){return nominal;}
		int getCount(){return count;}
};

void init(std::vector <ATM> &atms){
	FILE *fp;
    fp = fopen("example.txt", "r");
    int nom, count, a;
    while((a = fscanf(fp, "%d - %d", &nom, &count)) != EOF){
		if (a != 2) exit(-1);
		atms.push_back(ATM(nom, count));
    }
	fclose(fp);
}

int main(){
	std::vector <ATM> atms;
    init(atms);
	std::cout << atms.size() << std::endl;
}