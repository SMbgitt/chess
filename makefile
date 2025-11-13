chess: main.o realization.o game.o
	gcc main.o realization.o game.o -o chess
main.o: main.c game.h
	gcc -c main.c
realization.o: realization.c header.h
	gcc -c realization.c
game.o: game.c header.h game.h
	gcc -c game.c
clean:
	rm -f *.o chess