#ifndef __test_h__              //����
#define __test_h__

#include <stdio.h>
#include <stdlib.h>


#define INPUT "input.c"          
#define OUTPUT "output.c"

enum KIND //ö�ٱ�ʾ����ѡ��
{
	END_START,
	NULL_START,
	C_START,
	CPP_START,
};

void note_convert(FILE *pfin,FILE *pfout);//ע��ת����������
void null_state(FILE *pfin,FILE *pfout,enum KIND *sta);//��ͨ�ַ�ת������
void c_state(FILE *pfin,FILE *pfout,enum KIND *sta);//c����ע��ת��Ϊc++ע�ͺ���
void cpp_state(FILE *pfin,FILE *pfout,enum KIND *sta);//c++ע��ת������

#endif