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
int openfile()//打开记事本文件 
{
	if((fp=fopen("记事本","r+"))==NULL)
	{
		printf("记事本打开失败\n");
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
int addchar()//添加字符 
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
 COORD pos= {x,y}; /* 光标的起始位（第1列，第3行） 0是第1列 2是第3行*/
 hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hOut, pos);
 //printf("定位光标位置(%d,%d)\n",pos.X,pos.Y);
 return 0;
} 

