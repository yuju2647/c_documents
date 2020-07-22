#include<stdio.h>
#define Maxsize 50
struct string
{
	char data[Maxsize];
	int curlen;
};
int main()
{
	struct string s,t;
	gets(s.data);
	s.curlen=calculate(s.data);
	gets(t.data);
	t.curlen=calculate(t.data);
	int i;
	i=locate(s.data,t.data);
	if(i==0)
	printf("无匹配\n");
	else
	{
		printf("\n有匹配\n");
		printf("子串在第 %d 个字符中出现\n",i);
	}
	
}
int locate(struct string *s,struct string *t)
{
	int i=0,j=0;
	while(i<=s->curlen-1&&j<=t->curlen-1)
	{
		if(s->data[i]==t->data[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j==t->curlen)
	return i-j+1;
	else if(i==s->curlen)
	return 0;
	return 0;
}
int calculate(struct string *s)
{
	int i;
	for(i=0;s->data[i]!='\0';i++)
	{}
	return i; 
}
