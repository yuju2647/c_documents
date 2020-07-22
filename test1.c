#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int a;
}T;
int main()
{
	char *s;
	test(s);
	puts(s); 
	T a; 
}
int test(char *a)
{
	a=(char *)malloc(sizeof(char));
	*a='b';
	return 0;
}

