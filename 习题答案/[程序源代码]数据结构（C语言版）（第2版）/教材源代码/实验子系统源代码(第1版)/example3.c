#include<stdio.h>
#include<malloc.h>
#define MAXLEN 100
typedef struct stacknode			         // 定义栈的存储结构
{ 
 int data;
 struct stacknode *next;
}stacknode;
typedef struct						
{ 
 stacknode *top;			              	// 定义栈顶的指针
}linkstack;

void Push(linkstack *s,int x)		           	// 进栈操作
{	    stacknode *p;
            p=(stacknode*)malloc(sizeof(stacknode)); 
		p->data=x;
		p->next=s->top;
		s->top=p;
}

int Pop(linkstack *s)				       		// 出栈操作
{	        int x;
		stacknode *p=s->top;
		x=p->data;
		s->top=p->next;
		free(p);
		return x;
}

void ShowStack (linkstack *s)	     	      	// 显示栈内元素
{	stacknode *p=s->top;
		if(p==NULL)
			printf ("\t\t栈为空。\n");
		else
		{	printf ("\t\t栈元素为：");
			while(p!=NULL)
			{	printf ("%6d",p->data);
				p=p->next;
			}
			printf ("\n");
		}
}

void Conversion(int n)		              		// 栈的应用：二进制-十进制转换
{ 	    linkstack s; 
            stacknode *p;  
		int x; 
		s.top=NULL;                         			// 置栈空
		do
		{  x=n%2;                          				// 取余数
			n=n/2;                           			// 取新的商			    		   
                        p=(stacknode*)malloc(sizeof(stacknode));    // 申请新结点
			p->next=s.top;                    			// 修改栈顶指针
			s.top=p;
			s.top->data=x;                     		// 余数入栈
		}
		while (n);
		printf ("\n\t\t转换后的二进制数值为：");
		while (s.top)                          			// 出栈处理
		{	printf ("%d",s.top->data);
			p=s.top;
			s.top=s.top->next;
			free(p);                        // 出栈一个余数，收回一个结点
		}
		printf ("\n");
		getchar();
} 

void Suffix()
{	        char str[MAXLEN];			           		// 存储算术表达式
		char stack[MAXLEN];			       			// 运算符号栈
		char exp[MAXLEN],ch;
		int n,i,j,t,top=0;  
		printf ("\n\t\t*   输入算术表达式，以#结束。(只能包含+,-,*, / 和正整数)  *\n");
		printf ("\n\t\t请输入一个正整数的算术表达式：");
		i=0;
		do{	i++;                      			// 接受用户输入的表达式
			scanf("%c",&str[i]);
		}
                while(str[i]!='#'&&i!=MAXLEN);
		n=i; 					        	// n记录输入表达式总的字符个数
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
				while (ch>='0'&&ch<='9')       // 判定输入字符是否为10以内的正整数
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
		printf ("\n\t\t输入表达式：");
		for(j=1;j<n;j++)
			printf ("%c",str[j]);
		printf ("\n\t\t后缀表达式：");
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
			printf ("\n\t\t               栈子系统\n");
			printf ("\n\t\t***********************************");
			printf ("\n\t\t*            1-----------进      栈          *");
			printf ("\n\t\t*            2-----------出      栈          *");
			printf ("\n\t\t*            3-----------显      示          *");
			printf ("\n\t\t*            4-----------进 制 转换          *");
			printf ("\n\t\t*            5-----------后缀表达式          *");
			printf ("\n\t\t*            0-----------返      回          *");
			printf ("\n\t\t***********************************");
			printf ("\n\t\t请选择菜单号(0--5)：");
			choice=getchar();
			getchar ();
			switch (choice)
			{
			case '1':
				while (j)
				{
					printf ("\t\t请键入一个整数(按回车输入下一个，输入'0'结束):");
					scanf ("%d",&val);getchar();
					if (val!=0)
						Push (s,val);
					else
						j=0;
				}break;
			case '2':if (s->top!=NULL)
				printf ("\t\t出栈元素为:%6d\n",Pop(s));break;
			case '3':
				ShowStack (s);break;
			case '4':
				printf ("\n\t\t请输入一个十进制正整数：");
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
				printf ("\n\t\t按回车键继续，按任意键返回!");
				a=getchar ();
				if (a!='\xA') 
				i=0;
		   }
		}
}
