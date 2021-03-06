/* ======================================== */
/*    程序实例: 3-2.c                  */
/*    计算英语平均成绩(动态内存分配)      */
/* ======================================== */
#include <stdlib.h>

void main()
{
	int *score;                    /* 整型指标声明 */
	int i;
	int num;                       /* 学生人数     */
	int sum;                       /* 成绩总分变量 */
	float ave;                     /* 平均成绩变量 */

	sum = 0;                       /* 设置总分初值 */
	printf("请输入学生人数 ==> ");
	scanf("%d", &num);              /* 读取学生人数 */
	/* 分配成绩数组的内存 */
	score = (int *) malloc(num * sizeof(int));
	if ( !score )                  /* 检查指针     */
	{
		printf("内存分配失败! \n");
		exit(1);
	}

	for ( i = 0; i < num; i++ )
	{
		printf("请输入英语成绩. ==> ");
		scanf("%d", &score[i]);      /* 读取英语成绩 */
		sum += *(score + i);        /* 计算总分     */
	}

	ave = (float) sum / (float) num;  /* 计算平均分 */
	printf("平均成绩: %6.2f \n",ave);
}
//程序运行结果：
//请输入学生人数 ==> 4
//请输入英语成绩. ==> 75
//请输入英语成绩. ==> 80
//请输入英语成绩. ==> 92
//请输入英语成绩. ==> 81
//平均成绩:  82.00
