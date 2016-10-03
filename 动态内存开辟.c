/*void* alloc(int sz)
{
	int *p = (int *)malloc(sz);
	if(p  == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}
	return p;
}
*/
#define MALLOC(N, TYPE)\
	alloc(N*sizeof(TYPE));

int main()
{
	int *p = (int *)malloc(155 * sizeof(int));
	if(p  == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}
	//...
	int i = 0;
	int *ptr = (int *)MALLOC(10, int);
	
	for(i = 0;i<10; i++)
	{
		*(ptr+i) = i;
	}
	for(i = 0;i<10; i++)
	{
		printf("%d\n",*(ptr+i));
	}
	free(ptr);

	return 0;
}