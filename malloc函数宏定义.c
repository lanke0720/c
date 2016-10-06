//void *alloc(int num)
//{
//	void *p = malloc(num);
//	if(p == NULL)
//	{
//		printf("out of memory\n");
//		exit(EXIT_FAILURE);
//	}
//	return p;
//}
//
//#define MALLOC(num, type)\
//	(type*)alloc(num*sizeof(type))
//
//
//int main()
//{
//	//int *parr = (int *)malloc(10*sizeof(int));
//	int *parr = (int *)MALLOC(10, int);
//	/*if(parr == NULL)
//	{
//		printf("out of memory\n");
//		exit(EXIT_FAILURE);
//	}*/
//
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//		//parr[i] = i;
//		*(parr+i) = i;
//	}
//	print_arr(parr, 10);
//
//	free(parr);
//	parr = NULL;
//	return 0;
//}