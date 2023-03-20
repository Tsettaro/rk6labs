// (a=(b=c))
// () - оператор 
class Alpha{
	unsigned _bin;
	public:
		Alpha() : _bin(0) {};
		Alpha (const char *);
		Alpha operator &(Alpha&);
		operator char*();
		int pop(unsigned b);
		int operator () (Alpha&, Alpha&);
};
