G = g++
FLAGS = -Wall -Werror -ansi -pedantic

all: clean makebin rshell ls

makebin:
	mkdir bin

rshell:
	$(G) $(FLAGS) src/rshell.cpp -o bin/rshell

ls:
	$(G) $(FLAGS) src/ls.cpp -o bin/ls

clean:
	rm -rf bin
