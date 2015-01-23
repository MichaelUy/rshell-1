#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>

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
		cout << '$';
		counter = 0;
		cin.getline(fullinput, 3333);
		if(fullinput == "exit") { break; }
		curr = strtok(fullinput, " ");
		while(curr != NULL)
		{
			cout << "Token: " << curr << endl;

			arr[counter] = curr;
			curr = strtok(NULL, " ");
			counter++;
			//word = strtok(NULL, ' ');
		}
		arr[counter] = NULL;
		runcmd(arr);
	}


//	while(1)
	{

//		if(input == "exit") { break; }
	}

//	for(int i = 0; i < inputlist.size(); i++)
//	{
		
//	}

	

//main
//helper1: run cmd
//helper2: connector logic (AND &&, OR ||, ;)
//
//

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

	//	char* testex[] = {'e', 'x', 'i', 't'};
	

		if(strcmp(argv[0], "exit") == 0) { exit(1); }

		if(-1 == execvp(argv[0], argv))
			perror("There was an error in execvp. ");
//
		return 0; //always end the child process after its done
		exit(1);	//figure out which one to use
	}
	else //we are in the parent
	{
		if (-1 == wait(0))      //error checking, `wait` should almost always be used
		{                       //in the parent immediately following `fork`
			perror("wait");
			exit(1);
		}
	}
	//you can do whatever the parent function needs to do here
}

/*

only character arrays/pointers/etc. for exec function

*/



