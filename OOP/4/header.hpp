// (a=(b=c))
// () - оператор 
class Alpha{
	unsigned _bin;
	public:
		Alpha() : _bin(0) {};
		Alpha (const char *, const char*);
		Alpha operator &(Alpha&);
		operator char*();
		int pop(unsigned);
		int operator () (Alpha&, Alpha&);
};
