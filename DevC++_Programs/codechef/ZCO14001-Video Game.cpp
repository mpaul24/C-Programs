#include<stdio.h>

int main()
{
	int width,maxHeight;
	scanf("%d %d",&width,&maxHeight);
	int game[width];
	int i;
	for(i=0;i<width;i++)
	{
		int boxes;
		scanf("%d",&boxes);
		game[i]=boxes;
	}
	int pointer=0;
	int picked;
	int loop = 1;
	while(loop)
	{
		int move=0;
		scanf("%d",&move);
		switch(move)
		{
			case 1:
				//move left
				if(pointer!=0)
				{
					pointer--;
				}
				break;
			case 2:
				if(pointer!=(width-1))
				{
					pointer++;
				}
				//move right
				break;
			case 3:
				if(picked!=1 && game[pointer]>0)
				{
					picked = 1;
					game[pointer]--;
					//printf("Picked: %d %d\n",pointer,game[pointer]);
				}
				//pick up box
				break;
			case 4:
				if(picked==1 && game[pointer]<maxHeight)
				{
					picked=0;
					game[pointer]++;
					//printf("Drop: %d %d\n",pointer,game[pointer]);
				}
				//drop box
				break;
			case 0:
				//Quit
				for(i=0;i<width;i++)
				{
					printf("%d ",game[i]);
				}
				printf("\n");
				loop =0;
				break;
		}
	}
}
