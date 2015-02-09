#rshell

###Summary:
A program that can implement basic features of the command shell.

###How to install and run the program:
1. hw0: Open a terminal and type:
  * `git clone https://github.com/cyang032/rshell.git`
  * `cd rshell`
  * `make`
  * `bin/rshell`

2. hw1: Open a terminal and type:
  * `git clone https://github.com/cyang032/rshell.git`
  * `cd rshell`
  * `git checkout hw1`
  * `make`
  * `bin/ls`

###Known Bugs:
1. hw0:
  * Cannot handle whitespace-only input.
  * Comments and flags work only if the other is never inputted during that program run.
  * Cannot handle `;`.
  * Cannot handle connectors.
  * Cannot handle symbols.
  * Segmentation fault on ENTER and if `#` is the first non-whitespace input.

2. hw1:
  * Cannot handle multiple flags.
  * Cannot handle the `-a` flag.
  * Cannot handle the `-R` flag.
  * Cannot handle optional file parameters.
  * Cannot print in alphabetical order.
  * For the `-l` flag, does not print user or group members correctly, and does not print the time.
