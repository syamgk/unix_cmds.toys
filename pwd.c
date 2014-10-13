#include<unistd.h>
// prints current working Dir
int main()
{
	char *dir =	get_current_dir_name();
	printf("%s\n",dir);
	if(dir == NULL ) perror();
	return 0;
}
