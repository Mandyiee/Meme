all: create

create: main.c
	gcc main.c -o create

clean:
	rm -f create