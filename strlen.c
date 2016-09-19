#include <string.h>
#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)   //const 增加函数健壮性  //*str 指向字符串首地址
{
	const char *start = NULL;
	assert(str != NULL);      //断言函数
	start = str;
	while(*str++)
	{
		;
	}
	return str-start-1;   //地址相减
}
//int my_strlen(const char* p)
//{
//	if(*p == '\0')
//		return 0;
//	else
//		return 1+my_strlen(++p); //前置++ 先++ 后执行       //"abcdef";
//                                                            //1+"bcdef";
//                                                            //1+1+"cdef";
//}
//
//int my_strlen(const char *p)
//{
//	int count = 0;
//	while(*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}	


int main()
{
	/*char *p1 = "abcdef";
	char *p2 = "abc";
	if(strlen(p2)-strlen(p1)>0)
		printf("p2比p1长\n");
	else
		printf("p1比p2长\n");*/
	int ret = my_strlen("abcdef");
	printf("%d\n", ret);
	return 0;
}
