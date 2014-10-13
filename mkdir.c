#include <sys/stat.h>
#include <sys/types.h>
// creates a directory
int main(int argc, char **argv) 
{
	int stat = mkdir(*(argv+1), 0777);
	if(stat != 0) perror(argv[1]);
	return stat;
}


