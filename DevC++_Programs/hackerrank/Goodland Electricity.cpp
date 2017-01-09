#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int city[n];
	int lastTower=-1,lastNoTower=-1,noTower=-1,tower=-1;
	int sum=0;
	int f=0,i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&city[i]);
	}
	for(i=0;i<n;i++)
	{
		if(!city[i])
		{
			if(lastNoTower==-1)
				lastNoTower = i;
			noTower=i;
			if(i!=0){
			
			/*if(noTower-tower==k-1)
			{
				printf("%d\n",i);
				
			}*/
			if(noTower-lastNoTower==k-1)
			{
				if(tower==-1)
				{
					f=1;
					noTower=-1;
					tower=-1;
					lastNoTower=-1;
					lastTower=-1;
					break;
				}
				printf("A:%d %d\n",i,tower);
				sum++;
				i=tower+k-1;
				noTower=-1;
				tower=-1;
				lastNoTower=-1;
				lastTower=-1;
				//printf("A:%d\n",i);
			}
			else if(lastTower-lastNoTower==k-1)
			{
				printf("B:%d %d\n",i,tower);
				i=tower+k-1;
				sum++;
				noTower=-1;
				tower=-1;
				lastNoTower=-1;
				lastTower=-1;
			}
		}
		}
		else
		{
			if(lastTower==-1) lastTower=i;
			tower=i;
			if(i!=0){
			
			if(tower-lastNoTower==k-1)
			{
				printf("C:%d %d\n",i,tower);
				sum++;
				noTower=-1;
				tower=-1;
				lastNoTower=-1;
				lastTower=-1;
				i=i+k-1;
			}
			else if(tower-lastTower==k-1)
			{
				printf("D:%d %d\n",i,tower);
				sum++;
				noTower=-1;
				tower=-1;
				lastNoTower=-1;
				lastTower=-1;
				i=i+k-1;
			}
		}
			
		}
	}
	if(tower==-1 && noTower!=-1)
	{
		f=1;
	}
	else{
		sum++;
	}
	if(f==1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",sum);
	}
}
