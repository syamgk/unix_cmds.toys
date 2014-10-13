#include <unistd.h>

int main()
{
	int p[2];
	pipe(p);
	if(fork() == 0) { //child (doing first command and pass o/p through pipe)
		close(1);
		dup(p[1]);
		close(p[0]);
		execlp("ls","ls",(char*)0);
	}
	else { // parent (recieved o/p of child from pipe)
		close(0);
		dup(p[0]);
		close(p[1]);
		execlp("wc","wc",(char*)0);
	}
}
