#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
int main(argc, argv)
	int argc;
	char* argv[];
{
	int pid;
	while(--argc) {
		pid = atoi(argv[argc]);
		if(kill(pid, SIGKILL) == -1) {
			perror(argv[argc]);
			exit(1);
		}
	}
	return 0;
}

