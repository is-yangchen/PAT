#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long long gcd(long long b,long long d)
{
	long long x;
	while (d != 0)
	{
		x = b%d;
		b = d;
		d = x;
	}
	return b;

}
int main()
{
	int N,i,j,flag;
	long long a,b,c,d,tmp,tmpA,tmpB;
	scanf("%d",&N);
	scanf("%lld/%lld",&a,&b);
	for (i=1;i<N;i++)
	{
		scanf("%lld/%lld",&c,&d);
		tmp = gcd(b,d);
		tmpA = d/tmp *a+b/tmp *c;
		tmpB = b/tmp *d;
		tmp = gcd(tmpA,tmpB);
		a = tmpA / tmp;
		b = tmpB / tmp;
	}
	flag = 1;
	if (a/b>0){ printf("%lld",a/b); flag =0;}
	if ((!flag)&&(a%b>0)) printf(" ");
	if ((a%b>0)||(flag)) 
	{	printf("%lld",a%b);
		if (a%b>0) printf("/%lld",b);
	}
	return 0;
}