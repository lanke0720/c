#include <string.h>
#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)   //const ���Ӻ�����׳��  //*str ָ���ַ����׵�ַ
{
	const char *start = NULL;
	assert(str != NULL);      //���Ժ���
	start = str;
	while(*str++)
	{
		;
	}
	return str-start-1;   //��ַ���
}
//int my_strlen(const char* p)
//{
//	if(*p == '\0')
//		return 0;
//	else
//		return 1+my_strlen(++p); //ǰ��++ ��++ ��ִ��       //"abcdef";
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
		printf("p2��p1��\n");
	else
		printf("p1��p2��\n");*/
	int ret = my_strlen("abcdef");
	printf("%d\n", ret);
	return 0;
}
