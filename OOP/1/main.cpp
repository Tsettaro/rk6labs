#include "point.hpp"

// Перевод координат точки из полярной в декартову систему 
Point Point::polar(float radius, float f) {
	Point p(radius*cos(f), radius*sin(f));
	return p;
};

int main(int argc, char** argv) {
	float side = 5.0;
	float angle = 0.0;
	float pi = acos(-1.0);
	float radius;
	float deltaX = 1.0, deltaY = -1.0;
	Point vertex[8];
	int i = 0;
	// Проверка на количество аргументов
	if (argc > 3) {
		side = atof(argv[1]);
		deltaX = atof(argv[2]);
		deltaY = atof(argv[3]);
	} else{
		std::cout << "Invalid count of arguments\n";
		return -1;
	}

	// Проверка на расположение точки
	if (deltaX <= 0 || deltaY >= 0){
		std::cout << "Invalid coordinates of point\n";
		return -2;
	}

	radius = side*sqrt(4+2*sqrt(2))/2;

	while (i < 8){
		// Создание вершины восьмиугольника
		vertex[i] = Point::polar(radius,angle);
		angle+=(pi/4.0);
		i++;
	}
	do{
		// Вывод координат вершин восьмиугольника
		printf("Point %d: %f ; %f\n", i, vertex[i].getX()+deltaX, vertex[i].getY()+deltaY);
		i--;
	}while(i>0);
	return 0;
}
