#include <unistd.h>

int main()
{
	int p[2];
	pipe(p);
	if(fork() == 0) { //child 
		close(1);
		dup(p[1]);
		close(p[0]);
		execlp("ls","ls",(char*)0);
		if(fork() == 0 ) { //grand child
			close(p[0]);
			
	}
	else { // parent
		close(0);
		dup(p[0]);
		close(p[1]);
		execlp("wc","wc",(char*)0);
	}
//	write(1,"#",1);
}
