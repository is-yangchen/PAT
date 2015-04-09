//将科学计数法恢复成普通的
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10005
char data[MAX_SIZE];
int main()
{
	int i,e,len=0,np;
	int f1,f2;
	char ch;
	for (i=0;i<MAX_SIZE;i++) data[i] = '0';
	scanf("%c",&ch);
	if (ch == '+') f1 = 1;
	else {	f1 = -1;printf("-");}
	scanf("%c",&ch);
	while (ch != 'E')
	{
		if (ch == '.') np = len;
		else 
		{
			data[len] = ch;len++;
		}
		scanf("%c",&ch);
	}
	scanf("%d",&e);
	np += e;
	
	if (np<=0)
	{
		printf("0.");
		for(i=0;i<-np;i++) printf("0");
		for(i=0;i<len;i++) printf("%c",data[i]);
	}
	else
	{
		for (i=0;i<np;i++) printf("%c",data[i]);
		if (np<len) printf(".");
		for (i=np;i<len;i++) printf("%c",data[i]);
	}
	return 0;
}
