
#include<stdio.h>
int odd_num(int arr[],int sz)
{
	int i=0;
	int ret=0;
	for(;i<sz; i++)
	{
		ret=ret^arr[i];
	}
	return ret;
}
int main ()
{
	int arr[]={1,1,3,3,6,8,8};              //{1,1,3,3,6,8,8，7}  拓展问题
	int sz=sizeof(arr)/sizeof(arr[0]); 
	int rs=0;
	rs=odd_num(arr, sz);
	printf("%d",rs);
}  

翻转
unsigned int  reverse_bit(unsigned int num)
{
	unsigned int ret = 0;
	int i = 0;
	for(i = 0; i<32; i++)
	{
		ret += ((num>>i)&1)*pow(2, 31-i);
	}
	return ret;
}
//
//int main()
//{
//	int num = 0;
//	int i = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	for(i=0; i<32; i++)
//	{
//		ret = ret<<1;
//		ret |= ((num>>i)&1);	
//	}
//
//	printf("%u\n", ret);
//	return 0;
//}






int main()
{
	int num = 25;
	printf("%u\n", reverse_bit(num));
	return 0;
}



1.编程实现：
两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
输入例子:
1999 2299
输出例子:7
{
	int ret=m^n;
	int count ++;
	while(ret)
	  {
		if((ret&1)==1)
		{  count++;
		}
	    
	ret>>=1;                            // num _1
	}
	return count ;
}
int count_diff(int m, int n)
{
	int ret = m^n;
	int count = 0;
	while(ret)                     //有多少个 1。
	{
		count++;
		ret = ret&(ret-1);
	}
	return count;
}


int count_diff(int m, int n)
{
	int i = 0;
	int count = 0;
	for(i = 0; i<32; i++)            //有多少个1 。
	{
		if(((m>>i)&1) != ((n>>i)&1))
			count++;
	}
	return count;
}
int main()
{
	int m = 15;//1111
	int n = 10;//1010
	
	int ret = count_diff(m, n);
	printf("%d\n",ret);
	return 0;
}


利用宏定义翻转数字二级制位
#include<stdio.h>
#define SWAP(X) ( ( (X)&(0xaaaaaaaa) )>>1 )+( ( (X)&(0x55555555) )<<1 )
	////10 1010  00000000 00000000 00000000 00001010 
 //              
	//		   10101010 10101010 10101010 10101010
	//	    &= 00000000 00000000 00000000 00001010  
	//		   00000000 00000000 00000000 00000101  >>1   (X&0xaaaaaaaa)>>1  偶数位右移到奇数位置

	//		   01010101 01010101 01010101 01010101     
	//		&= 00000000 00000000 00000000 00000000  <<1   (X&0x55555555)<<1  奇数位置左移到偶数位置
      
int main ()
{
 int X=10;
 printf("%d",SWAP(X));
return 0;
}