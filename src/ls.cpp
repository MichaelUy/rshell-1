#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
* This is a BARE BONES example of how to use opendir/readdir/closedir.
* Notice that there is no error checking on these functions.
* You MUST add error checking yourself.
*/

int main() {
	char dirName[] = ".";
	DIR* dirp = opendir(dirName);
	if(dirp == NULL) {
		perror("opendir");
		exit(1);
	}
	dirent* direntp;
	while ((direntp = readdir(dirp))) {
		if(direntp == NULL) {
			perror("readdir");
			exit(1);
		}

		struct stat status;
		if(stat(direntp->d_name, &status) == -1) {
			perror("stat");
			exit(1);
		}
		// use stat here to find attributes of file
		cout << direntp->d_name << endl;
	}

	if(closedir(dirp) == -1) {
		perror("closedir");
		exit(1);
	}

	cout << endl;
	return 0;
}

//       int stat(const char *path, struct stat *buf);
//       int fstat(int fd, struct stat *buf);
//       int lstat(const char *path, struct stat *buf);
