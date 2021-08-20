#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a=0;
	printf("%p\n",sbrk(0));
	sbrk(1024);
	printf("%p\n",sbrk(0));
	return 0;
}
