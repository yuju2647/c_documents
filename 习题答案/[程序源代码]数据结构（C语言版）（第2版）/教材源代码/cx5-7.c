#include <stdio.h>
#include <string.h>
#define  MAXSIZE 81
typedef  struct
{   
int len;
   char ch[MAXSIZE];
｝SEQSTRING;
void  ComStrMax(SEQSTRING *s, SEQSTRING *t)  /*求串s和串t的一个最长公共子串*/
{
  int position=0,maxlen=0,i=0,j,k,length;      /*i作为扫描s的指针*/
  while (i<s->len)
 ｛
   j=0；                        /*由j作为扫描t的指针*/
   while (j<t->len)
  ｛
     if(s->ch[i]==t->ch[j]）    /*找一个子串,其在s中的序号为i，长度为length*/
     ｛
         length=1;
         for (k=l;s->ch[i+k]==t->ch[j+k];k++)
           length++;
         if(length>maxlen)    /*将较大长度者赋给position与maxlen*/
        ｛
            position=i;
            maxlen=1ength;
         ｝
         j+=length;          /*继续扫描t中第j+length字符之后的字符*/
       ｝
      else
        j++
    ｝
    i++         /*继续扫描s中第i字符之后的字符*/
｝
  printf("\n字符串'%s'和'%s'的最长公共子串：",s->ch,t->ch);
  for (i=0;i<maxlen;i++)
   printf(" %c",s->ch[position+i]）；
}
main()
{
    SEQSTRING *str,*strl;
    printf(" 输入第一个字符串："）；
    scanf("%s",str->ch)；
    str->len=strlen(str->ch)；
    printf("输入第二个字符串：")；
    sconf("%s",strl->ch)；
    strl->len=Lenstr(strl->ch)；
    comStrMax(r,r1);
}
