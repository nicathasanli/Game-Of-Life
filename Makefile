CC = gcc
EXECUTABLE = main

all:
	$(CC) gamecell.c game.c main.c -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) *.tar.gz *.o  Docs

dist:
	mkdir GameOfLifeStep1 && cp gamecell.c gamecell.h game.c game.h main.c GameOfLifeStep1 && tar -czvf GameOfLifeStep1.tar.gz GameOfLifeStep1 && rm -rf GameOfLifeStep1



docs:
	doxygen
	xdg-open Docs/html/index.html



exec:
	./$(EXECUTABLE)
