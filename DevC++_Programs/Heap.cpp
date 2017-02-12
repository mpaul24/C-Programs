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

void maxHeapify(int* A,int size,int i)
{
	int greatest;
	greatest = i;
	if(LEFT(i)<=size && A[LEFT(i)-1]>A[i-1])
		greatest = LEFT(i);
	if(RIGHT(i)<=size && A[RIGHT(i)-1]>A[greatest-1])
		greatest = RIGHT(i);
	swap(A,i,greatest);
	if(greatest==i) return;//if value at is max out of two children then return, as no further recursive call so function will return
	maxHeapify(A,size,greatest);
}

void buildMaxHeap(int* A,int size)
{
	int i;
	for(i=size/2;i>0;i--)//i>0 because here we are considering from 1 to n (n is the size of heap) 
	{
		int j;
		
		maxHeapify(A,size,i);
		//for(j=0;j<14;j++) printf("%d  ",A[j]);
		//printf("\n");
	}
	//int j;
	//for(j=0;j<14;j++) printf("%d  ",A[j]);
}

void heapSort(int *A,int size)
{
	int temp = size;
	int i,j;
	for(i=0;i<temp;i++){
		swap(A,1,size);
		//A[size-1] = A[0];
		size--;
		maxHeapify(A,size,1);
		//for(j=0;j<14;j++) printf("%d  ",A[j]);
		//printf("\n");
	}
	
}

int main()
{
	int A[14]= {27,17,3,16,13,10,1,5,7,12,4,16,9,0};
	buildMaxHeap(A,14);
	int i;
	for(i=0;i<14;i++) printf("%d  ",A[i]);
	printf("\n");
	heapSort(A,14);
	for(i=0;i<14;i++) printf("%d  ",A[i]);
	
		
}

