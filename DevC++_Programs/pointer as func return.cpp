//Pointer as Function returns

/*
	
	it is always prefered to pass data from bottom to top w.r.t stack
	because upper level stack allocation can be deallocated
	and which may be dangerous
	only happens when passes a pointer as return value
	
*/

#include<stdio.h>
#include<stdlib.h>
void print(){
	printf("Hello World!\n");
}
int *add(int *a,int *b)
{
	/*int c  = (*a)+(*b);
	return &c;*/
	//to avoid the problem
	
	int *c  = (int*)malloc(sizeof(int));//here deallocation is not done immediately as data is allocated in heap
	*c = (*a) + (*b);
	return c;
}

int main()
{
	int a =2,b=4;
	int *ptr = add(&a,&b);
	print();
	printf("%d\n",*ptr);//because stack memory is deallocated and then it has some garbage value
}
