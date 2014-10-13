#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int n,r_fd, w_fd;
	char buf[4];
	assert(argv[1] != NULL);
	assert(argv[2] != NULL);
	r_fd = open(argv[1],O_RDONLY); // read
	if(r_fd == -1) { // Error.
		perror(argv[1]);
	}
	w_fd = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644); // write
	if(r_fd == -1) { // Error.
		perror(argv[2]);
	}
	for(;(n = read(r_fd,buf,4))>0;write(w_fd,buf,n));
	return 0;
}

