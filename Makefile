G = g++
FLAGS = -Wall -Werror -ansi -pedantic

all: clean makebin rshell

makebin:
	mkdir bin

rshell:
	$(G) $(FLAGS) src/rshell.cpp -o ./bin/rshell

clean:
	rm -rf bin
