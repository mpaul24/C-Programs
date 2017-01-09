//time limit exceeded

#include<stdio.h>



int b_gcd(int a,int b)
{
	if(a==b)
	{
		return a;
	}
	else if(a==0)
	{
		return b;
	}
	else if(b==0)
	{
		return a;
	}
	else if(a%2==0 && b%2==0)
	{
		return (b_gcd(a/2,b/2)*2);
	}
	else if(a%2==0 && b%2==1)
	{
		return b_gcd(a/2,b);
	}
	else if(a%2==1 && b%2==0)
	{
		return b_gcd(a,b/2);
	}
	else if(a%2==1 && b%2==1)
	{
		if(a>=b)
		{
			return b_gcd((a-b)/2,b);
		}
		else
		{
			return b_gcd((b-a)/2,a);
		}
	}
}

int clear = 0;
int direct = 0;

/*bool gcd(int a,int b){
	if(a==b && a!=1)
	{
		return true;
	}
	else if(a<b)
	{
		int i;
		for(i=a;i>1;i--)
		{
			if(a%i==0 && b%i==0)
			{
				return true;	
			}	
		}
	}
	else if(a>b)
	{
		int i;
		for(i=b;i>1;i--)
		{
			if(a%i==0 && b%i==0)
			{
				return true;	
			}	
		}
	}
	else
	{
		return false;
	}
	return false;
}*/

int main()
{
	int count;
	scanf("%d",&count);
	int i;
	for(i=0;i<count;i++)
	{
		int rooms;
		scanf("%d",&rooms);
		int j;
		int array[rooms];
		for(j=0;j<rooms;j++)
		{
			scanf("%d",&array[j]);	
		}	
		for(j=0;j<(rooms-1);j++)
		{
			int abc = b_gcd(array[j],array[j+1]);
			printf("%d %d : %d\n",array[j],array[j+1],abc);
			if(abc!=0 && abc!=1)//gcd(array[j],array[j+1])
			{
				direct++;
			}
			else
			{
				int k=j+2;
				int l = j;
				int prev = clear;
				for(;k<=(rooms-1);k++)
				{
					int abcd = b_gcd(array[l],array[k]);
					printf("%d %d : %d\n",array[l],array[k],abcd);
					if(abcd!=1 && abcd!=0)//gcd(array[l],array[k])
						{
							j = k-1;
							clear++;
							break;	
						}
				}			
					
					
			}
		}
		if(direct == rooms-1){
			direct++;
		}
		if(clear>0)
		{
			clear++;
		}
		printf("%d\n",(direct+clear));
		clear = 0;
		direct = 0;
	}	
}
