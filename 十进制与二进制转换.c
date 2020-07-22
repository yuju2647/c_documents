#include<stdio.h>
#define MAXSIZE 100
int main()
{
	char binary[MAXSIZE];
	int n,decimal;
	/*while(1)
	{
		printf("decimal=");
		scanf("%d",&decimal);
		n=decimaltobinary(binary,decimal);
		printf("turn to binary£º");
		for(;n>=0;n--)
		putchar(binary[n]);
		printf("\n\n");
	}*/
	gets(binary);
	decimal=binarytodecimal(binary);
	printf("decimal= %d\n",decimal);
}
int decimaltobinary(char *s,int decimal)
{
	int i=0;
	int temp;
	while(decimal)
	{
		temp=decimal%2;
		s[i++]=temp+48;
		decimal/=2;
	}
	return --i;
}
int binarytodecimal(char *s)
{
	int i,n;
	for(n=0;s[n];n++)
	{}
	int decimal=0;
	n--;
	for(i=0;n>=0;i++,n--)
	{
		decimal+=(s[i]-48)*two(n);
	}
	return decimal;
}
int two(int n)
{
	int i,s=1;
	for(i=1;i<=n;i++)
	s*=2;
	return s;
}
