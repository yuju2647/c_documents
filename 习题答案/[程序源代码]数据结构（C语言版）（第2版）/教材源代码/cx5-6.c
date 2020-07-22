#include <stdio.h>
#define MAXSIZE 20
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

DelStr(SEQSTRING S,int i,int len)
{
int j;
  if(i>=S.len)                     /*删除子串的位置值超过字符串长度的值*/
  {
printf("删除位置错误!\n");
    return;
  }
  else if(i+len>S.len)
  {
printf("删除的子串太长!\n");   /*要删除的子串长度大于可删除的字符总长度*/
    return;
  }
  else                         /*正常删除子串的情况*/
  {
j=i;
    while(S.ch[j-1+len]!='\0')     /*把要删除子串后的字符串前移len个位置*/
    { 
S.ch[j-1]=S.ch[j-1+len];
	      j++;
    }
    S.len=S.len-len;             /*修改字符串长度*/
    S.ch[S.len]='\0';             /*存放字符串结束标志*/ 
    printf("删除子串后的字符串为:\n");
puts(S.ch);
  }
}

main()
{
SEQSTRING S;
int i,j;
i=0;
j=0;
S.len=0;
printf("请输入字符串S:\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
printf("请输入删除子串的起始位置i和长度j:");  
scanf("%d,%d",&i,&j);
DelStr(S,i,j);                /*调用删除子串函数*/
}
//程序运行结果：
//请输入字符串S:
//abcdefg
//请输入删除子串的起始位置i和长度j: 3,2
//删除子串后的字符串为:
//abefg
//如果输入字符串S的值为:abcdefg,删除位置i为8,则会输出“删除位置错误!”的提示
