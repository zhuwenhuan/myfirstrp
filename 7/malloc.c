#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	printf("pd is %p\n",sbrk(0));
	char *p=malloc(1024);
	if(p==NULL)
	{
		printf("malloc fail\n");
	}
	printf("pd is %p\n",sbrk(0));
	
	char *p1=malloc(1024);
	if(p1==NULL)
        {
                printf("malloc fail\n");
        }

	printf("pd is %p\n",sbrk(0));
	char *p2=malloc(1024);
	if(p2==NULL)
        {
                printf("malloc fail\n");
        }

	printf("pd is %p\n",sbrk(0));

	free(p);
	printf("pd is %p\n",sbrk(0));

	free(p1);
	free(p2);
	printf("pd is %p\n",sbrk(0));
	return 0;
}
