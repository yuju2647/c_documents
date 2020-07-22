#include<stdio.h>
#include<malloc.h>
#define MAXLEN 100
typedef struct stacknode			         // ����ջ�Ĵ洢�ṹ
{ 
 int data;
 struct stacknode *next;
}stacknode;
typedef struct						
{ 
 stacknode *top;			              	// ����ջ����ָ��
}linkstack;

void Push(linkstack *s,int x)		           	// ��ջ����
{	    stacknode *p;
            p=(stacknode*)malloc(sizeof(stacknode)); 
		p->data=x;
		p->next=s->top;
		s->top=p;
}

int Pop(linkstack *s)				       		// ��ջ����
{	        int x;
		stacknode *p=s->top;
		x=p->data;
		s->top=p->next;
		free(p);
		return x;
}

void ShowStack (linkstack *s)	     	      	// ��ʾջ��Ԫ��
{	stacknode *p=s->top;
		if(p==NULL)
			printf ("\t\tջΪ�ա�\n");
		else
		{	printf ("\t\tջԪ��Ϊ��");
			while(p!=NULL)
			{	printf ("%6d",p->data);
				p=p->next;
			}
			printf ("\n");
		}
}

void Conversion(int n)		              		// ջ��Ӧ�ã�������-ʮ����ת��
{ 	    linkstack s; 
            stacknode *p;  
		int x; 
		s.top=NULL;                         			// ��ջ��
		do
		{  x=n%2;                          				// ȡ����
			n=n/2;                           			// ȡ�µ���			    		   
                        p=(stacknode*)malloc(sizeof(stacknode));    // �����½��
			p->next=s.top;                    			// �޸�ջ��ָ��
			s.top=p;
			s.top->data=x;                     		// ������ջ
		}
		while (n);
		printf ("\n\t\tת����Ķ�������ֵΪ��");
		while (s.top)                          			// ��ջ����
		{	printf ("%d",s.top->data);
			p=s.top;
			s.top=s.top->next;
			free(p);                        // ��ջһ���������ջ�һ�����
		}
		printf ("\n");
		getchar();
} 

void Suffix()
{	        char str[MAXLEN];			           		// �洢�������ʽ
		char stack[MAXLEN];			       			// �������ջ
		char exp[MAXLEN],ch;
		int n,i,j,t,top=0;  
		printf ("\n\t\t*   �����������ʽ����#������(ֻ�ܰ���+,-,*, / ��������)  *\n");
		printf ("\n\t\t������һ�����������������ʽ��");
		i=0;
		do{	i++;                      			// �����û�����ı��ʽ
			scanf("%c",&str[i]);
		}
                while(str[i]!='#'&&i!=MAXLEN);
		n=i; 					        	// n��¼������ʽ�ܵ��ַ�����
		t=1;
		i=1;
		ch=str[i];
		i++;
		while (ch!='#')
		{  switch (ch)
			{
			case '(': 
				top++;stack[top]=ch; break;
			case ')':
				while (stack[top]!='(')
				{	exp[t++]=stack[top--];
					exp[t++]=',';
				}
				top--; break;
			case '+':
			case '-':
				while (top!=0&&stack[top]!='(')
				{	exp[t++]=stack[top--];
					exp[t++]=',';
				}
				stack[++top]=ch; break;
			case '*':
			case '/':
				while (stack[top]=='*'||stack[top]=='/')
				{	exp[t++]=stack[top--];
					exp[t++]=',';
				}
				stack[++top]=ch; break;
			case ' ': break;
			default:
				while (ch>='0'&&ch<='9')       // �ж������ַ��Ƿ�Ϊ10���ڵ�������
				{	exp[t++]=ch;
					ch=str[i++];
				}
				i--;
				exp[t++]=',';
			}
			ch=str[i++];
		}
		while (top!=0)
		{
			exp[t++]=stack[top--];
		}
		printf ("\n\t\t������ʽ��");
		for(j=1;j<n;j++)
			printf ("%c",str[j]);
		printf ("\n\t\t��׺���ʽ��");
		for (j=1;j<t;j++)
			printf ("%c",exp[j]);
		printf ("\n");
}

void main()
{
		int i=1,j=1,val,n;
		char choice,a;
		linkstack *s;
		s=(linkstack*)malloc(sizeof(linkstack));
		s->top=NULL;
		while (i)
		{
			printf ("\n\n\n\n");
			printf ("\n\t\t               ջ��ϵͳ\n");
			printf ("\n\t\t***********************************");
			printf ("\n\t\t*            1-----------��      ջ          *");
			printf ("\n\t\t*            2-----------��      ջ          *");
			printf ("\n\t\t*            3-----------��      ʾ          *");
			printf ("\n\t\t*            4-----------�� �� ת��          *");
			printf ("\n\t\t*            5-----------��׺���ʽ          *");
			printf ("\n\t\t*            0-----------��      ��          *");
			printf ("\n\t\t***********************************");
			printf ("\n\t\t��ѡ��˵���(0--5)��");
			choice=getchar();
			getchar ();
			switch (choice)
			{
			case '1':
				while (j)
				{
					printf ("\t\t�����һ������(���س�������һ��������'0'����):");
					scanf ("%d",&val);getchar();
					if (val!=0)
						Push (s,val);
					else
						j=0;
				}break;
			case '2':if (s->top!=NULL)
				printf ("\t\t��ջԪ��Ϊ:%6d\n",Pop(s));break;
			case '3':
				ShowStack (s);break;
			case '4':
				printf ("\n\t\t������һ��ʮ������������");
				scanf ("%d",&n);
				Conversion(n);break;
			case '5':
				Suffix();getchar ();
				break;
			case '0':
				i=0;break;
			default:;
			}
	if(choice=='1'||choice=='2'||choice=='3'||choice=='4'||choice=='5')
		   {
				printf ("\n\t\t���س��������������������!");
				a=getchar ();
				if (a!='\xA') 
				i=0;
		   }
		}
}
