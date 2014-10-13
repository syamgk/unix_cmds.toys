#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define BUFF_SIZE 1<<10

char BUFF_LINE[BUFF_SIZE];
char *args[10];
void read_input();
int issep(char a);
int parse_input(); 

main()
{
	int *ret_status;
	int i,nargs;
	size_t pid;
	while(1) {
		read_input();
		nargs = parse_input();
		if (nargs==0) continue;
		if (!strcmp(args[0], "exit" )) exit(0); //for exit
		if (!strcmp(args[0], "clear" )) write(1,"\x1b[H\x1b[J",6); //for clear
		if (pid = fork()){
  //          printf("Waiting for child (%d)\n", pid);
            pid = wait(ret_status);
//            printf("Child (%d) finished\n", pid);
        } else {
            if( execvp(args[0], args)) {
                puts(strerror(errno));
                exit(127);
            }
        }
//		for( i = 0; i<nargs; i++)
//			printf("%s\n",args[i]);
	}
//	write(1,">EnD\n",5);
}

// copy a line from stdin to BUFF_LINE[]
void read_input()
{
	char *word;
	char *ptr = BUFF_LINE;
	while(read(STDIN_FILENO, ptr, 1) > 0 && *ptr != '\n')
		ptr++;
	*ptr = '\0';
}
// return: no of args present in queue and copy arguments to args[] 
int parse_input()
{
	char *a;
	char *p;//cursor
	int i;
	for(i = 0,p= BUFF_LINE; *p != '\0'; i++) {
		for( a = p; issep(*p); p++)
			;
		if( *p !='\0')
			*p++ = '\0';
		args[i] = a;
	}
	return i;
}
int issep(char ch)
{
	if( ch == '\0'|| ch == ' ' )
		return 0;
	else 
		return 1;
}
