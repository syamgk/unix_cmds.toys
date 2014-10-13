#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 2<<9

int main(argc, argv)
	int argc;
	char* argv[];
{
	char buf[SIZE];
	int n;
	int pid;
	if( argc = 1) { // need to edit
		n = read(0, buf,SIZE);
		printf("%d\n",n);
	}
	
	
}
		
