#include <iostream>
#include "chlib.h"

int main(int argc, char * argv[]) {
	if (argc < 2)
		return -1;
	
	Lord k(argv[1]);
	k.desk();
}