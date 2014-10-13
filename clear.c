#include <unistd.h>
int main()
{
	write(1, "\33[H\33[J",6);
	return 0;
} 
