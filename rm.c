#include <unistd.h>
#include <error.h>
#include <stdio.h>
// rm :removes the argument files given by calling unlink
int main(argc, argv)
	int argc; 
	char* argv[];
{
	while( --argc) {
		printf("removing ...%s\n",argv[argc]);
		if(unlink(argv[argc]) == 0)
			printf("%s :removed !\n",argv[argc]);
		else
			perror(argv[argc]);
	}
	return 0;
}

