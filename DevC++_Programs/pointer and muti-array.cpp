//Pointers and Multi-Dimensional Arrays

#include<stdio.h>

int main()
{
	int b[2][3] = {2,3,6,4,5,8};
	
	int (*p)[3] = b;//will return a pointer to 1-D array of 3 integer
	
	printf("%d %d %d\n",*b,*(b+1)+1,b+2);
	printf("%d %d %d\n",b,*b,b[0]);//will give the address of the value 2 OR same as &b[0][0]
	
	
	
	int c[3][2][2] = {2,5,7,9,3,4,6,1,0,8,11,13};
	printf("%d %d %d %d",c,*c,c[0],&c[0][0]);
	// c[i][j][k] = *(c[i][j]+k) = *(*(c[i]+j)+k) = *(*(*(c+i)+j)+k)
	printf("\n%d %d %d",&*(c[0]+1),*(c[0]+1),&(c[0][1][0]));
	
	int* asd;
	int a = 10;
	asd = &a;
	printf("\n%d %d",&a,&asd);
}
