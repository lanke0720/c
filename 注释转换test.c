#include "test.h"

int main()
{
	FILE *pfout = NULL;         //�����ļ�ָ�� ���
	FILE *pfin = NULL;
	pfin = fopen(INPUT,"r");//���ļ������
	if(pfin == NULL)
	{
		perror("not open file");  //��ʾ��λԭ��
		exit(EXIT_FAILURE);        //ʧ�ܵĺ궨����ʾ
	}
	pfout = fopen(OUTPUT,"w");    //д���ļ�
	if(pfout == NULL)
	{
		perror("not open file ");
		fclose(pfin);
		exit(EXIT_FAILURE);
	}
	note_convert(pfin,pfout);     //����ע��ת������
	system("pause");
	return 0;
}
