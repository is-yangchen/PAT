#include <stdio.h>
#include <stdlib.h>
#incldue <string.h>

int flag[40];

int IsBroken(char ch)
{
	int k;
	if ((ch>='0')&&(ch<='9')) k=ch-'0';
	if ((ch>='a')&&(ch<='z')) k=ch-'a'+10;
	if ((ch>='A')&&(ch<='Z')) k=ch-'A'+10;
	if (ch == '_') k=36;
	if (flag[k]) return 0;
	else {	flag[k] = 1;
			return 1;
		}
}

int main()
{
	char str1[81];str2[81];
	int i,j,len1,len2;

	for (i=0;i<40;i++)	flag[i]=0;
	scanf("%s",&str1);
	scanf("%s",&str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	i=0;j=0;
	while (i<len1)
	{
		if ((str1[i] != str2[j]))
		{
			if (IsBroken(str1[i])) 
			{
				if ((str1[i]>='a')&&(str1[i]<='z')) printf("%c",str1[i]-'a'+'A');
				else printf("%c",str1[i]);
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return 0;

}