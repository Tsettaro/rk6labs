#include <iostream>

class Heap{
	private:
		int size;
		int max;
		int old;
	public:
		Heap(int m) : max(m) {size = 0;};
		int get(int n = 0) {size+=n; return size;}
		int get_max() {return max;}
		void set_old(int o) {old = o;}
		int get_old() {return old;}
};

class Gamer{
	protected:
		Heap *heap;
		const int limit;
		const char *name;
	public:
		Gamer(Heap &h, int l) : limit(l) {heap = &h;};
		int query();
		virtual int move() = 0;
		virtual ~Gamer() {};
};

class Human : public Gamer{
	public:
		Human(Heap &heap, int l, const char *n) : Gamer(heap, l) {name = n;};
		int move(); 
};

class Comp : public Gamer{
        public:
                Comp(Heap &heap, int l, const char *n) : Gamer(heap, l) {name = n;};
                int move();
};

int Gamer::query(){
	if (heap->get() < heap->get_max())
		std::cout << "Heap = " << heap->get() << " " << name << " > ";
	return heap->get();
}

int Human::move(){
	int g;
	std::cin >> g;
	if (g < 1 || g > limit) g = 1;
	heap->set_old(g);
	return heap->get(g);
}

int Comp::move(){
	int x = 1;
	int mx = heap->get_max();
	int s = heap->get();
	while (((mx - s - x) % (limit +1) != 0) && (x <= limit)){
		x++;
	}
	if (x > limit) x = heap->get_old();
	std::cout << x << std::endl;
	return heap->get(x);
}

int main(int argc, char **argv){
	if (argc < 3) exit(-1);
	Heap h(atoi(argv[1]));
	Gamer *g[] = {new Human(h, atoi(argv[2]), "Human"), new Comp(h, atoi(argv[2]), "Computer")};
	int i = 0;
	int mx = atoi(argv[1]);
	while (g[i]->query() < mx){
		g[i]->move();
		if (++i > 1) i = 0;
	}
	if (i == 1) std::cout << "Human win";
	else std::cout << "Computer win";
	delete g[0];
	delete g[1];
}
