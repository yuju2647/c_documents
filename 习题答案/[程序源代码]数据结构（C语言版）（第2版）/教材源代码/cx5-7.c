#include <stdio.h>
#include <string.h>
#define  MAXSIZE 81
typedef  struct
{   
int len;
   char ch[MAXSIZE];
��SEQSTRING;
void  ComStrMax(SEQSTRING *s, SEQSTRING *t)  /*��s�ʹ�t��һ��������Ӵ�*/
{
  int position=0,maxlen=0,i=0,j,k,length;      /*i��Ϊɨ��s��ָ��*/
  while (i<s->len)
 ��
   j=0��                        /*��j��Ϊɨ��t��ָ��*/
   while (j<t->len)
  ��
     if(s->ch[i]==t->ch[j]��    /*��һ���Ӵ�,����s�е����Ϊi������Ϊlength*/
     ��
         length=1;
         for (k=l;s->ch[i+k]==t->ch[j+k];k++)
           length++;
         if(length>maxlen)    /*���ϴ󳤶��߸���position��maxlen*/
        ��
            position=i;
            maxlen=1ength;
         ��
         j+=length;          /*����ɨ��t�е�j+length�ַ�֮����ַ�*/
       ��
      else
        j++
    ��
    i++         /*����ɨ��s�е�i�ַ�֮����ַ�*/
��
  printf("\n�ַ���'%s'��'%s'��������Ӵ���",s->ch,t->ch);
  for (i=0;i<maxlen;i++)
   printf(" %c",s->ch[position+i]����
}
main()
{
    SEQSTRING *str,*strl;
    printf(" �����һ���ַ�����"����
    scanf("%s",str->ch)��
    str->len=strlen(str->ch)��
    printf("����ڶ����ַ�����")��
    sconf("%s",strl->ch)��
    strl->len=Lenstr(strl->ch)��
    comStrMax(r,r1);
}
