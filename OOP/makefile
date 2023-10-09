chess: chman.o chlib.o chess.cpp
	g++ -o chess chess.cpp chman.o chlib.o
chman.o: chman.h chman.cc
	g++ -c chman.cc -o chman.o
chlib.o: chlib.h chlib.cc chman.h
	g++ -c chlib.cc -o chlib.o
clean:
	rm *.o chess
