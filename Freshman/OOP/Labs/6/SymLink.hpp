class SymLink : public Dlink{
	private:
		char _let;
	public:
		SymLink(char let) : Dlink(), _let(let) {}
		SymLink* incr() {return (SymLink*) Dlink::incr();}
		int print();
        int mx();
        int is_max(int);
};