#include <iostream>
#include <cstdio>
int main(){
	FILE *fp;
	fp = fopen("example.txt", "r");
	int nom, count;
	while(fscanf("%d – %d", fp, &nom, &count)){
		std::cout << nom << " " << count << std::endl;
	}
	fclose(fp);
}
