#include<stdio.h>
void bubble_sort(int list[], int n)
{
  int c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int array[4];
		int i;
		int zero=0,neg=0;
		for(i=0;i<4;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp==0)
			{
				zero=1;
				break;
			}
			else
			{
				array[i]=temp;
				if(temp<0)
				{
					neg++;
				}
			}
		}
		if(zero)
		{
			printf("yes\n");
		}
		else if(neg<4 && neg>0)
		{
			bubble_sort(array,4);
			for(i=0;i<4;i++)
			{
				printf("%d\n",array[i]);
			}
			int sub=0;
			if(neg==1)
			{
				for(i=1;i<4;i++)
				{
					sub += array[i]-array[0];
				}
				if(sub==(2*array[0]))
				{
					printf("yes\n");
				}
				else
				{
					printf("%d no\n",sub);
				}
			}
			else if(neg==2)
			{
				for(i=2;i<4;i++)
				{
					sub += 2*array[i]-array[0]-array[1];
				}
				if(sub==0)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else if(neg==3)
			{
				for(i=0;i<3;i++)
				{
					sub += array[4]-array[i];
				}
				if(sub==(2*array[4]))
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
		}
		else
		{
			printf("no\n");
		}
	}
}
