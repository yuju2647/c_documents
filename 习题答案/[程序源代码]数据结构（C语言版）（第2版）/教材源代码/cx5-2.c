#include <stdio.h>
#define MAXSIZE 8        /*Ϊ�˲��Է��㣬���ַ�����󳤶�MAXSIZE��ֵ��Ϊ8*/
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

void ConcatStr (SEQSTRING S,SEQSTRING T1,SEQSTRING T2) /*�ַ������Ӻ���*/
{
int i,n=MAXSIZE;                /*nΪ��ַ���*/
   if(T1.len+T2.len<n)            /*��һ�����*/ 
   {
for(i=0;i<T1.len;i++)
         S.ch[i]=T1.ch[i];
       for(i=0;i<T2.len;i++)
         S.ch[T1.len+i]=T2.ch[i];
         S.len=T1.len+T2.len;
         S.ch[S.len]='\0';             /*���һ���ֽڴ���ַ���������־*/
   }
   else if(T1.len<n)                    /*�ڶ������*/
   {
for(i=0;i<T1.len;i++)
         S.ch[i]=T1.ch[i];
      for(i=0;T1.len+i<n;i++)
         S.ch[T1.len+i]=T2.ch[i];
         S.ch[n]='\0';
         S.len=n;
   }
   else                                   /*���������*/
   {
for(i=0;i<n;i++)
       S.ch[i]=T1.ch[i];
       S.ch[n]='\0';
       S.len=n;
   }
printf("���Ӻ���ַ���Ϊ��\n");
puts(S.ch);
}

main()
{
SEQSTRING S,T1,T2;
int i,l;
S.len=0;
T1.len=0;
T2.len=0;
printf("�������ַ���1��\n");
gets(T1.ch); 
printf("�������ַ���2��\n");
gets(T2.ch);
for(i=0;T1.ch[i]!='\0';i++)
T1.len++;
for(i=0;T2.ch[i]!='\0';i++)
T2.len++;
ConcatStr (S,T1,T2); /*�����ַ������Ӻ���*/
}  
//�������н����
//�������ַ���1��        /*��һ�������Ӧ�Ľ��*/
//abcd
//�������ַ���2��
//123
//���Ӻ���ַ���Ϊ��
//abcd123

//�������ַ���1��        /*�ڶ��������Ӧ�Ľ��*/
//abcdef
//�������ַ���2��
//123
//���Ӻ���ַ���Ϊ��
//abcdef12

//�������ַ���1��        /*�����������Ӧ�Ľ��*/
//abcdefghi
//�������ַ���2��
//123
//���Ӻ���ַ���Ϊ��
//abcdefgh
