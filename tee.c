#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
int FD_BUFF[100]; // file descriptor buffer
int main(int argc,char **argv)
{
	int i;
	int n;
	char buf[2<<9];
	int *fd = FD_BUFF;
	if (argc > 1) {
		for(i=0; i< argc; i++)
		*(fd+i) = open(argv[i+1],O_RDWR | O_CREAT | O_TRUNC,0644);
	}

	while ((n = read(0,buf,2<<9)) > 0) {
		write(1,buf,n);
		if(argc >1) {
			for(i=0; i< argc; i++)
				write(*(fd+i),buf,n);
		}
	}
	return 0;
}

