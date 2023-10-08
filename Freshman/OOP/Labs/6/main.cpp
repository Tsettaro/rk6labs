#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Dlink.hpp"
#include "SymLink.hpp"

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
SymLink* SymLink::seek(int n)
{
	if (n>0)
		return (SymLink*) toTail(n);
	if (n<0)
		return (SymLink*) toHead(-n);
	return this;
}
Dlink* Dlink::incr()
{
	return _next;
}
Dlink* Dlink::decr()
{
	return _prev;
}
Dlink* Dlink::append(Dlink* p)
{
	p->_next = this;
	_prev = p;
	return(p);
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
Dlink* Dlink::toTail()
{
	Dlink* p = this;
	Dlink* q = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->_next;
	}
	return q;
}
Dlink* Dlink::toTail(int n)
{
	Dlink* p = this;
	Dlink* q = this;
	int i = 0;
	while(p != NULL)
	{
		q = p;
		if (i == n) break;
		p = p->_next;
		i++;
	}
	return q;
}

int main(int argc, char* argv[])
{
	unsigned seed = 0;
	int count = 0;
	int length, ch;
	unsigned pos;
	int side;
	SymLink* watch[2];
	SymLink* head;
	SymLink* tail;
	SymLink* p, *q;
	Dlink*(Dlink::* insert[])(Dlink*) = {&Dlink::after, &Dlink::before};
	if (argc>1)
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

}
















