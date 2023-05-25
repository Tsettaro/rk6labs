chess: chman.o chlib.o chess.cc
	g++ -o chess chess.cc chman.o chlib.o
chman.o: chman.h chman.cc
	g++ -c chman.cc -o chman.o
chlib.o: chlib.h chlib.cc chman.h
	g++ -c chlib.cc -o chlib.o
clean:
	rm *.o chess
