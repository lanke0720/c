#include "test.h"

void note_convert(FILE *pfin,FILE *pfout)//ע��ת����������
{
	int input = 0;
	int output = 0;
	enum KIND sta =  NULL_START;
	while (sta != END_START)
	{
		switch (sta)
		{
		case NULL_START:
			null_state(pfin,pfout,&sta);
			break;
		case C_START:
			c_state(pfin,pfout,&sta);
			break;
		case CPP_START:
			cpp_state(pfin,pfout,&sta);
			break;
		case END_START:
			break;
		default:
			break;
		}
	}
	printf("converted! ");
	fclose(pfin);
	fclose(pfout);
}
void null_state(FILE *pfin,FILE *pfout,enum KIND *sta)//��ͨ�ַ�ת������
{
	int _f = 0;
	int _s = 0;
	_f = fgetc(pfin);//��intput.c�ļ��ж�ȡһ���ַ�
	switch(_f)
	{
	case '/':
		{
			fputc(_f ,pfout);//����һ���ַ������output.c�ļ���
			_s = fgetc(pfin);//��ȡ��һ���ַ�
			switch(_s)
			{
			case '*':  //����� ��/*��   �ͽ��� *�� ��Ϊ ��/�� ���� output.c��
				fputc('/',pfout);
				*sta = C_START; // ����C����ע��ת��������
				break;
			case '/':  //�����// ��_s �����output.c �ļ���
				fputc(_s,pfout);
				*sta = CPP_START; // ����cppע��ת��������
				break;
			default :
				fputc(_s,pfout);
				break;
			}
		}
	case EOF:  //��ȡ�����ļ�ĩβ
		fputc(_f,pfout);
		*sta = END_START;
		break;
	default:  //�����ַ�
		fputc(_f,pfout);
		break;
	}
}
void c_state(FILE *pfin,FILE *pfout,enum KIND *sta)//c����ע��ת��Ϊc++ע�ͺ���
{
	int _f = 0;
	int _s = 0;
	int _t = 0;
	_f = fgetc(pfin);
	switch(_f)
	{
	case '/':
		fputc(_f,pfout);
		break;
	case '*':
		_s = fgetc(pfin);
		switch(_s)
		{
		case '*':
			fputc(_f,pfout);
			ungetc(_s,pfin);// ��֮������ݷŵ�������
			break;
		case '/':
			{
				_t = fgetc(pfin);//�жϵ������ַ��ǲ��ǡ�\n���������ע������ /*int i=0*/int i=0;
				*sta = NULL_START;
				if(_t =='\n')
				{
					fputc('\n',pfout);
				}
				else
				{
					fputc('\n',pfout);
					ungetc(_t,pfin);
				}
				break;
			}	
		default:
			fputc(_f,pfout);
			fputc(_s,pfout);
			break;
		}
		break;
	case '\n':
	 	{
			_s = fgetc(pfin);
			switch(_s)
			{
			case '*':
				{
					_t = fgetc(pfin);
					if(_t == '/')
					{

						fputc('\n',pfout);
						*sta = NULL_START;
					}
					else
					{
						fputc('/',pfout);
						fputc('/',pfout);
						fputc(_s,pfout);
						fputc(_t,pfout);
					}
					break;
				}
			default:
				fputc('\n',pfout);
				fputc('/',pfout);
				fputc('/',pfout);
				ungetc(_s,pfin);
				break;
			}
			break;
		}
	default:
		fputc(_f,pfout);
		break;
		}
}

void cpp_state(FILE *pfin,FILE *pfout,enum KIND *sta)//c++ע��ת������
{
	int _f = 0;
	_f = fgetc(pfin);
	switch(_f)
	{
	case '\n':
		{
			fputc(_f , pfout);
			*sta = NULL_START;
			break;
		}
	default:
		{
			fputc(_f,pfout);
			break;
		}
	}
}









