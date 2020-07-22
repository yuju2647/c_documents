/* ======================================== */
/*    ����ʵ��: 4-6.c                       */
/*    �÷ǵݹ��㷨�����������һ���Ǹ�       */
/*    ʮ��������ת���ɰ˽�����               */
/* ======================================== */
#include<stdio.h>
#define MAXLEN 100             	/*�������*/
void trans(char str[],char exp[])     	/*���������ʽstrת���ɺ�׺���ʽexp*/
{
	struct
	{
		char data[MAXLEN];     	/*�������ڴ�żӡ������ˡ����ȷ��ŵ�ջ*/
		int  top;                	/*����ջָ��*/
	}op;
	char ch;
	int i=0,t=0;
	op.top=-1;
	ch=str[i];i++;
	while(ch!='\0')              	/*ɨ���������ʽ�����Ƿ����*/
	{
		switch(ch)
		{
		case'(':               	/*�ж��Ƿ�Ϊ'('*/
			op.top++;op.data[op.top]=ch;
			break;
		case')':                 	/*�ж��Ƿ�Ϊ')'*/
			while(op.data[op.top]!='(')
			{
				exp[t]=op.data[op.top];
				op.top--;
				t++;
			}
			op.top--;
			break;
		case'+':
		case'-':                 	/*�ж��Ƿ�Ϊ'+'��'-'*/
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
		case'/':                 	/*�ж��Ƿ�Ϊ'*'��'/'*/
			while(op.data[op.top]=='*' || op.data[op.top]=='/')
			{
				exp[t]=op.data[op.top];
				op.top--;
				t++;
			}
			op.top++;op.data[op.top]=ch;
			break;
		case' ':break;            	/*�����ո�*/
		default:
			while(ch>='0' && ch<='9')
			{
				exp[t]=ch;t++;
				ch=str[i];i++;
			}
			i--;
			exp[t]='#';t++;       	/*��#��ʾ��ֵ�Ƿ����*/
		}
		ch=str[i];i++;
	}
	while(op.top!= -1)          	/*ɨ�������ջ�Ƿ�Ϊ��*/
	{
		exp[t]=op.data[op.top];
		t++;
		op.top--;
	}
	exp[t]='\0';                  	/*����׺���ʽ��ӽ�����*/
}

float compvalue(char exp[])         	/*�����׺���ʽ��ֵ*/
{
	struct
	{
		float data[MAXLEN];       	/*�����ֵ*/
		int top;                     	/*����ջָ��*/
	} st;
	float d;
	char ch;
	int t=0;
	st.top= -1;
	ch=exp[t];t++;
	while(ch!='\0')                   	/*ɨ���ַ����Ƿ����*/
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
				printf("\n�������! \n");  	/*�жϷ�ĸ�Ƿ�Ϊ0����Ϊ0�Ƴ�*/
				return(0);
			}
			st.top--;break;
		default:
			d=0;
			while(ch>='0' && ch<='9')     	/*�ж��Ƿ�Ϊ�����ַ�*/
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
	/*����洢�������ʽ���ַ���������ڴ�ź�׺���ʽ������*/
	printf("����һ����ֵ���ʽ��ֻ�ܰ���+��-��*��/��������������\n");
	printf("���ʽ��");
	gets(str);                   	/*������ֵ���ʽ*/
	printf("ԭ���ʽ����׺���ʽ����%s\n",str); 
	trans(str,exps);              		/*������׺���ʽ���׺���ʽ�ĺ���*/
	printf("��׺���ʽ��% s\n",exps);
	printf("���ʽ�ļ�������% g\n",compvalue(exps));
	return 0;                          
}
//�������н����
//����һ����ֵ���ʽ��ֻ�ܰ���+��-��*��/��������������
//���ʽ�� 2 + 4 /(18�C(6 + 10))* 6���س��� 
//ԭ���ʽ����׺���ʽ���� 2 + 4 /(18�C(6 + 10))* 6 
//��׺���ʽ��2#4#18#6#10#+�C/6#*+
//���ʽ�ļ�������14
