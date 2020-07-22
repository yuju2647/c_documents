#include <stdio.h>
#define MAXSIZE 8        /*为了测试方便，把字符串最大长度MAXSIZE的值设为8*/
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

void ConcatStr (SEQSTRING S,SEQSTRING T1,SEQSTRING T2) /*字符串连接函数*/
{
int i,n=MAXSIZE;                /*n为最长字符数*/
   if(T1.len+T2.len<n)            /*第一种情况*/ 
   {
for(i=0;i<T1.len;i++)
         S.ch[i]=T1.ch[i];
       for(i=0;i<T2.len;i++)
         S.ch[T1.len+i]=T2.ch[i];
         S.len=T1.len+T2.len;
         S.ch[S.len]='\0';             /*最后一个字节存放字符串结束标志*/
   }
   else if(T1.len<n)                    /*第二种情况*/
   {
for(i=0;i<T1.len;i++)
         S.ch[i]=T1.ch[i];
      for(i=0;T1.len+i<n;i++)
         S.ch[T1.len+i]=T2.ch[i];
         S.ch[n]='\0';
         S.len=n;
   }
   else                                   /*第三种情况*/
   {
for(i=0;i<n;i++)
       S.ch[i]=T1.ch[i];
       S.ch[n]='\0';
       S.len=n;
   }
printf("连接后的字符串为：\n");
puts(S.ch);
}

main()
{
SEQSTRING S,T1,T2;
int i,l;
S.len=0;
T1.len=0;
T2.len=0;
printf("请输入字符串1：\n");
gets(T1.ch); 
printf("请输入字符串2：\n");
gets(T2.ch);
for(i=0;T1.ch[i]!='\0';i++)
T1.len++;
for(i=0;T2.ch[i]!='\0';i++)
T2.len++;
ConcatStr (S,T1,T2); /*调用字符串连接函数*/
}  
//程序运行结果：
//请输入字符串1：        /*第一种情况对应的结果*/
//abcd
//请输入字符串2：
//123
//连接后的字符串为：
//abcd123

//请输入字符串1：        /*第二种情况对应的结果*/
//abcdef
//请输入字符串2：
//123
//连接后的字符串为：
//abcdef12

//请输入字符串1：        /*第三种情况对应的结果*/
//abcdefghi
//请输入字符串2：
//123
//连接后的字符串为：
//abcdefgh
