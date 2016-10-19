#include <stdio.h>
#include <stdlib.h>

int Add(int num1, int num2)
{
	return num1+num2;
}
int Sub(int num1, int num2)
{
	return num1-num2;
}

int main(int argc, char *argv[])
{
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	int ret = 0;
	if(argc != 4)
	{
		printf("输入参数有误\n");
		exit(1);
	}
	if(strcmp(argv[1], "-a") == 0)
	*(argv[1]+0)
	if(argv[1][0]=='-')
	{
		switch(argv[1][1])
		{
		case 'a':
			{
				ret = Add(num1, num2);
			}
			break;
		case 's':
			{
				ret = Sub(num1, num2);
			}
			break;
		case 'm':
			int ret = Mul(num1, num2);
			break;
		case 'd':
			int ret = Div(num1, num2);
			break;
		default:
			break;
		}
	}
	printf("%d\n", ret);
	return 0;
}