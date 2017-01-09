//Character Arrays and Pointers

//size of array >= no of characters in string + 1
// null character is placed at last i.e '\0'
//null terminal is implicit

#include<stdio.h>
#include<string.h>

int main(){
	char c[] = "JOHN"; //cannot keep size of c 4 here
	int a[] = {1,2,3,4,5};
	int size = sizeof(c)/sizeof(c[0]);
	size = strlen(c);
	printf("%s %d\n",c,size);
	int i;
	char* ab = c;//size of character pointer is 8 byte
	for(i=0;i<5;i++){
		printf("%c",*(ab++));//ab++ is allowed but c++ is not allowed
		printf("%d\n",(c+i));//in memory it shows memory locations with a difference of 1
	}
	
	char *acs = "Hello";//string is stored as compile time constant
	
}
