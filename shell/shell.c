#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFF_SIZE 1<<10

int redir_flag = -1;
char BUFF_LINE[BUFF_SIZE];
char *args[10];
void read_input();
int issep(char,int);
int parse_input(); 

int main()
{
	int ret_status;
	int nargs;
	size_t pid;
	while(1) {
		write(1,"usr@Gnu$ ", 10);
		read_input();
		nargs = parse_input();
		if (nargs==0) continue;
		if ( (pid = fork()) ) { // parent
			pid = wait(&ret_status);
        } else { // child
			if( execvp(args[0], args)) {
                _exit(1);
            }
        }
	}
//	write(1,">EnD\n",5);
}

// copy a line from stdin to BUFF_LINE[]
void read_input()
{
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
	for(i = 0,p= BUFF_LINE; *p != '\0'; i++) { // loop moves through string until '\0' is reached
		for( a = p; issep(*p,i); p++) //loop moves through string until a sep is reached
			;
		if( *p !='\0')
			*p++ = '\0';
		args[i] = a;
	}
	args[i] = NULL;
	return i;
}
int issep(char ch, int i)
{
/*	int r;
	switch(ch) {
		case '\0':
			r = 0;
			break;
		case ' ':
			r = 0;
			break;
		case '>':
			*(&redir_flag) = i;
			r =0;
			break; 
		default :
			r =1;
			break;
	}*/
	if( ch == '\0'|| ch == ' ' )
		return 0;
	else 
		return 1; 
}
