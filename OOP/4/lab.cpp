#include <iostream>
#include <cstring>

class Alpha{
	unsigned _bin;
	public:
		Alpha() : _bin(0) {};
		Alpha (const char *, const char*);
		Alpha operator &(Alpha&);
		operator char*();
		int pop(unsigned b);
		int operator () (Alpha&, Alpha&);
};

Alpha::Alpha(const char *s, const char*c){
	_bin = 0;
	while (*s){
		if (strchr(c, tolower(*s))){
			_bin|= (1 << (tolower(*s) - 'a'));
		}
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
	Alpha str(argv[1], "bcdfghjklmnpqrstvwxz");
	Alpha sogl("bcdfghjklmnpqrstvwxz", "bcdfghjklmnpqrstvwxz");
	Alpha H;
	Alpha set_sogl = str & sogl;
	int d = H(set_sogl, sogl); // вызов объекта класса Альфа как функция
	cout << "<(" << (char*)str << ", " << (char*)sogl << ") = " << d << '\n';
}
