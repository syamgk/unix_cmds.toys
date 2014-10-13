#include <unistd.h>
#include <string.h>
#define BUFF_SIZE 2<<9
void read_input(void);
char* upto_(char* str);
char BUFF_LINE[BUFF_SIZE];
// pipe cmd as arg
int main(int argc,char *argv[])
{
	read_input();
	printf("%s\n",BUFF_LINE);
	char* fst_arg;
	char* scnd_arg;
	fst_arg = BUFF_LINE;
	scnd_arg = strstr(BUFF_LINE,"|");
	*scnd_arg = '\0';
	while ( *scnd_arg ==' ' || *scnd_arg == '\0' || *scnd_arg == '\t' ) 
		scnd_arg++;
//	strcpy(fst_arg,argv[1]);
	printf("%s\n",fst_arg);
	printf("%s\n",scnd_arg);
	char fst[10];
	strcpy(fst,upto_(fst_arg));
	int p[2];
	pipe(p);
	if(fork() == 0) { //child 
		close(1);
		dup(p[1]);
		close(p[0]);
		execlp(fst, fst_arg,(char*)0);
	}
	else { // parent
		close(0);
		dup(p[0]);
		close(p[1]);
		execlp(scnd_arg, scnd_arg,(char*)0);
	}
}
// copy a line from stdin to BUFF_LINE[]
void read_input()
{
	char *ptr = BUFF_LINE;
	while(read(STDIN_FILENO, ptr, 1) > 0 && *ptr != '\n')
		ptr++;
	*ptr = '\0';
}
char* upto_(char* str)
{
	int i = 0;
	char a[10];
	for(i=0; *str != ' '&& *str != '\0';str++,i++)
		a[i] = *str;
	a[i] = '\0';
	printf("%s\n",a);
	return a;
}
