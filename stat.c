#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
int main( int argc, char *argv[])
{
	struct stat sbuf;
	assert(argv[1] != 0);
	if( stat(argv[1],&sbuf)== -1) {
		perror(argv[1]);
		exit(0);
	}
	printf("  File: `%s\'\n",argv[1]);
	printf("  Size: %d\t\tBlocks: %d\tIO Block:%d\n",(long int)sbuf.st_size,(long)sbuf.st_blocks,(long int)sbuf.st_blksize);
	printf("Device: %lld\t\tInode: %ld\tLinks: %d\n",(long long)sbuf.st_dev,(long int)sbuf.st_ino,(int)sbuf.st_nlink);
	printf("Access: (%o)\t Uid: ( %d)\t Gid: ( %d)\n",(unsigned int)sbuf.st_mode,(int)sbuf.st_uid,(int)sbuf.st_gid);
	printf("Access: %ld:%s",(long int )sbuf.st_atime,ctime(&sbuf.st_atime));
	printf("Modify: %ld:%s",(long int )sbuf.st_mtime,ctime(&sbuf.st_mtime));
	printf("Change: %ld:%s",(long int )sbuf.st_ctime,ctime(&sbuf.st_ctime));
	return 0;
}
