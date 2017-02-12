#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct Bowler{
	int position;
	int balls;
}bowler;

int LEFT(int i){
	return 2*i;
}
 	
int RIGHT(int i){
	return 2*i+1;
}
	
int PARENT(int i){
	return i/2;
}
	
void maxBuildHeap(bowler *b,int size,int i)
{
	int max = PARENT(i);
	if(PARENT(i)>0 && b[PARENT(i)-1].balls<=b[i-1].balls)
	{
		//b[PARENT(i)-1].position<=b[i-1].balls
		max = i;
	}
	swap(b,max,i);
	if(max==PARENT(i)) return;
	maxBuildHeap(b,size,max);
}

void maxHeapify(bowler *b,int size,int i)
{
	int max = i;
	if(LEFT(i)<=size && RIGHT(i)<=size && b[LEFT(i)-1]==b[i-1])
	if(LEFT(i)<=size && b[LEFT(i)-1].balls>=b[i-1].balls)
	{
		if(b[LEFT(i)-1].balls==b[i-1].balls)
		{
			if(b[LEFT(i)-1].position<b[i-1].balls)
		}
	}
}

int insert(bowler *b,int size,bowler element)
{
	b[size] = element;
	size++;
	maxBuildHeap(b,size,size);
	return size;
}

int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	bowler b[n];
	int i;
	int size = 0;
	for(i=0;i<n;i++)
	{
		//b = (bowler*) malloc (n*sizeof(bowler));
		scanf("%d",&b[i].balls);
		b[i].position=i;
		size = insert(b,size,b[i]);
	}
	
	
}
