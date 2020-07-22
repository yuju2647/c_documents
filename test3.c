#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
	int *a;
	test(a);
	printf("%d\n",*a);
}
int test(int *b)
{
	b=(int *)malloc(sizeof(int));
	*b=2;
	return 0;
}
