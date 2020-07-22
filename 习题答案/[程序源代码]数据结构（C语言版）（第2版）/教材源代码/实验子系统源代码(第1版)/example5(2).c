#include <stdio.h>        
#define MAXSIZE 80
typedef struct
{char ch[MAXSIZE];
int len;
}SEQSTRING;

SEQSTRING S,T1,T2,T;

SEQSTRING InputStr()                /*�����ַ���*/
 { int i;
   T.len=0;
   printf("�������ַ���:\n");
   gets(T.ch);
   for(i=0;T.ch[i]!=��\0��;i++)
    T.len++;
   return T;
  }
void OutputStr(SEQSTRING T)      /*����ַ���*/
  { puts(T.ch);
  }

int LenStr(SEQSTRING T)                      /*���ַ�������*/
 { return (T.len);
  }
int EqualStr(SEQSTRING T1,SEQSTRING T2)  /*���ַ����Ƿ����*/
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

SEQSTRING Concat(SEQSTRING T,SEQSTRING T1,SEQSTRING T2) /*�����ַ���*/
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

SEQSTRING SubStr(SEQSTRING S,int i,int l)      /*ȡ�Ӵ�*/
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

SEQSTRING InsStr(SEQSTRING S,int i,SEQSTRING T)  /*�����ַ���*/
  {int j;
  if(T.len<=0)
    {printf("�ַ���Ϊ��!\n");
     return;
    }
  else if((i<=0)||(i>S.len+1))
    {printf("����λ���д���!\n");
      return;
    }
  else if (S.len+T.len>=MAXSIZE)
    {printf("���봮̫��!\n");
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

SEQSTRING DelStr(SEQSTRING S,int i,int len)   /*ɾ���ַ���*/
  {int j;
   if(i>=S.len)
      {printf("ɾ������λ�ò�����!\n");
       return;
      }
  else if(i+len-1>S.len)
     {printf("ɾ���Ĵ���ֵ̫��!\n");
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

int Index(SEQSTRING *S,SEQSTRING *T)    /*ģʽƥ��*/
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

main()                                    /*������*/
{ int i=0,j=1,len=0,l;
  int choice;
  S.len=0;
  T1.len=0;
  T2.len=0;
 while(j)
   {printf("\t\t\t            ����ϵͳ\n");
    printf("\n\t\t**********************************");
    printf("\n\t\t*         1------���봮               *");
    printf("\n\t\t*         2------�󴮳�               *");
    printf("\n\t\t*         3------���Ӵ�               *");
    printf("\n\t\t*         4------���Ӵ�               *");
    printf("\n\t\t*         5------���Ƚ�               *");
    printf("\n\t\t*         6------��ƥ��               *");
    printf("\n\t\t*         7------���봮               *");
    printf("\n\t\t*         8------ɾ����               *");
    printf("\n\t\t*         9------��ʾ��               *");
    printf("\n\t\t*         0------��  ��               *");
    printf("\n\t\t**********************************\n");
    printf("\t\t ������ѡ�����(0--9)!");
    scanf("%d",&choice);getchar();
if(choice==1)
    S=InputStr();
else if (choice==2)
   { len=LenStr(S);
     printf("����Ϊ��%d\n",len);
   }
else if (choice==3)
   { T1=InputStr();
     T2=InputStr();
     S=Concat(S,T1,T2);
     printf("���Ӻ���ַ���Ϊ��%s\n",S.ch);
   }
else if (choice==4)
   {T=InputStr(T);
    printf("�������Ӵ���λ�ü����ȣ���֮���ö��Ÿ�������");
    scanf("%d,%d",&i,&len);
    S=SubStr(T,i,len);
    if(S.len>0)
      printf("�Ӵ�Ϊ��%s\n",S.ch);
   }
else if (choice==5)
   {T1=InputStr();
    T2=InputStr();
    l=EqualStr(T1,T2);
    if(l) printf("��1�봮2��ȣ�\n");
    else  printf("��1�봮2���ȣ�\n");
   }
else if (choice==6)
   {S=InputStr();
    T=InputStr();
    l=Index(&S,&T);
    if(l) printf("�Ӵ�T�ڴ�S�У�\n");
    else  printf("�Ӵ�T���ڴ�S�У�\n");
   }
else if (choice==7)
   {S=InputStr(S);
    T=InputStr(T);
    printf("���������λ��i :");
    scanf("%d",&i);getchar();
    S=InsStr(S,i,T);
   }
else if (choice==8)
   {S=InputStr(S);
    printf("������ɾ���Ӵ���λ��i������len��֮���ö��Ÿ�����:");
    scanf("%d,%d",&i,&len);getchar();
    S=DelStr(S,i,len);
   }
else if (choice==9)
   OutputStr(S);
else if (choice==0)
   j=0;
else
printf("\n\t\t �����ѡ�������!\n");
}
}
