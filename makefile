chess: main.o realization.o game.o
	gcc main.o realization.o game.o -o chess
main.o: main.c game.h figure.h
	gcc -c main.c
realization.o: realization.c header.h figure.h
	gcc -c realization.c
game.o: game.c game.h header.h figure.h
	gcc -c game.c
clean:
	rm -f *.o chess