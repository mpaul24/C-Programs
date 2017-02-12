#include<stdio.h>


int PARENT(int i)
{
	return (i/2);
}
int LEFT(int i)
{
	return (2*i);
}
int RIGHT(int i)
{
	return (2*i+1);
}
void swap(int* A,int i,int j)
{
	int temp = A[i-1];
	A[i-1] = A[j-1];
	A[j-1] = temp;
}

void minHeapify(int *A,int size,int i)
{
	int least = i;
	if(LEFT(i)<=size && A[LEFT(i)-1]<A[i])
		least = LEFT(i);
	if(RIGHT(i)<=size && A[RIGHT(i)]<A[least-1])
		least = RIGHT(i);
	if(least==i) return;
	minHeapify(A,size,least);
}

void minHeap(int *A,int size,int i)
{
	int max = i;
	if(i>0 && A[PARENT(i)-1]>A[i-1])
		max = PARENT(i);
	swap(A,i,max);
	if(max==i) return;
	minHeap(A,size,max);
}

int insert(int *A,int size,int element)
{
	size++;
	A[size-1] = element;
	minHeap(A,size,size);
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d  ",A[i]);
	}
	printf(" \n");
	return size;
}

int main()
{
	int size = 0,num;
	int A[100];
	while(1)
	{
		scanf("%d",&num);
		size = insert(A,size,num);
		min = 
	}
}
