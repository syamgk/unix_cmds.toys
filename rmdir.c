#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
// delets a directory if it is empty
int main(int argc, char **argv) 
{
	int stat = rmdir(*(argv+1));
	if(stat != 0) perror(argv[1]);
	return stat;
}


