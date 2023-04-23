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
        Dlink* toHead();
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
        int cs(int);
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

Dlink* Dlink::toHead()
{
	Dlink* p = this;
	Dlink* q = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->_prev;
	}
	return q;
}

Dlink* Dlink::toHead(int n)
{
	Dlink* p = this;
	Dlink* q = this;
	int i = 0;
	while(p != NULL)
	{
		q = p;
		if (i == n) break;
		p = p->_prev;
		i++;
	}
	return q;
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

int SymLink::cs(int max){
    return (abs(_let - this->incr()->_let) == max);
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
    if ((length = head->print() - 2) < 2){
        std::cout << "No pairs!\n";
        return 0;
    }
    max = head->mx();
    q = head->incr();
    while (count < length){
        if (q->cs(max) == true){
            printf("%*c\n", count+1, '^');
            q->excluse();
            //head->print();
            count+=2;
        } else {count++;}
        q = q->incr();
    }
    q->print();
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