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
  if(i>=S.len)                     /*ɾ���Ӵ���λ��ֵ�����ַ������ȵ�ֵ*/
  {
printf("ɾ��λ�ô���!\n");
    return;
  }
  else if(i+len>S.len)
  {
printf("ɾ�����Ӵ�̫��!\n");   /*Ҫɾ�����Ӵ����ȴ��ڿ�ɾ�����ַ��ܳ���*/
    return;
  }
  else                         /*����ɾ���Ӵ������*/
  {
j=i;
    while(S.ch[j-1+len]!='\0')     /*��Ҫɾ���Ӵ�����ַ���ǰ��len��λ��*/
    { 
S.ch[j-1]=S.ch[j-1+len];
	      j++;
    }
    S.len=S.len-len;             /*�޸��ַ�������*/
    S.ch[S.len]='\0';             /*����ַ���������־*/ 
    printf("ɾ���Ӵ�����ַ���Ϊ:\n");
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
printf("�������ַ���S:\n");
gets(S.ch);
for(i=0;S.ch[i]!='\0';i++)
S.len++;
printf("������ɾ���Ӵ�����ʼλ��i�ͳ���j:");  
scanf("%d,%d",&i,&j);
DelStr(S,i,j);                /*����ɾ���Ӵ�����*/
}
//�������н����
//�������ַ���S:
//abcdefg
//������ɾ���Ӵ�����ʼλ��i�ͳ���j: 3,2
//ɾ���Ӵ�����ַ���Ϊ:
//abefg
//��������ַ���S��ֵΪ:abcdefg,ɾ��λ��iΪ8,��������ɾ��λ�ô���!������ʾ
