chess: main.o realization.o
	gcc main.o realization.o -o chess
main.o: main.c header.h
	gcc -c main.c
realization.o: realization.c header.h
	gcc -c realization.c
clean:
	rm -f *.o chess


