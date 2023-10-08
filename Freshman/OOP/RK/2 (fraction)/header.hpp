class Fraction{
	int _nom;
	int _den;
	public:
		Fraction(int n = 0, int d = 1) : _nom(n), _den(d) {};
		Fraction(char *s);
		Fraction operator ~	();
		void reduce();
		operator char*();
};
