#include <stdio.h>        
#define MAXSIZE 80
typedef struct
{char ch[MAXSIZE];
int len;
}SEQSTRING;

SEQSTRING S,T1,T2,T;

SEQSTRING InputStr()                /*输入字符串*/
 { int i;
   T.len=0;
   printf("请输入字符串:\n");
   gets(T.ch);
   for(i=0;T.ch[i]!=’\0’;i++)
    T.len++;
   return T;
  }
void OutputStr(SEQSTRING T)      /*输出字符串*/
  { puts(T.ch);
  }

int LenStr(SEQSTRING T)                      /*求字符串长度*/
 { return (T.len);
  }
int EqualStr(SEQSTRING T1,SEQSTRING T2)  /*判字符串是否相等*/
{int i=0;
 if(T1.len!=T2.len)
    return(0);
 else
   for(i=0;i<T1.len;i++)
     if (T1.ch[i]!=T2.ch[i])
     return(0);
     else
     return(1);
}

SEQSTRING Concat(SEQSTRING T,SEQSTRING T1,SEQSTRING T2) /*联接字符串*/
{int i,n=MAXSIZE-1;
 if(T1.len+T2.len<n) /* */
    {for(i=0;i<T1.len;i++)
       T.ch[i]=T1.ch[i];
     for(i=0;i<T2.len;i++)
       T.ch[T1.len+i]=T2.ch[i];
       T.len=T1.len+T2.len;
       T.ch[T.len]='\0';
    }
 else if(T1.len<n)
   {for(i=0;i<T1.len;i++)
      T.ch[i]=T1.ch[i];
   for(i=0;T1.len+i<n;i++)
      T.ch[T1.len+i]=T2.ch[i];
   T.ch[n]='\0';
      T.len=T1.len+i;
   }
 else
  {for(i=0;i<n;i++)
   T.ch[i]=T1.ch[i];
   T.ch[n]='\0';
   T.len=n;
  }
return T;
}

SEQSTRING SubStr(SEQSTRING S,int i,int l)      /*取子串*/
  { SEQSTRING T;
    int k;
   if((i>=1) && (i<=S.len) && (l>=1) && (l<=S.len-i+1))
    {for(k=0;k<=l;k++)
     T.ch[k]=S.ch[i+k-1];
     T.ch[l]='\0';
     T.len=l;
     return (T);
     }
   else
    {printf("The length is no right!\n");
    T.len=0;
    return T;
    }
  }

SEQSTRING InsStr(SEQSTRING S,int i,SEQSTRING T)  /*插入字符串*/
  {int j;
  if(T.len<=0)
    {printf("字符串为空!\n");
     return;
    }
  else if((i<=0)||(i>S.len+1))
    {printf("插入位置有错误!\n");
      return;
    }
  else if (S.len+T.len>=MAXSIZE)
    {printf("插入串太长!\n");
      return;
    }
  else
    {for (j=S.len;j>=i-1;j--)
      { S.ch[j+T.len]=S.ch[j];
       S.ch[j]=''; }
     for(j=0;j<T.len;j++)
       S.ch[i+j-1]=T.ch[j];
       S.len=S.len+T.len;
       puts(S.ch);
     return S;
     }
}

SEQSTRING DelStr(SEQSTRING S,int i,int len)   /*删除字符串*/
  {int j;
   if(i>=S.len)
      {printf("删除串的位置不合理!\n");
       return;
      }
  else if(i+len-1>S.len)
     {printf("删除的串长值太大!\n");
      return;
     }
  else
    {j=i;
     while(S.ch[j-1+len]!='\0')
       { S.ch[j-1]=S.ch[j-1+len];
	 j++;
       }
     S.len=S.len-len;
     S.ch[S.len]='\0';
     puts(S.ch);
    }
}

int Index(SEQSTRING *S,SEQSTRING *T)    /*模式匹配*/
  {int i=1,j=1;
   while(i<=S->len && j<=T->len)
    { if (S->ch[i-1]==T->ch[j-1])
	{i++;j++;}
     else
	{i=i-j+2;
	 j=1;}
     }
   if(j>T->len)
       return (i-T->len);
    else
       return 0;
   }

main()                                    /*主函数*/
{ int i=0,j=1,len=0,l;
  int choice;
  S.len=0;
  T1.len=0;
  T2.len=0;
 while(j)
   {printf("\t\t\t            串子系统\n");
    printf("\n\t\t**********************************");
    printf("\n\t\t*         1------输入串               *");
    printf("\n\t\t*         2------求串长               *");
    printf("\n\t\t*         3------联接串               *");
    printf("\n\t\t*         4------求子串               *");
    printf("\n\t\t*         5------串比较               *");
    printf("\n\t\t*         6------串匹配               *");
    printf("\n\t\t*         7------插入串               *");
    printf("\n\t\t*         8------删除串               *");
    printf("\n\t\t*         9------显示串               *");
    printf("\n\t\t*         0------返  回               *");
    printf("\n\t\t**********************************\n");
    printf("\t\t 请输入选项序号(0--9)!");
    scanf("%d",&choice);getchar();
if(choice==1)
    S=InputStr();
else if (choice==2)
   { len=LenStr(S);
     printf("串长为：%d\n",len);
   }
else if (choice==3)
   { T1=InputStr();
     T2=InputStr();
     S=Concat(S,T1,T2);
     printf("联接后的字符串为：%s\n",S.ch);
   }
else if (choice==4)
   {T=InputStr(T);
    printf("请输入子串的位置及长度（数之间用逗号隔开）：");
    scanf("%d,%d",&i,&len);
    S=SubStr(T,i,len);
    if(S.len>0)
      printf("子串为：%s\n",S.ch);
   }
else if (choice==5)
   {T1=InputStr();
    T2=InputStr();
    l=EqualStr(T1,T2);
    if(l) printf("串1与串2相等！\n");
    else  printf("串1与串2不等！\n");
   }
else if (choice==6)
   {S=InputStr();
    T=InputStr();
    l=Index(&S,&T);
    if(l) printf("子串T在串S中！\n");
    else  printf("子串T不在串S中！\n");
   }
else if (choice==7)
   {S=InputStr(S);
    T=InputStr(T);
    printf("请输入插入位置i :");
    scanf("%d",&i);getchar();
    S=InsStr(S,i,T);
   }
else if (choice==8)
   {S=InputStr(S);
    printf("请输入删除子串的位置i及长度len（之间用逗号隔开）:");
    scanf("%d,%d",&i,&len);getchar();
    S=DelStr(S,i,len);
   }
else if (choice==9)
   OutputStr(S);
else if (choice==0)
   j=0;
else
printf("\n\t\t 输入的选项号有误!\n");
}
}
