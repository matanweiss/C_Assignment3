all: isort txtfind

isort: isort.c
	gcc -Wall -g -o isort isort.c

txtfind: txtfind.c
	gcc -Wall -g -o txtfind txtfind.c

clean:
	rm txtfind isort