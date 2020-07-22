/* ======================================== */
/*    程序实例: 4-5.c                       */
/*    用非递归算法将输入的任意一个非负       */
/*    十进制整数转换成八进制数               */
/* ======================================== */
#define MAXSIZE 100
#include <stdio.h>
typedef struct
{
	int data[MAXSIZE];
	int top;
}SeqStack;
void initStack(SeqStack *s)
{    /*顺序栈初始化*/
	s->top=0;
}

int getTop(SeqStack *s)
{    /*返回栈顶元素*/
	int x;
	if(s->top==0)
	{
		printf("栈空\n");
		x=0; 
	}
	else
		x=(s->data)[s->top];
	return x;
}

int push(SeqStack *s,  int x)
{    /*元素x入栈*/
	if(s->top==MAXSIZE-1)
	{
		printf("栈满!\n");
		return 0;
	}
	else
	{
		s->top++;
		(s->data)[s->top]=x;
		return 1;
	}
}

int pop(SeqStack *s)
{   /*返回栈顶元素并删除栈顶元素*/
	int  x;
	if(s->top == 0)
	{
		printf("栈空\n");
		x=0;
	}
	else
	{ 
		x=(s->data)[s->top];
		s->top--;
	}
	return  x;
}

main( )
{
	SeqStack stack, *s;
	int n=0;
	s=&stack;
	initStack(s);
	printf("输入一非负整数（十进制）："); 
	scanf("%d",&n);
	push(s,'#');
	while(n!= 0)
	{
		push(s,n%8); 
		n=n/8;
	}               
	printf("对应的八进制数为：");
	while(getTop(s)!='#')
		printf("%d",pop(s));
	printf("\n");
}
//程序运行结果：
//输入一非负整数（十进制）：10（回车） 
//对应的八进制数为：12
