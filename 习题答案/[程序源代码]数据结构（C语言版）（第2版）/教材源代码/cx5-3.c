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
     printf("�Ӵ�Ϊ��\n");
     puts(T.ch);
     return (T);
}
   else
       printf("��ʼλ�û��Ӵ����Ȳ�����\n");
   return;
}

main()
{
SEQSTRING S,T1,T2;
int i,j,l;
S.len=0;
T1.len=0;
T2.len=0;
printf("�������ַ�����\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
printf("�������Ӵ���ʼλ��i���Ӵ�����j:\n");
scanf("%d,%d",&i,&j);
SubStr(S,i,j);
}
//�������н����
//�������ַ�����
//abcdefghijkl
//�������Ӵ���ʼλ��i���Ӵ�����j:
//3,5
//�Ӵ�Ϊ��
//cdefg
//�������ַ�����
//abcd
//�������Ӵ���ʼλ��i���Ӵ�����j:
//5,3
//��ʼλ�û��Ӵ����Ȳ�����
