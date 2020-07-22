#include <stdio.h>
#define MAXSIZE 20    /*为方便验证算法而设定的值*/
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

void InsStr(SEQSTRING S,int i,SEQSTRING T)
{
int j;
  if(T.len<=0)                       /*子串为空*/
  {
printf("字符串为空!\n");
    return;
  }
  else if((i<=0)||(i>=S.len+1))   /*插入位置不对*/
  {
printf("插入位置不合理!\n");
    return;
  }
  else if (S.len+T.len>=MAXSIZE) /*子串太长*/
  {
printf("字符串长度越界!\n");
    return;
  }
  else                            /*插入运算*/
  {
for (j=S.len;j>=i;j--)   /*把串S中第i个字符之后的子串后移,以便插入串T*/
    { 
S.ch[j+T.len]=S.ch[j];/*此算法已经考虑到字符串结束标志移动问题*/
      S.ch[j]=''; }
      for(j=0;j<T.len;j++)     /*把串T插入到串S中第i个字符之后的位置*/
       S.ch[i+j]=T.ch[j];
     S.len=S.len+T.len;       /*修改串S的长度*/
     printf("插入子串后的字符串为:\n");
puts(S.ch);                
   }
}
main()
{
SEQSTRING string;
SEQSTRING S,T;
int i,j;
i=0;
S.len=0;
T.len=0;
printf("请输入字符串S和T:\n");
gets(S.ch);
gets(T.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
for(i=0;T.ch[i]!='\0';i++)
T.len++;
printf("请输入插入位置i:");
scanf("%d",&i);
InsStr(S,i,T);      /*调用插入函数*/
}
//程序运行结果：
//请输入字符串S和T:
//aaaaaaaa
//ss
//请输入插入位置i: 3
//插入子串后的字符串为:
//aaassaaaaa
//如果输入字符串S和T的值为:aaaaaaaa和ss,插入位置i为10,则会输出“输入位置不合理!”的提示
