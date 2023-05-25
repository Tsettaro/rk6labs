class Dlink{
	protected:
		Dlink* _next;
		Dlink* _prev;
	public:
		Dlink() : _next(NULL), _prev(NULL) {}
        void excluse();
		Dlink* incr();
        Dlink* toTail();
		Dlink* toTail(int);
		Dlink* before(Dlink*);
};