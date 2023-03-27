#include "header.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
Magic::Magic(unsigned degree) : Square(degree){};

void Magic::print(){
	int len = width();
	for (int i = 0; i < _degree; i++){
		for (int j = 0; j < _degree; j++){
			printf("%0*d ", len, _table[i][j]); // звёздочка отвечает за ширину
		}
		putchar('\n');
	}
	putchar('\n');
}

int Magic::width(){
	int max = _degree * _degree;
	int result = 0;
	while (max > 0){
		max/=10;
		result++;
	}
	return result;
}

int Magic::reflect(int k){
	if (k < 0) {return k + _degree;}
	else if (k > _degree - 1) {return k - _degree;}
	return k;
}

void Magic::horse(){
	int i, j;
	int z = 1;
	int row = 0, col = 0;
	int max = _degree * _degree;
	row = _degree-1;
	col = _degree/2;
	_table[row][col] = z;
	while (z < max){
		i = reflect(row - 2);
		j = reflect(col + 1);
		if (_table[i][j] > 0){
			i = reflect(row-4);
			j = reflect(col);
		}
		row = i;
		col = j;
		++z;
		_table[row][col] = z;
	}
}

int main(int argc, char **argv){
	if (argc < 2) return -1;
	int n = atoi(argv[1]);
	if ((n % 2) == 0) return -2;
	Magic m(atoi(argv[1]));
	m.horse();
	m.print();
	return 0;
}
