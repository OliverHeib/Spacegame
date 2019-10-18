
output: ../obj/spacegame.o
	gcc spacegame.o -lncurses -o ../bin/spacegame

../obj/spacegame.o: spacegame.c
	gcc -c spacegame.c -lncurses -o ../obj/spacegame.o

clean:
	rm *.o spacegame