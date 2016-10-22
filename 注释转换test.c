#include "test.h"

int main()
{
	FILE *pfout = NULL;         //定义文件指针 输出
	FILE *pfin = NULL;
	pfin = fopen(INPUT,"r");//打开文件（命令）
	if(pfin == NULL)
	{
		perror("not open file");  //提示错位原因
		exit(EXIT_FAILURE);        //失败的宏定义显示
	}
	pfout = fopen(OUTPUT,"w");    //写入文件
	if(pfout == NULL)
	{
		perror("not open file ");
		fclose(pfin);
		exit(EXIT_FAILURE);
	}
	note_convert(pfin,pfout);     //调用注释转换函数
	system("pause");
	return 0;
}
