//Pointer and Dynamic Memory
/*
	C:
		malloc : return void pointer which is type casted to desirable pointer type
		calloc : all elements are initialised to zero
		realloc
		free
	C++:
		new 
		delete
		
		realloc(pointer that is to be entended,size)
		
			realloc(A,2*n*sizeof(int))
			
			realloc(NULL,n*sizeof(int)) == malloc(n*sizeof(int))
			
			realloc(A,0) == free(A)

	
		
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n;
	scanf("%d",&n);
	int *a = (int*)malloc(n*sizeof(int));
	
}

