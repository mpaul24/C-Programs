#include<stdio.h>

int main()
{
	int test,n;
	scanf("%d %d",&test,&n);
	char array[n][n];
	int i;
	fflush(stdin);
	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			char c;
			scanf("%c",&c);
			//int temp = c-'a';
			//printf("%d %c",temp,c);
			array[i][j]=c;
			fflush(stdin);
		}
	}
	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			printf("%c ",array[i][j]);
		}
	}
	
}
