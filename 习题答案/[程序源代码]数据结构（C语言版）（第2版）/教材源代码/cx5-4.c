#include <stdio.h>
#define MAXSIZE 100
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;
int EqualStr(SEQSTRING S,SEQSTRING T)
{
int i=0;
 if(S.len!=T.len)
      return(0);
 else
   for(i=0;i<S.len;i++)
    if (S.ch[i]!=T.ch[i])
      return(0);
    else
      return(1);
}
main()
{
SEQSTRING S1,S2;
int i,l;
S1.len=0;
S2.len=0;
printf("请输入字符串1:\n");
gets(S1.ch);
printf("请输入字符串2:\n");
gets(S2.ch);
for(i=0;S1.ch[i]!='\0';i++)
S1.len++;
for(i=0;S2.ch[i]!='\0';i++)
S2.len++;
l=EqualStr(S1,S2);
printf("字符串是否相等的取值为（1为相等，0为不相等）： %d\n",l);
}
//程序运行结果：
//请输入字符串1:
//abcd
//请输入字符串2:
//abcd
//字符串是否相等的取值为（1为相等，0为不相等）：1
//当输入的字符串长度不等或对应位置的字符不同时，字符串是否相等的取值为“0”
