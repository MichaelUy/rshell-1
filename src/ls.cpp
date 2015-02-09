#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
//#include <time.h>
#include <iostream>

using namespace std;

/*
* This is a BARE BONES example of how to use opendir/readdir/closedir.
* Notice that there is no error checking on these functions.
* You MUST add error checking yourself.
*/

int main(int argc, char** argv) {
	bool flagnone = false;
	bool flaga = false;
	bool flagl = false;
//	bool flagR = false;

	if(argc == 1) { flagnone = true; }
	else {
		

		flagl = true;
	}

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

		if(flagnone) {
			if(direntp->d_name[0] != '.') {
				cout << direntp->d_name << " ";
			}
		}
		else if(flagl) {
			if(direntp->d_name[0] == '.' && !flaga) {
				goto here;
			}

			struct stat status;
			if(stat(direntp->d_name, &status) == -1) {
				perror("stat");
				exit(1);
			}

			if(status.st_mode & S_IFDIR) { cout << "d"; }
			else { cout << "-"; }

			if(status.st_mode & S_IRUSR) { cout << "r"; }
			else { cout << "-"; }
			if(status.st_mode & S_IWUSR) { cout << "w"; }
			else { cout << "-"; }
			if(status.st_mode & S_IXUSR) { cout << "x"; }
			else { cout << "-"; }

			if(status.st_mode & S_IRGRP) { cout << "r"; }
			else { cout << "-"; }
			if(status.st_mode & S_IWGRP) { cout << "w"; }
			else { cout << "-"; }
			if(status.st_mode & S_IXGRP) { cout << "x"; }
			else { cout << "-"; }

			if(status.st_mode & S_IROTH) { cout << "r"; }
			else { cout << "-"; }
			if(status.st_mode & S_IWOTH) { cout << "w"; }
			else { cout << "-"; }
			if(status.st_mode & S_IXOTH) { cout << "x"; }
			else { cout << "-"; }

			cout << status.st_nlink << " ";
//			cout << oct;
		//	struct passwd* pass;
			cout << status.st_uid << " ";
		//	struct group *grp;
			cout << status.st_gid << " ";
			cout << status.st_size << " " << endl;
			
		}
//		cout << endl;
		here: ;
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
