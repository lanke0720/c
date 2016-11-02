#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <my_head.h>
#include <stdlib.h>
#include <limits.h>

//
//typedef struct S
//{
//	int num;
//	int arr[0];//arr
//}S,*Ps_t;
//
//typedef struct Stu
//{
//	int num;
//	int *arr;
//}Stu;
//int main()
//{
//	//printf("%d\n", sizeof(struct S));
//	/*int i = 0;
//	struct S*ps = (Ps_t)malloc(sizeof(S)+ 100*sizeof(int));
//	ps->num = 100;
//	for(i=0; i<100; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for(i=0; i<100; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps);*/
//	Stu *pstu = malloc(sizeof(Stu));
//	int i = 0;
//	pstu->arr = (int *)malloc(100 *sizeof(int));
//	for(i=0; i<100; i++)
//	{
//		pstu->arr[i] = i;
//	}
//	for(i=0; i<100; i++)
//	{
//		printf("%d ", pstu->arr[i]);
//	}
//	free(pstu->arr);
//	free(pstu);
//
//	return 0;
//}
