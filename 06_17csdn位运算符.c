
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
	int arr[]={1,1,3,3,6,8,8};              //{1,1,3,3,6,8,8��7}  ��չ����
	int sz=sizeof(arr)/sizeof(arr[0]); 
	int rs=0;
	rs=odd_num(arr, sz);
	printf("%d",rs);
}  

��ת
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



1.���ʵ�֣�
����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
��������:
1999 2299
�������:7
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
	while(ret)                     //�ж��ٸ� 1��
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
	for(i = 0; i<32; i++)            //�ж��ٸ�1 ��
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


���ú궨�巭ת���ֶ�����λ
#include<stdio.h>
#define SWAP(X) ( ( (X)&(0xaaaaaaaa) )>>1 )+( ( (X)&(0x55555555) )<<1 )
	////10 1010  00000000 00000000 00000000 00001010 
 //              
	//		   10101010 10101010 10101010 10101010
	//	    &= 00000000 00000000 00000000 00001010  
	//		   00000000 00000000 00000000 00000101  >>1   (X&0xaaaaaaaa)>>1  ż��λ���Ƶ�����λ��

	//		   01010101 01010101 01010101 01010101     
	//		&= 00000000 00000000 00000000 00000000  <<1   (X&0x55555555)<<1  ����λ�����Ƶ�ż��λ��
      
int main ()
{
 int X=10;
 printf("%d",SWAP(X));
return 0;
}