#include<stdio.h>
int flag=1;
void out(int x)
{
 if (flag) printf("%d",x);
   else   {
	printf(",");
	printf("%d",x/100);x %= 100;
	printf("%d",x/10); x %= 10;
	printf("%d",x);
	}
}
int main()
{
  int a,b;
  scanf("%d %d",&a,&b);
  a += b;
  if (a<0) {printf("-");a = -a;}
  if (a/1000000 != 0) { out(a/1000000); a = a % 1000000; flag = 0;}
  if ((a/1000 != 0)|| (!flag)) { out(a/1000); a = a % 1000; flag =0;}
  out(a);
  return 0;
}
