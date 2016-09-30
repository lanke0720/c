void print(int num)
{
	if(num > 10)
		print(num/10);
	printf("%d ", num%10);   //上一个语句执行完才可以执行 
}
int main()
{
	int num = 1234;
	//123 + 4
	//12 + 3 + 4
	//1 2 3 4
	print(num);
	return 0;
}
	
//

int fib(int n)
{
	if(n<=2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d\n", ret);
	return 0;
}

//
//int fib(int n)
//{
//	int num1 = 1;
//	int num2 = 1;
//	int num3 = num1;
//	while(n>2)
//	{
//		num3 = num1+num2;
//		num1 = num2;
//		num2 = num3;
//		n--;
//	}
//	return num3;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = _fib(n);
//	printf("%d\n", ret);
//	printf("count = %d\n", count);
//	return 0;
//}