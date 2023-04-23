class SymLink : public Dlink
{
	private:
		char _let;
	public:
		SymLink(char let) : Dlink(), _let(let) {}
		SymLink* seek(int);
		SymLink* incr() {return (SymLink*) Dlink::incr();}
		SymLink* decr() {return (SymLink*) Dlink::decr();}
		int print();
};