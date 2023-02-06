all: genecode.c fileio.c code.c
	gcc genecode.c fileio.c code.c -o genecode

install:
	sudo cp genecode /usr/local/bin