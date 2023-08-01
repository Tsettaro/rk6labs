#include "header.hpp"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

// Алгоритм Евклида
int Euclide(int n, int m){
	int r = 1;
	while (n != 0){
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

void Fraction::reduce(){
	int nod = Euclide(abs(_nom), _den); // if we work with -2/-3 ???
	_nom /= nod;
	_den /= nod;
}

Fraction::Fraction(char *s){
	char *p = strchr(s, '/');
	_den = 1;
	if (p != NULL){
		*(p++) = '\0';
		_den = atoi(p);
	}
	_nom = atoi(s);
}

Fraction::operator char*(){
	static char s[32];
	sprintf(s, "%d/%d", _nom, _den);
	return s;
}

Fraction Fraction::operator ~(){
	int k = 0;
	int sign = (_nom < 0) ? -1 : 1;
	int n = sign * _nom;
	while (k < n){
		k += _den;
	}
	n = k - n;
	return Fraction(sign * n, _den);
}


int main(int argc, char **argv){
	if (argc < 2) return -1;
	Fraction x(argv[1]);
	x.reduce();
	Fraction result = ~x;
	std::cout << (char*)result << std::endl;
}
