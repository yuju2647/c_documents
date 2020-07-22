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
			printf("\n\t\t������̫���������\n");
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
		{	printf("\n\t\t�Ӵ�����!\n");
			return;
		}
		else
		{	for(k=0;k<j;k++)
			s1->vec[k]=s->vec[i+k-1];
			s1->len=j;
			s1->vec[s1->len]='\0';
		}
		printf("\n\t\tȡ���ַ�Ϊ��");
				puts(s1->vec);
}
void DelStr(Str *s,int i,int j)
{	    int k;
		if(i+j-1>s->len)
			printf("\n\t\t��Ҫɾ�����Ӵ����磡\n");
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
    printf("\n\t\t���ܲ���!\n");
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

void main()                                   // ����ϵͳ������
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
		printf("\n\t\t\t\t�� �� ϵ ͳ \n");
		printf("\n\t\t***************************************");
		printf("\n\t\t*           1----------��  ��  ��  ��            *");
		printf("\n\t\t*           2----------��  ��  ��  ��            *");
		printf("\n\t\t*           3----------ȡ  ��  ��  ��            *");
		printf("\n\t\t*           4----------ɾ  ��  ��  ��            *");
		printf("\n\t\t*           5----------��  ��  ��  ��            *");
		printf("\n\t\t*           6----------��  ��  ��  ��            *");
		printf("\n\t\t*           7----------�� �� �� �� С            *");
		printf("\n\t\t*           8----------��  ʾ  ��  ��            *");
		printf("\n\t\t*           0----------��          ��            *");
		printf("\n\t\t***************************************");
		printf("\n\t\t������˵���(0--8)��");
		scanf("%c",&choice);getchar();
		printf("\n");
		printf("\n");
		if (choice=='1')
		{	printf("\n\t\t������һ���ַ���:");
			gets(s->vec);
			s->len=LenStr(s);
		}
	    else if (choice=='2')
			{
			printf("\n\t\t��������Ҫ���ӵĴ���");
			s1=CseateStr(&b);
			ConcatStr(s,s1);
			}
			else if (choice=='3')
			{	printf("\n\t\t������ӵڼ����ַ���ʼ��");
				scanf("%d",&i);getchar();
				printf("\n\t\t������ȡ���������ַ�����");
				scanf("%d",&j);getchar();
				SubStr(s,i,j);
			}
			else if (choice=='4')
			{	printf("\n\t\t������ӵڼ����ַ���ʼ��");
				scanf("%d",&i);getchar();
				printf("\n\t\t������ɾ���������ַ�����");
				scanf("%d",&j);getchar();
				DelStr(s,i-1,j);
			}
			else if (choice=='5')
			{	printf("\n\t\t�������ڵڼ����ַ�ǰ���룺");
				scanf("%d",&i);getchar();
				printf("\n\t\t��������Ҫ������ַ�����");
				s1=CseateStr(&b);
				InsStr(s,s1,i-1);
			}
			else if (choice=='6')
			{	printf("\n\t\t��������Ҫ���ҵ��ַ�����");
				s1=CseateStr(&b);
				i=IndexStr(s,s1);
				if(i!=-1)
					printf ("\n\t\t��һ�γ��ֵ�λ���ǵ�%d����\n",i+1);
				else
					printf ("\n\t\t���Ӵ��������У�\n");
			}
			else if(choice=='7')
			{	printf("\n\t\t�������һ������");
				gets(c.vec);
				printf("\n\t\t������ڶ�������");
				gets(d.vec);
			    k=EqualStr(&c,&d);
				if(k>0)
					printf("\n\t\t��һ������");
				else if(k<0)
					printf("\n\t\t�ڶ�������");
				else
					printf("\n\t\tһ����");
			}
			else if (choice=='8')
			{	printf ("\n\t\t�ô�ֵΪ��");
				if(s->vec[0]=='\0')
					printf("�գ�");
				else
					puts(s->vec);
			}
			else if (choice=='0')
				break;
			else
				printf ("\n\t\t\t***��ע�⣺��������***\n");
			if (choice!='X'&&choice!='X')
			{	printf ("\n\n\t\t���س�������,��������������˵�.\n");
				p=getchar();
				if(p!='\xA')
				{getchar();break;}
			}
		}
}
