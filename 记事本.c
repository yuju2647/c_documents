#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
FILE *fp;
int main()
{
	at(2,2);
	system("pause");
	/*openfile();
	printfile();
	addchar();
	rewind(fp);
	printfile();*/
}
int openfile()//�򿪼��±��ļ� 
{
	if((fp=fopen("���±�","r+"))==NULL)
	{
		printf("���±���ʧ��\n");
		getch();
		exit(1);
	}
}
int printfile()
{
	char a;
	a=fgetc(fp);
	while(a!=EOF)
	{
		putchar(a);
		a=fgetc(fp);
	}
	return 0;
}
int addchar()//����ַ� 
{
	char a;
	a=getchar();
	while(a!='$')
	{
		fputc(a,fp);
		a=getchar();
	}
	return 0;
}
int at(int x,int y) 
{
 HANDLE hOut;
 COORD pos= {x,y}; /* ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��*/
 hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hOut, pos);
 //printf("��λ���λ��(%d,%d)\n",pos.X,pos.Y);
 return 0;
} 

