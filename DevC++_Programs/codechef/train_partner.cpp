#include<stdio.h>

void neig(int a)
{
	int x = a%8;
	switch(x)
	{
		case 0 :
			printf("%dSL\n",(a-1));
			break;
		case 1:
			printf("%dLB\n",(a+3));
			break;
		case 2:
			printf("%dMB\n",(a+3));
			break;
		case 3:
			printf("%dUB\n",(a+3));
			break;
		case 4:
			printf("%dLB\n",(a-3));
			break;
		case 5:
			printf("%dMB\n",(a-3));
			break;
		case 6:
			printf("%dUB\n",(a-3));
			break;
		case 7:
			printf("%dSU\n",(a+1));
			break;
	}
}

int main()
{
	int count;
	scanf("%d",&count);
	int i;
	for(i=0;i<count;i++)
	{
		int a;
		scanf("%d",&a);
		neig(a);
	}
}
