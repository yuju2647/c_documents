#include <stdio.h>
#define MAXLEN 100

typedef struct
{	char vec[MAXLEN];
	int len;
}Str;

void ConcatStr(Str *s1,Str *s2)
{	    int i;
		printf("s1=%s    s2=%s\n",s1->vec,s2->vec);
		if(s1->len+s2->len>MAXLEN)
			printf("\n\t\t两个串太长，溢出！\n");
		else
		{	for(i=0;i<s2->len;i++)
			s1->vec[s1->len+i]=s2->vec[i];
			s1->vec[s1->len+i]='\0';
			s1->len=s1->len+s2->len;
		}
}

void SubStr(Str *s,int i,int j)
{	    int k;
		Str a;
		Str *s1=&a;
		if(i+j-1>s->len)
		{	printf("\n\t\t子串超界!\n");
			return;
		}
		else
		{	for(k=0;k<j;k++)
			s1->vec[k]=s->vec[i+k-1];
			s1->len=j;
			s1->vec[s1->len]='\0';
		}
		printf("\n\t\t取出字符为：");
				puts(s1->vec);
}
void DelStr(Str *s,int i,int j)
{	    int k;
		if(i+j-1>s->len)
			printf("\n\t\t所要删除的子串超界！\n");
		else
		{	for(k=i+j;k<s->len;k++,i++)
			s->vec[i]=s->vec[k];
			s->len=s->len-j;
			s->vec[s->len]='\0';
		}
}

Str *InsStr(Str *s,Str *s1,int i)
{	int k;
		if(i>=s->len||s->len+s1->len>MAXLEN)
    printf("\n\t\t不能插入!\n");
		else
		{	for(k=s->len-1;k>=i;k--)
			s->vec[s1->len+k]=s->vec[k];
			for(k=0;k<s1->len;k++)
			s->vec[i+k]=s1->vec[k];
			s->len=s->len+s1->len;
			s->vec[s->len]='\0';
		}
		return s;
}

int IndexStr(Str *s,Str *s1)
{	    int i,j,k;
		for(i=0;s->vec[i];i++)
			for(j=i,k=0;s->vec[j]==s1->vec[k];j++,k++)
				if(!s1->vec[k+1])
					return i;
				return -1;
}

int LenStr(Str *s)
{	    int i=0;
		while(s->vec[i]!='\0')
		  i++;
		return i;
}

Str *CseateStr(Str *s)
{	    gets(s->vec);
		s->len=LenStr(s);
		return s;
}

int EqualStr(Str *s1,Str *s2)
{	    int i=0;
	    for(i=0;s1->vec[i]==s2->vec[i]&&s1->vec[i];i++);
		return s1->vec[i]-s2->vec[i];
}

void main()                                   // 串子系统主函数
{ 
char choice,p;
int i,j,ch=1,k=0;
Str a,b,c,d;
Str *s=&a,*s1;
s->vec[0]='\0';
while(ch!='0')
{	    printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t串 子 系 统 \n");
		printf("\n\t\t***************************************");
		printf("\n\t\t*           1----------输  入  字  串            *");
		printf("\n\t\t*           2----------连  接  字  串            *");
		printf("\n\t\t*           3----------取  出  子  串            *");
		printf("\n\t\t*           4----------删  除  子  串            *");
		printf("\n\t\t*           5----------插  入  子  串            *");
		printf("\n\t\t*           6----------查  找  子  串            *");
		printf("\n\t\t*           7----------比 较 串 大 小            *");
		printf("\n\t\t*           8----------显  示  字  串            *");
		printf("\n\t\t*           0----------返          回            *");
		printf("\n\t\t***************************************");
		printf("\n\t\t请输入菜单号(0--8)：");
		scanf("%c",&choice);getchar();
		printf("\n");
		printf("\n");
		if (choice=='1')
		{	printf("\n\t\t请输入一个字符串:");
			gets(s->vec);
			s->len=LenStr(s);
		}
	    else if (choice=='2')
			{
			printf("\n\t\t请输入所要连接的串：");
			s1=CseateStr(&b);
			ConcatStr(s,s1);
			}
			else if (choice=='3')
			{	printf("\n\t\t请输入从第几个字符开始：");
				scanf("%d",&i);getchar();
				printf("\n\t\t请输入取出的连续字符数：");
				scanf("%d",&j);getchar();
				SubStr(s,i,j);
			}
			else if (choice=='4')
			{	printf("\n\t\t请输入从第几个字符开始：");
				scanf("%d",&i);getchar();
				printf("\n\t\t请输入删除的连续字符数：");
				scanf("%d",&j);getchar();
				DelStr(s,i-1,j);
			}
			else if (choice=='5')
			{	printf("\n\t\t请输入在第几个字符前插入：");
				scanf("%d",&i);getchar();
				printf("\n\t\t请输入所要插入的字符串：");
				s1=CseateStr(&b);
				InsStr(s,s1,i-1);
			}
			else if (choice=='6')
			{	printf("\n\t\t请输入所要查找的字符串：");
				s1=CseateStr(&b);
				i=IndexStr(s,s1);
				if(i!=-1)
					printf ("\n\t\t第一次出现的位置是第%d个。\n",i+1);
				else
					printf ("\n\t\t该子串不在其中！\n");
			}
			else if(choice=='7')
			{	printf("\n\t\t请输入第一个串：");
				gets(c.vec);
				printf("\n\t\t请输入第二个串：");
				gets(d.vec);
			    k=EqualStr(&c,&d);
				if(k>0)
					printf("\n\t\t第一个串大！");
				else if(k<0)
					printf("\n\t\t第二个串大！");
				else
					printf("\n\t\t一样大！");
			}
			else if (choice=='8')
			{	printf ("\n\t\t该串值为：");
				if(s->vec[0]=='\0')
					printf("空！");
				else
					puts(s->vec);
			}
			else if (choice=='0')
				break;
			else
				printf ("\n\t\t\t***请注意：输入有误！***\n");
			if (choice!='X'&&choice!='X')
			{	printf ("\n\n\t\t按回车键继续,按任意键返回主菜单.\n");
				p=getchar();
				if(p!='\xA')
				{getchar();break;}
			}
		}
}
