#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <cstdlib>

using namespace std;
using namespace boost;

vector<char*> getinput();
int runcmd(char** argv);

int main()
{
//	vector<char*> inputlist = getinput();

//	for(int i = 0; i < inputlist.size(); i++)
//	{
//		cout << inputlist.at(i) << ' ';
//	}

	char fullinput[3333];
//	fullinput = input;
	char* curr;
	char* arr[29000];
	int counter = 0;

	while(1)
	{
		cout << "$ ";
		counter = 0;
		cin.getline(fullinput, 3333);

//		if(strcmp(string(fullinput)), "exit") == 0) { exit(0); }

		char* s; //looking for instance of '#' or '\n'
		if(strchr(fullinput, '#') != NULL) //looking for # char
			s = strchr(fullinput, '#');
		else if(strchr(fullinput, '\n') != NULL) //looking for newline char
			s =  strchr(fullinput, '\n');

//		cout << string(fullinput) << endl;
//		if(string(fullinput) == "#" || string(fullinput) == "")
//			s = fullinput;
//		cout << endl << s << endl;

		if(s != NULL)
		{
//			cout << "\nhere\n";
			fullinput[s - fullinput + 1] = '\0';
//			fullinput = fullinput - s;
		}		
//		cout << fullinput << endl;

		curr = strtok(fullinput, " &	|#");

		if(strcmp(curr, "exit") == 0) { exit(0); } // looks for "exit" input
		//problem is that strtok will seg fault if this line is present,
		//even though the first strtok is called before this line

		//also, sometimes up to 3 times of "exit" input is required to
		//actually exit the program

		while(curr != NULL)
		{
//			cout << "Token: " << curr << endl;
			arr[counter] = curr;
			curr = strtok(NULL, " &	|#");
			counter++;
		}

		arr[counter] = NULL;
//		if(arr[0] != NULL)
			runcmd(arr);
	}

//main
//helper1: run cmd
//helper2: connector logic (AND &&, OR ||, ;)

	cout << endl;
	return 0;
}

int runcmd(char** argv)
{
	int pid = fork();

	if (pid == -1)
	{
		perror("fork"); //syscall to output error
		exit(1);
	}
	else if (pid == 0) //if it is the child process running
	{
		//do whatever the child should do

//		char* testex[] = {'e', 'x', 'i', 't'};
//		if(argv[0] != NULL && strcmp(argv[0], "exit") == 0) { exit(1); }

		if(-1 == execvp(argv[0], argv))
			perror("There was an error in execvp. ");

//		return 0;
		exit(1);
	}
	else //we are in the parent
	{
		if (-1 == wait(0)) //error checking, `wait` should almost always be used
		{                  //in the parent immediately following `fork`
			perror("wait");
			exit(1);
		}
	}
	//you can do whatever the parent function needs to do here
	return 0;
}
