#include <iostream>
#include <cstdio>
#include <cstdlib>

class Dlink
{
	protected:
		Dlink* _next;
		Dlink* _prev;
	public:
		Dlink() : _next(NULL), _prev(NULL) {}
        void excluse();
		Dlink* incr();
		Dlink* decr();
		Dlink* after(Dlink*);
		Dlink* before(Dlink*);
};

class SymLink : public Dlink
{
	private:
		char _let;
	public:
		SymLink(char let) : Dlink(), _let(let) {}
		SymLink* incr() {return (SymLink*) Dlink::incr();}
		SymLink* decr() {return (SymLink*) Dlink::decr();}
		int print();
        int mx();
};

int SymLink::mx(){
    SymLink *p = this->incr();
    SymLink *q;
    int m = -1, s1;
    while ((p->incr())->_let != '\n'){
        q = p->incr();
        if (q != NULL && q->_let != '\n'){
            s1 = abs(p->_let - q->_let);
            if (m < s1) m = s1;
        }
        p = q;
    }
    return m;
}

int SymLink::print()
{
	SymLink *p = this;
	SymLink *q;
	int n = 0;
	while(p != NULL)
	{
		putchar(p->_let);
		q = p->incr();
		p = q;
		n++;
	}
	return(n);
}

Dlink* Dlink::incr()
{
	return _next;
}
Dlink* Dlink::decr()
{
	return _prev;
}

void Dlink::excluse()
{
	if(_next !=  NULL)
		_next->_prev = _prev;
	if(_prev  !=  NULL)
		_prev->_next = _next;
	return;
}
Dlink* Dlink::after(Dlink* p)
{

	p->_next = _next;
	p->_prev = this;
	if (_next !=  NULL)
		_next->_prev = p;
	_next = p;
	return p->_next;
}
Dlink* Dlink::before(Dlink* p )
{
	p->_next = this;
	p->_prev = _prev;
	if (_prev !=  NULL)
		_prev->_next = p;
	_prev = p;
	return p->_prev;
}

int main(int argc, char* argv[])
{
	int max = 0;
	int length = 0, ch, count = 1;
    SymLink* head;
	SymLink* tail;
    SymLink* q;
    SymLink* watch[2];
    watch[0] = head = new SymLink('\n');
	watch[1] = tail = new SymLink('\n');
	tail->before(head);
    while((ch = getchar())  !=  '\n'){
		q = new SymLink(ch);
		tail->before(q);
	}
    head->print();
    max = head->mx();
    std::cout << max;
	/* if (argc>1)
		seed = atoi(argv[1]);
	watch[0] = head = new SymLink('\n');
	watch[1] = tail = new SymLink('\n');
	tail->before(head);
	while((ch = getchar())  !=  '\n')
	{
		q = new SymLink(ch);
		tail->before(q);
	}
	if ((length = head->print() - 1) < 2)
		count = length;
	srand(seed);
	while(count < length)
	{
		side = rand()%2;
		while((pos = rand()%length) == 0);
		printf("%*c\n", pos, '^');
		q = head->seek(pos);
		q->excluse();
		(watch[side]->*insert[side])(q);
		head->print();
		count++;
	}
	p = tail;
	while(p != NULL)
	{
		q = p->decr();
		p->excluse();
		delete p;
		p = q;
	}
    return(length+1); */
}