//Arrays as Function argument
//always passed as reference   (CALL BY REFERENCE)
//values changed in calling function will change the value in main thread

#include<stdio.h>

int sumOfElements(int A[],int size)//int a[] = int* a
{
	int i,sum=0;
	//here A is nothing but a pointer to the first element of the array in main thread
	int size = sizeof(A)/sizeof(A[0]);//so this will give the value 1
	for(i=0;i<size;i++)
	{
		sum+=A[i];
	}
	return sum;
}
int main()
{
	int A[] = {1,2,3,4,5};
	int size = sizeof(A)/sizeof(A[0]);//this will give value 5
	int total = sumOfElements(A,size);
	printf("%d",total);
}
