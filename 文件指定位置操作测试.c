#include<stdio.h>
#include<stdlib.h>
FILE *fp;
int main()
{
	fp=fopen("��������.txt","r+");
	if(fp==NULL)
	{
		printf("�ļ���ʧ��\n");
		getch();
		exit(1);
	}
	fseek(fp,0,2);
	fputc('#',fp);
	rewind(fp);
	printf("��ĩβ���� '#'\n");
	//system("pause");
	char ch;
	printf("\n\n��ʼ\n\n");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	ch=fgetc(fp);
	printf("ȡֵ��ch= %c\n\n",ch);
	printf("ȡֵ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	printf("ch Ϊ b\n");
	fseek(fp,-1,1);
	printf("ָ���ƶ���,");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	fputc('a',fp);
	printf("��ָ��λ�ã����� a ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
    printf("\n\n\n\n�ڶ�����\n\n");
	ch=fgetc(fp);
	printf("ȡֵ��ch= %c\n\n",ch);
	printf("ȡֵ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	printf("ch Ϊ b\n");
	fseek(fp,-1,1);
	printf("ָ���ƶ���,");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp)); 
	fputc('a',fp);
	printf("��ָ��λ�ã����� a ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	system("pause");
	printf("\n\n\n\n��������\n\n");
	ch=fgetc(fp);
	printf("ȡֵ��ch= %c\n\n",ch);
	printf("ȡֵ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	printf("ch Ϊ b\n");
	fseek(fp,-1,1);
	printf("ָ���ƶ���,");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp)); 
	fputc('a',fp);
	printf("��ָ��λ�ã����� a ��");
	printf("�ļ�ָ��λ�� %d\n\n",ftell(fp));
	/*while(ch!='#')
	{
		if(ch=='b')
		{
			printf("ch Ϊ b\n");
			fseek(fp,-1,1);
			printf("ָ���ƶ���");
			printf("�ļ�ָ��λ�� %d\n\n",ftell(fp)); 
			fputc('a',fp);
			printf("ָ��λ�ã����� a ��");
			printf("�ļ�ָ��λ�� %d\n",ftell(fp));
			system("pause"); 
		}
		ch=fgetc(fp);
		printf("ȡֵ��ch= %c\n\n",ch);
		printf("�ٴ�ȡֵ��,");
		printf("�ļ�ָ��λ�� %d\n",ftell(fp));
		system("pause");
	}*/
	fclose(fp);
	system("pause");
}
