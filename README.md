#rshell

###Summary:
A program that can implement basic features of the command shell.

###How to install and run the program:
Open a terminal and type:
* `git clone https://github.com/cyang032/rshell.git`
* `cd rshell`
* `make`
* `bin/rshell`

###Known Bugs:
1. Cannot handle whitespace-only input.
2. Comments and flags work only if the other is never inputted during that program run.
3. Cannot handle `;`.
4. Cannot handle connectors.
6. Cannot handle symbols.
7. Segmentation fault on ENTER and if `#` is the first non-whitespace input.
