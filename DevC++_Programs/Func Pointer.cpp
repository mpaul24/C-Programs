//fUNCTION pOINTER

//int *func(int,int) : declaring a function that would return int*

// int (*func)(int,int) : declaring afunction pointer

#include<stdio.h>

int add(int a,int b)
{
	return a+b;
}

int main()
{
	int c;
	int (*p)(int ,int);//declaration of function pointer
	p = &add;// p = add : function name will return us pointer
	c = (*p)(2,3);// we can use p(2,3)
	printf("%d",c);
}
