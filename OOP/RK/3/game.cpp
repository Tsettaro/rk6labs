#include <iostream>
#include <cstdlib>

class Heap{
    private:
        int size;
        int max;
    public:
        Heap(int s) : max(s) {size = 0;};
        int get(int n = 0){
            size+=n;
            return size;
        }
        int get_max(){return max;}
};

class Gambler{
    protected:
        Heap *heap;
        const int limit;
        const char *name;
    public:
        Gambler(Heap &h, int l) : limit(l) {heap = &h;};
        virtual int move() = 0;
        virtual ~Gambler(){};
        int query();
};

class Human : public Gambler{
    public:
        Human(Heap &h, int l, const char *n) : Gambler(h, l) {name  = n;};
        int move(); 
};

class Comp : public Gambler{
    public:
        Comp(Heap &h, int l, const char *n) : Gambler(h, l) {name  = n;};
        int move(); 
};

int Gambler::query(){
  if (heap -> get() < heap->get_max()){
    std::cout << "Heap = " << heap->get() << " " << name << " > ";
  }
  return heap->get();
}

int Human::move(){
    int g;
    std::cin >> g;
    if (g < 1 || g > limit){
        g = 1;
    }
    return heap->get(g);
}

int Comp::move(){
    int x = 1;
    int h = heap->get();
    int mx = heap->get_max();
    while (((mx - h - x) % (limit + 1) != 0) && (x < limit)){
        x++;
    }
    heap->get(x);
    std::cout << x << std::endl;
    return heap->get();
}

int main(int argc, char** argv){
    int i = 0;
    if (argc < 3) {exit(-1);}
    Heap h(atoi(argv[1]));
    Gambler* g[] = {new Human(h, atoi(argv[2]), "Human"), new Comp(h, atoi(argv[2]), "Computer")};
    while (g[i]->query() < h.get_max()){
        g[i]->move();
        if (++i > 1){
            i = 0;
        }
    }
    std::cout << "WINNER";
    delete g[0];
    delete g[1];
}