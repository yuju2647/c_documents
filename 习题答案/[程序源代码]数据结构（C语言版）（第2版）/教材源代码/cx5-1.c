#include <stdio.h>
#define MAXSIZE 100
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;
int LenStr(SEQSTRING S)
{ 
return (S.len);
}
main()
{
SEQSTRING S;
int i,l;
S.len=0;
printf("请输入字符串！\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
l=LenStr(S);//*/
printf("字符串长度为：%d\n",l);
}
//程序运行结果：
//请输入字符串！
//china
//字符串长度为：5
