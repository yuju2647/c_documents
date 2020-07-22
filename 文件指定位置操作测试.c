#include<stdio.h>
#include<stdlib.h>
FILE *fp;
int main()
{
	fp=fopen("测试数据.txt","r+");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	fseek(fp,0,2);
	fputc('#',fp);
	rewind(fp);
	printf("在末尾加入 '#'\n");
	//system("pause");
	char ch;
	printf("\n\n开始\n\n");
	printf("文件指针位置 %d\n\n",ftell(fp));
	ch=fgetc(fp);
	printf("取值，ch= %c\n\n",ch);
	printf("取值后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
	printf("ch 为 b\n");
	fseek(fp,-1,1);
	printf("指针移动后,");
	printf("文件指针位置 %d\n\n",ftell(fp));
	fputc('a',fp);
	printf("在指针位置，输入 a 后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
    printf("\n\n\n\n第二操作\n\n");
	ch=fgetc(fp);
	printf("取值，ch= %c\n\n",ch);
	printf("取值后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
	printf("ch 为 b\n");
	fseek(fp,-1,1);
	printf("指针移动后,");
	printf("文件指针位置 %d\n\n",ftell(fp)); 
	fputc('a',fp);
	printf("在指针位置，输入 a 后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
	system("pause");
	printf("\n\n\n\n第三操作\n\n");
	ch=fgetc(fp);
	printf("取值，ch= %c\n\n",ch);
	printf("取值后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
	printf("ch 为 b\n");
	fseek(fp,-1,1);
	printf("指针移动后,");
	printf("文件指针位置 %d\n\n",ftell(fp)); 
	fputc('a',fp);
	printf("在指针位置，输入 a 后，");
	printf("文件指针位置 %d\n\n",ftell(fp));
	/*while(ch!='#')
	{
		if(ch=='b')
		{
			printf("ch 为 b\n");
			fseek(fp,-1,1);
			printf("指针移动后，");
			printf("文件指针位置 %d\n\n",ftell(fp)); 
			fputc('a',fp);
			printf("指针位置，输入 a 后，");
			printf("文件指针位置 %d\n",ftell(fp));
			system("pause"); 
		}
		ch=fgetc(fp);
		printf("取值，ch= %c\n\n",ch);
		printf("再次取值后,");
		printf("文件指针位置 %d\n",ftell(fp));
		system("pause");
	}*/
	fclose(fp);
	system("pause");
}
