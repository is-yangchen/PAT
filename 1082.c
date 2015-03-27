#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int flag=0;
int last;
void print(int k,int l)
{
	if (flag)
	{	printf(" ");
		if ((last>3)&&(last<8)&&(l<3)) printf("Wan ");
		if (last-l>1) printf("ling ");
	}
	switch (k)
	{
		case 9:{	printf("jiu");break;}
		case 8:{	printf("ba");break;}
		case 7:{	printf("qi");break;}
		case 6:{	printf("liu");break;}
		case 5:{	printf("wu");break;}
		case 4:{	printf("si");break;}
		case 3:{	printf("san");break;}
		case 2:{	printf("er");break;}
		case 1:{	printf("yi");break;}
	}
	switch (l)
	{
		case 8:{	printf(" Yi");break;}
		case 7:{	printf(" Qian");break;}
		case 6:{	printf(" Bai");break;}
		case 5:{	printf(" Shi");break;}
		case 4:{	printf(" Wan");break;}
		case 3:{	printf(" Qian");break;}
		case 2:{	printf(" Bai");break;}
		case 1:{	printf(" Shi");break;}
		case 0:{	break;}
	}

}
int main()
{
	long data[10];
	long i,k;
	data[0] = 1;
	for (i=1;i<9;i++) data[i] = data[i-1] * 10;
	scanf("%ld",&k);
	if (k<0) {	printf("Fu ");k = -k;}
	//if (k/data[9] > 0) {print(k/data[9],9);last = 9;flag =true;k=k%data[9];}
	if (k/data[8] > 0) {print(k/data[8],8);last = 8;flag =1;k=k%data[8];}
	if (k/data[7] > 0) {print(k/data[7],7);last = 7;flag =1;k=k%data[7];}
	if (k/data[6] > 0) {print(k/data[6],6);last = 6;flag =1;k=k%data[6];}
	if (k/data[5] > 0) {print(k/data[5],5);last = 5;flag =1;k=k%data[5];}
	if (k/data[4] > 0) {print(k/data[4],4);last = 4;flag =1;k=k%data[4];}
	if (k/data[3] > 0) {print(k/data[3],3);last = 3;flag =1;k=k%data[3];}
	if (k/data[2] > 0) {print(k/data[2],2);last = 2;flag =1;k=k%data[2];}
	if (k/data[1] > 0) {print(k/data[1],1);last = 1;flag =1;k=k%data[1];}
	if (k/data[0] > 0) {print(k/data[0],0);last = 0;flag =1;k=k%data[0];}
	if (!flag) printf("ling");
	return 0;	

}