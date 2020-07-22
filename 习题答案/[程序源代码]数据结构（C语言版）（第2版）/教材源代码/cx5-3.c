#include <stdio.h>
#define MAXSIZE 80
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

SEQSTRING  SubStr(SEQSTRING S,int i,int j)
{
SEQSTRING T;
   int k;
   if((i>=1) && (i<=S.len) && (j>=1) && (j<=S.len-i+1))
   {
for(k=0;k<=l;k++)
      T.ch[k]=S.ch[i+k-1];
     T.ch[j]='\0';
     T.len=j;
     printf("子串为：\n");
     puts(T.ch);
     return (T);
}
   else
       printf("开始位置或子串长度不合理！\n");
   return;
}

main()
{
SEQSTRING S,T1,T2;
int i,j,l;
S.len=0;
T1.len=0;
T2.len=0;
printf("请输入字符串！\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
printf("请输入子串起始位置i和子串长度j:\n");
scanf("%d,%d",&i,&j);
SubStr(S,i,j);
}
//程序运行结果：
//请输入字符串！
//abcdefghijkl
//请输入子串起始位置i和子串长度j:
//3,5
//子串为：
//cdefg
//请输入字符串！
//abcd
//请输入子串起始位置i和子串长度j:
//5,3
//开始位置或子串长度不合理！
