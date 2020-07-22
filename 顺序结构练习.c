#include<stdio.h>
#include<stdlib.h>
#define Maxsize 30
struct string
{
	char data[Maxsize];
	int curlen;
};
//全局变量//

//函数声明//

struct string substr(struct string s,int pos,int len);
struct string Concat(struct string s,struct string t);
struct string Replace(struct string s,int pos,int len,struct string t);
struct string add(struct string s,char *a);
int main()
{
	struct string s1,s2,s3;
	s1.curlen=assign(s1.data,"I am a good student");
	s2.curlen=assign(s2.data,"teacher");
	s3.curlen=assign(s3.data,"yes");
	printf("%d  %d  %d\n",s1.curlen,s2.curlen,s3.curlen);
	struct string str;
	str=substr(s1,8,4);
	printf("Substr(s1,8,4)=");
	puts(str.data);
	printf("Substr(s2,2,1)=");
	str=substr(s2,2,1);
	puts(str.data);
	str=add(s1,"B");
	printf("Index(s1,'B')=");
	puts(str.data);
	printf("s1.curlen=%d\n",s1.curlen);
	str=add(s3,"s");
	printf("Index(s3,'s')=");
	puts(str.data);
	printf("s3.curlen=%d\n",s3.curlen);
	str=Replace(s1,13,7,s2);
	printf("Replace(s1,13,7)=");
	puts(str.data);
	printf("s1和s2连接后\n");
	str=Concat(s1,s2);
	puts(str.data);
	printf("substr(s1,6,6)=");
	str=substr(s1,6,6);
	puts(str.data);
	printf("substr(s2,1,3)=");
	str=substr(s2,1,3);
	puts(str.data);
	printf("Concat(s3,substr(s2,1,3))=");
	str=Concat(s3,substr(s2,1,3));
	puts(str.data);
	printf("Concat(substr(s1,6,6),Concat(s3,substr(s2,1,3))=");
	str=Concat(substr(s1,6,6),Concat(s3,substr(s2,1,3)));
	puts(str.data);
}
int assign(char *s,char *t)
{
	int i;
	for(i=0;t[i];i++)
	{
		s[i]=t[i];
	}
	return i;
}
struct string substr(struct string s,int pos,int len)
{
	//printf("s->curlen=%d\npos=%d\n",s->curlen,pos);
	if(pos<1||pos>s.curlen||len<0||len>s.curlen-pos+1)
	{
		printf("位置填写错误\n");
		 exit(1);
	}
	struct string str;
	int i;
	for(i=0;i+1<=len;i++)
	{
		str.data[i]=s.data[pos-1+i];
	}
	str.data[i]='\n';
	str.curlen=i;
	return str;
}
struct string add(struct string s,char *a)
{
	int i;
	if(s.curlen==Maxsize-1)
	{
		printf("串已满\n");
		exit(1);
	}
	s.data[s.curlen]=*a;
	s.data[s.curlen+1]='\0';
	s.curlen++;
	return s;
}
struct string Replace(struct string s,int pos,int len,struct string t)
{
	if(pos<1||pos>s.curlen||len<0||len>s.curlen-pos+1)
	{
		printf("位置填写错误\n");
		exit(1);
	}
	int i;
	for(i=0;i+1<=len&&t.data[i]!='\0';i++)
	{
		s.data[pos-1+i]=t.data[i];
	}
	return s;
}
struct string Concat(struct string s,struct string t)
{
	int i;
	for(i=0;t.data[i]!='\0'&&s.curlen+i<=Maxsize-1;i++)
	{
		s.data[s.curlen+i]=t.data[i];
	}
	s.data[s.curlen+i]='\0';
	s.curlen=s.curlen+i;
	return s;
}
