//最长后缀
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int n,i,max,tmp,len1,len2;
	char str1[260],str2[260];
	scanf("%d\n",&n);
	gets(&str1);
	len1 = strlen(str1);
	max = len1;
	for (i=1;i<n;i++)
	{
		gets(&str2);
		len2 = strlen(str2);
		if (len2 < max) max = len2;
		if (max>0)
		{
			tmp=0;
			while ((tmp<max)&&(str1[len1-1-tmp]==str2[len2-1-tmp])) tmp++;	
		}
		max = tmp;
	}
	if (max > 0)
		for (i=len1-max;i<len1;i++) printf("%c",str1[i]);
	else
		printf("nai");
	return 0;
}