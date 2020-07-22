/* ======================================== */
/*    ����ʵ��: 4-5.c                       */
/*    �÷ǵݹ��㷨�����������һ���Ǹ�       */
/*    ʮ��������ת���ɰ˽�����               */
/* ======================================== */
#define MAXSIZE 100
#include <stdio.h>
typedef struct
{
	int data[MAXSIZE];
	int top;
}SeqStack;
void initStack(SeqStack *s)
{    /*˳��ջ��ʼ��*/
	s->top=0;
}

int getTop(SeqStack *s)
{    /*����ջ��Ԫ��*/
	int x;
	if(s->top==0)
	{
		printf("ջ��\n");
		x=0; 
	}
	else
		x=(s->data)[s->top];
	return x;
}

int push(SeqStack *s,  int x)
{    /*Ԫ��x��ջ*/
	if(s->top==MAXSIZE-1)
	{
		printf("ջ��!\n");
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
{   /*����ջ��Ԫ�ز�ɾ��ջ��Ԫ��*/
	int  x;
	if(s->top == 0)
	{
		printf("ջ��\n");
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
	printf("����һ�Ǹ�������ʮ���ƣ���"); 
	scanf("%d",&n);
	push(s,'#');
	while(n!= 0)
	{
		push(s,n%8); 
		n=n/8;
	}               
	printf("��Ӧ�İ˽�����Ϊ��");
	while(getTop(s)!='#')
		printf("%d",pop(s));
	printf("\n");
}
//�������н����
//����һ�Ǹ�������ʮ���ƣ���10���س��� 
//��Ӧ�İ˽�����Ϊ��12
