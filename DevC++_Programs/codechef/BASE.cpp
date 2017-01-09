#include<stdio.h>
int l = 0;
void base(int num){
	int i;
	if(num ==1)
	{
		printf("INFINITY\n");
	}
	else{
	
	for(i=2;i<=num/2;i++)
	{
		int key = num;
		
			while(1)
			{
				//printf("%d %d\n",key,i);
				key = key/i;
				if(key>=i && key<(2*i))
				{
					l++;
					//printf("%d\n",l);
					break;
				}
				else if(i>key)
				{
					break;
				}
				else
				{
					
				}
			}
		
	}
	if(num%2 == 0 )
	{
		l = l + num/2;
	}
	else
	{
		l = l + num/2 +1;
	}
	
	printf("%d\n",l);
	l=0;
}
}

int main()
{
	int test =1;
	scanf("%d",&test);
	int i;
	for(i=0;i<test;i++)
	{
		int n;
		scanf("%d",&n);
		base(n);
	}
}
