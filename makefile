build/mycat: obj/mycat.o
	gcc -Wall -o build/mycat obj/mycat.o

obj/mycat.o: main.c
	gcc -Wall -c -o obj/mycat.o main.c

.PHONY: clean

clean:
	rm -f obj/*