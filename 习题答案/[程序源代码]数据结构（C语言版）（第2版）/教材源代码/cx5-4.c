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
printf("�������ַ���1:\n");
gets(S1.ch);
printf("�������ַ���2:\n");
gets(S2.ch);
for(i=0;S1.ch[i]!='\0';i++)
S1.len++;
for(i=0;S2.ch[i]!='\0';i++)
S2.len++;
l=EqualStr(S1,S2);
printf("�ַ����Ƿ���ȵ�ȡֵΪ��1Ϊ��ȣ�0Ϊ����ȣ��� %d\n",l);
}
//�������н����
//�������ַ���1:
//abcd
//�������ַ���2:
//abcd
//�ַ����Ƿ���ȵ�ȡֵΪ��1Ϊ��ȣ�0Ϊ����ȣ���1
//��������ַ������Ȳ��Ȼ��Ӧλ�õ��ַ���ͬʱ���ַ����Ƿ���ȵ�ȡֵΪ��0��
