#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 2<<9
void print_dir(char *crnt_dir);
// pass argv[1] to print_dir if present else pass '.'
int main(int argc, char* argv[])
{
	if( argc == 1) { print_dir("."); }
	else { print_dir(argv[1]); }
	return 0;
}
// list subdirectories recursively 
void print_dir(char *crnt_dir)
{
	int i = 0;
	DIR *dir;
	struct dirent *dp;
	char *dir_names[100];
	char nxt_dir[SIZE];
	char tmp[SIZE];
	if( (dir = opendir(crnt_dir)) == 0) {
		perror(crnt_dir);
		exit(1);
	}
	printf("%s:\n",crnt_dir);
// keeping current_dir in dir_names[0] 
	int len = strlen(crnt_dir);
	dir_names[0] = tmp;		//malloc(len+1);
	strcpy(dir_names[0],crnt_dir);
	strcat(dir_names[0],"/");
// prints filenames in current dir except hidden files
	while( (dp = readdir(dir)) != 0) {
		if(dp->d_name[0] != '.'){
			printf("%s\t",dp->d_name);
			if(dp->d_type == 4) 
				dir_names[++i] = dp->d_name;
		}
	}
	printf("\n");
// recurse into subdir if present
	while(i >0) {
		printf("\n");
	//	nxt_dir = malloc( strlen(dir_names[0]) + strlen(dir_names[i]) );
		strcpy(nxt_dir,dir_names[0]);
		strcat(nxt_dir,dir_names[i--]);
		print_dir(nxt_dir);
	//	free(nxt_dir);
	}
}
