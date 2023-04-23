class Dlink
{
	protected:
		Dlink* _next;
		Dlink* _prev;
	public:
		Dlink() : _next(NULL), _prev(NULL) {}
		Dlink* append(Dlink*);
		Dlink* incr();
		Dlink* decr();
		void excluse();
		Dlink* after(Dlink*);
		Dlink* before(Dlink*);
		Dlink* toHead();
		Dlink* toHead(int);
		Dlink* toTail();
		Dlink* toTail(int);
};

