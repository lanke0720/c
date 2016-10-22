#include "test.h"

void note_convert(FILE *pfin,FILE *pfout)//注释转化操作函数
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
void null_state(FILE *pfin,FILE *pfout,enum KIND *sta)//普通字符转换函数
{
	int _f = 0;
	int _s = 0;
	_f = fgetc(pfin);//从intput.c文件中读取一个字符
	switch(_f)
	{
	case '/':
		{
			fputc(_f ,pfout);//将第一个字符输出到output.c文件中
			_s = fgetc(pfin);//读取下一个字符
			switch(_s)
			{
			case '*':  //如果是 ‘/*’   就将‘ *’ 改为 ‘/’ 放入 output.c中
				fputc('/',pfout);
				*sta = C_START; // 进入C语言注释转换函数中
				break;
			case '/':  //如果是// 将_s 输出到output.c 文件中
				fputc(_s,pfout);
				*sta = CPP_START; // 进入cpp注释转换函数中
				break;
			default :
				fputc(_s,pfout);
				break;
			}
		}
	case EOF:  //读取到了文件末尾
		fputc(_f,pfout);
		*sta = END_START;
		break;
	default:  //其他字符
		fputc(_f,pfout);
		break;
	}
}
void c_state(FILE *pfin,FILE *pfout,enum KIND *sta)//c语言注释转换为c++注释函数
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
			ungetc(_s,pfin);// 将之后的内容放到缓存区
			break;
		case '/':
			{
				_t = fgetc(pfin);//判断第三个字符是不是“\n”解决这种注释问题 /*int i=0*/int i=0;
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

void cpp_state(FILE *pfin,FILE *pfout,enum KIND *sta)//c++注释转化函数
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









