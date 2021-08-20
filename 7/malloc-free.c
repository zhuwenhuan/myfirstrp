#include<stdio.h>
#include<stdlib.h>
#define cahr char
#define MAX_ALLOCS 10000
#include<string.h>


int main(int argc,cahr *argv[])//1-分配内存块数量 2-每块的大小 3-释放的循环步长
{
	char *ptr[MAX_ALLOCS];
	int j;

	if(argc<3||strcmp(argv[1],"--help")==0)
	{
		printf("%s has some error!\n",argv[1]);
	}
	printf("the begin of the pd is %p\n",sbrk(0));
	int num=*argv[1]-'0';
	int blocksize=*argv[2]-'0';
	for(j=0;j<num;j++)
	{	
		ptr[j]=malloc(blocksize);
		if(ptr[j]==NULL)
		{
			printf("malloc fail\n");
			return 0;
		}
		printf("pb after %d time malloc is %p\n",j,sbrk(0));
	}
	//this is my array

	printf("free step is %d\n",*argv[3]-'0');
	for(int i=0;i<num;)
	{
		free(ptr[i]);
		i+=*argv[3]-'0';
		printf("after %d times free pb is %p\n",i,sbrk(0));

	}
//	exit(EXIT_SUCCESS);
	return 0;

}

