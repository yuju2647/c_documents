#include<stdio.h>
#include<stdlib.h>
float hundred_to_gpa(float s);
int main()
{
	float s=0,t;
	for(s=0;s<=100;s++)
	{
		t=hundred_to_gpa(s);
	    printf("grade=%f       gpa=%f\n\n",s,t);
	}
	
}
float hundred_to_gpa(float s)//ͨ�� �ٷ��Ʒ��� �жϳ�����Ӧ�ļ��� ����Ϊ��������ֵ ���� 
{
	//�������� 
	if(s>=67)
	{
		if(s<=69)
		{
			return 2.0;
		}
		else
		{
			if(s<=73)
			{
				return 2.33;
			}
			else
			{
				if(s<=76)
				{
					return 2.76;
				}
				else
				{
					if(s<=86)
					{
						if(s>=84)
						{
							return 3.67;
						}
						else
						{
							if(s>=80)
							{
								return 3.33;
							}
							else
							{
								if(s>=77)
								{
									return 3.0;
								}
								else
								{
									printf("\n���ִ���,�ٷ����жϴ��� 1\n\n");
									getch();
									exit(1);
								}
							}
						}
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
	else
	{
		if(s==60)
		{
			return 1.0;
		}
		else
		{
			if(s>=64)
			{
				return 1.67;
			}
			else
			{
				if(s>=61)
				{
					return 1.33;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	printf("\n���ִ���,�ٷ����жϴ��� 2\n\n");
}
