/* ======================================== */
/*    程序实例: 4-6.c                       */
/*    用非递归算法将输入的任意一个非负       */
/*    十进制整数转换成八进制数               */
/* ======================================== */
#include<stdio.h>
#define MAXLEN 100             	/*定义变量*/
void trans(char str[],char exp[])     	/*将算术表达式str转换成后缀表达式exp*/
{
	struct
	{
		char data[MAXLEN];     	/*定义用于存放加、减、乘、除等符号的栈*/
		int  top;                	/*定义栈指针*/
	}op;
	char ch;
	int i=0,t=0;
	op.top=-1;
	ch=str[i];i++;
	while(ch!='\0')              	/*扫描算术表达式数组是否结束*/
	{
		switch(ch)
		{
		case'(':               	/*判断是否为'('*/
			op.top++;op.data[op.top]=ch;
			break;
		case')':                 	/*判断是否为')'*/
			while(op.data[op.top]!='(')
			{
				exp[t]=op.data[op.top];
				op.top--;
				t++;
			}
			op.top--;
			break;
		case'+':
		case'-':                 	/*判断是否为'+'或'-'*/
			while(op.top!= -1 && op.data[op.top]!='(')
			{
				exp[t]=op.data[op.top];
				op.top--;
				t++;
			}
			op.top++;
			op.data[op.top]=ch;
			break;
		case'*':
		case'/':                 	/*判断是否为'*'或'/'*/
			while(op.data[op.top]=='*' || op.data[op.top]=='/')
			{
				exp[t]=op.data[op.top];
				op.top--;
				t++;
			}
			op.top++;op.data[op.top]=ch;
			break;
		case' ':break;            	/*跳过空格*/
		default:
			while(ch>='0' && ch<='9')
			{
				exp[t]=ch;t++;
				ch=str[i];i++;
			}
			i--;
			exp[t]='#';t++;       	/*用#表示数值是否结束*/
		}
		ch=str[i];i++;
	}
	while(op.top!= -1)          	/*扫描结束，栈是否为空*/
	{
		exp[t]=op.data[op.top];
		t++;
		op.top--;
	}
	exp[t]='\0';                  	/*给后缀表达式添加结束符*/
}

float compvalue(char exp[])         	/*计算后缀表达式的值*/
{
	struct
	{
		float data[MAXLEN];       	/*存放数值*/
		int top;                     	/*定义栈指针*/
	} st;
	float d;
	char ch;
	int t=0;
	st.top= -1;
	ch=exp[t];t++;
	while(ch!='\0')                   	/*扫描字符串是否结束*/
	{
		switch(ch)
		{
		case'+':st.data[st.top-1]=st.data[st.top-1]+st.data[st.top];
			st.top--;break;
		case'-':st.data[st.top-1]=st.data[st.top-1]-st.data[st.top];
			st.top--;break;
		case'*':st.data[st.top-1]=st.data[st.top-1]*st.data[st.top];
			st.top--;break;
		case'/':
			if(st.data[st.top]!=0)
				st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
			else
			{
				printf("\n除零错误! \n");  	/*判断分母是否为0，如为0推出*/
				return(0);
			}
			st.top--;break;
		default:
			d=0;
			while(ch>='0' && ch<='9')     	/*判断是否为数字字符*/
			{
				d=10*d+ch-'0';
				ch=exp[t];t++;
			}
			st.top++;
			st.data[st.top]=d;
		}
		ch=exp[t];t++;
	}
	return st.data[st.top];
}

main()
{
	char str[MAXLEN],exps[MAXLEN];
	/*定义存储算术表达式的字符数组和用于存放后缀表达式的数组*/
	printf("输入一个求值表达式，只能包含+、-、*、/、括弧和正整数\n");
	printf("表达式：");
	gets(str);                   	/*输入求值表达式*/
	printf("原表达式（中缀表达式）：%s\n",str); 
	trans(str,exps);              		/*调用中缀表达式变后缀表达式的函数*/
	printf("后缀表达式：% s\n",exps);
	printf("表达式的计算结果：% g\n",compvalue(exps));
	return 0;                          
}
//程序运行结果：
//输入一个求值表达式，只能包含+、-、*、/、括弧和正整数
//表达式： 2 + 4 /(18–(6 + 10))* 6（回车） 
//原表达式（中缀表达式）： 2 + 4 /(18–(6 + 10))* 6 
//后缀表达式：2#4#18#6#10#+–/6#*+
//表达式的计算结果：14
