#ifndef __test_h__              //定义
#define __test_h__

#include <stdio.h>
#include <stdlib.h>


#define INPUT "input.c"          
#define OUTPUT "output.c"

enum KIND //枚举表示操作选项
{
	END_START,
	NULL_START,
	C_START,
	CPP_START,
};

void note_convert(FILE *pfin,FILE *pfout);//注释转化操作函数
void null_state(FILE *pfin,FILE *pfout,enum KIND *sta);//普通字符转换函数
void c_state(FILE *pfin,FILE *pfout,enum KIND *sta);//c语言注释转换为c++注释函数
void cpp_state(FILE *pfin,FILE *pfout,enum KIND *sta);//c++注释转化函数

#endif