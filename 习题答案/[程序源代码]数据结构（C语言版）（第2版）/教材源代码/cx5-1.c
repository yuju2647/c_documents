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
printf("�������ַ�����\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
l=LenStr(S);//*/
printf("�ַ�������Ϊ��%d\n",l);
}
//�������н����
//�������ַ�����
//china
//�ַ�������Ϊ��5
