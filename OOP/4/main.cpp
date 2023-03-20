#include "header.hpp"
#include <iostream>
#include <cstring>

Alpha::Alpha(const char *s){
	_bin = 0;
	while (*s){
		_bin|= (1 << (tolower(*s) - 'a'));
		s++;
	}
}

// эффективный метод подсчёта единичных разрядов
int Alpha::pop(unsigned b){
	int i = 0;
	while (b != 0) {
		b = b & (b - 1);
		i++;
	}
	return i;
}

Alpha Alpha::operator &(Alpha &n){
	Alpha result;
	result._bin = _bin & n._bin;
	return result;
}

int Alpha::operator () (Alpha &m, Alpha &n){
	return pop(m._bin ^ n._bin);
}

Alpha::operator char*(){
	static char s[32];
	unsigned b = _bin;
	int i = 0, j = 0;
	while (b > 0){
		if (b & 1) {
			s[j++] = 'a' + i;
		}
		i++;
		b >>= 1;
	}
	s[j] = '\0';
	return s;
}

int main(int argc, char **argv){
	using std::cout;
	if (argc < 2) return -1;
	Alpha str(argv[1]);
	Alpha sogl("bcdfghjklmnpqrstvwxz");
	Alpha H;
	Alpha set_sogl = str & sogl;
	int d = H(set_sogl, sogl);
	cout << "<(" << (char*)str << ", " << (char*)sogl << ") = " << d << '\n';
}