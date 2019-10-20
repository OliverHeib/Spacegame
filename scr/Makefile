
output: ../obj/main.o ../obj/ncursesExtentions.o
	gcc ../obj/main.o ../obj/ncursesExtentions.o -lncurses -o ../bin/spacegame

../obj/main.o: main.c
	gcc -c main.c -lncurses -o ../obj/main.o

../obj/ncursesExtentions.o: ncursesExtentions.c
	gcc -c ncursesExtentions.c -lncurses -o ../obj/ncursesExtentions.o

clean:
	rm ../obj/*.o ../bin/spacegame