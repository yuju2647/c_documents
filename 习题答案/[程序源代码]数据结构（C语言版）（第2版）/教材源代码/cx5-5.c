#include <stdio.h>
#define MAXSIZE 20    /*Ϊ������֤�㷨���趨��ֵ*/
typedef struct
{
char ch[MAXSIZE];
int len;
}SEQSTRING;

void InsStr(SEQSTRING S,int i,SEQSTRING T)
{
int j;
  if(T.len<=0)                       /*�Ӵ�Ϊ��*/
  {
printf("�ַ���Ϊ��!\n");
    return;
  }
  else if((i<=0)||(i>=S.len+1))   /*����λ�ò���*/
  {
printf("����λ�ò�����!\n");
    return;
  }
  else if (S.len+T.len>=MAXSIZE) /*�Ӵ�̫��*/
  {
printf("�ַ�������Խ��!\n");
    return;
  }
  else                            /*��������*/
  {
for (j=S.len;j>=i;j--)   /*�Ѵ�S�е�i���ַ�֮����Ӵ�����,�Ա���봮T*/
    { 
S.ch[j+T.len]=S.ch[j];/*���㷨�Ѿ����ǵ��ַ���������־�ƶ�����*/
      S.ch[j]=''; }
      for(j=0;j<T.len;j++)     /*�Ѵ�T���뵽��S�е�i���ַ�֮���λ��*/
       S.ch[i+j]=T.ch[j];
     S.len=S.len+T.len;       /*�޸Ĵ�S�ĳ���*/
     printf("�����Ӵ�����ַ���Ϊ:\n");
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
printf("�������ַ���S��T:\n");
gets(S.ch);
gets(T.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
for(i=0;T.ch[i]!='\0';i++)
T.len++;
printf("���������λ��i:");
scanf("%d",&i);
InsStr(S,i,T);      /*���ò��뺯��*/
}
//�������н����
//�������ַ���S��T:
//aaaaaaaa
//ss
//���������λ��i: 3
//�����Ӵ�����ַ���Ϊ:
//aaassaaaaa
//��������ַ���S��T��ֵΪ:aaaaaaaa��ss,����λ��iΪ10,������������λ�ò�����!������ʾ
