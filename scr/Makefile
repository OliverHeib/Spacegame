
output: ../obj/main.o
	gcc ../obj/main.o -lncurses -o ../bin/spacegame

../obj/main.o: main.c
	gcc -c main.c -lncurses -o ../obj/main.o

clean:
	rm ../obj/*.o ../bin/spacegame