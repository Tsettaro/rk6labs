#include <iostream>

class Heap{
	private:
		int size;
	public:
		Heap(int s) : size(s) {};
		int get(int n = 0){size-=n; return size;};
};

class Gamer{
	protected:
		Heap *heap;
		const int limit;
		const char* name;
	public:
		Gamer(Heap &h, int l) : limit(l) {heap = &h;};
		int query();
		virtual ~Gamer() {};
		virtual int move() = 0;
};

class Man : public Gamer{
	public:
		Man(Heap &h, int l, const char* n) : Gamer(h, l) {name = n;};
		int move();
};

class Comp : public Gamer{
        public:
                Comp(Heap &h, int l, const char* n) : Gamer(h, l) {name = n;};
                int move();
};

int Gamer::query(){
	if (heap->get() > 0) std::cout << "Heap = " << heap->get() << " " << name << " > ";
	return heap->get();
}

int Man::move(){
	int g;
	std::cin >> g;
	if (g < 1 || g > limit) g = 1;
	return heap->get(g);
}

int Comp::move(){
	int x = 1;
	int s = heap->get();
	while (((s-x)%(limit+1) != 0) && x <= limit){
		x++;
	}
	if (x > limit) x = limit;
	std::cout << x << std::endl;
	return heap->get(x);
}

int main(int argc, char **argv){
	if (argc < 3) exit(-1);
	Heap heap(atoi(argv[1]));
	Gamer *g[] = {new Man(heap, atoi(argv[2]), "Man"), new Comp(heap, atoi(argv[2]), "Computer")};
	int i = 0;
	while (g[i]->query() > 0){
		g[i]->move();
		if (++i > 1) i = 0;
	}
	if (i == 1) std::cout << "WINNER";
	else std::cout << "LOSER";
	delete g[0];
	delete g[1];
}
