#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	DIR *dir;
	struct dirent *dp;
	if( argc == 1) { argv[1] = ".";}
	if( (dir = opendir(argv[1])) == 0) {
		perror(argv[1]);
		exit(1);
	}
	while( (dp = readdir(dir)) != 0) {
		if(dp->d_name[0] != '.'){
			printf("%s\n",dp->d_name);
		}
	}
	return 0;
}

