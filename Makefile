CC = gcc
EXECUTABLE = main

all:
	$(CC) gamecell.c game.c main.c -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) *.tar.gz *.o  Docs

dist:
	mkdir GameOfLife && cp gamecell.c gamecell.h game.c game.h main.c GameOfLife && tar -czvf GameOfLife.tar.gz GameOfLife && rm -rf GameOfLife



docs:
	doxygen
	xdg-open Docs/html/index.html



exec:
	./$(EXECUTABLE)
