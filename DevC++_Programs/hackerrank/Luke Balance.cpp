#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	int array1[N];
	int sum = 0,j=0;
	int i;
	for(i=0;i<N;i++)
	{
		int L,T;
		scanf("%d %d",&L,&T);
		if(T==0)
		{
			sum+= L;
		}
		else
		{
			array1[j] = L;
			j++;
		}
	}
	mergeSort(array1,0,j-1);
	if(K<j){
		i = j-K;
		for(;i<j;i++)
		{
			sum+= array1[i];
			//printf("Add: %d %d",sum,array1[i]);
		}
		for(i=0;i<(j-K);i++)
		{
			sum-= array1[i];
			//printf("Subtract: %d %d",sum,array1[i]);
		}
	}	
	else
	{
		for(i=0;i<j;i++)
		{
			sum+= array1[i];
			//printf("ADDDD: %d %d\n",sum,array1[i]);
		}
	}
		
	
		
	
	
	
	printf("%d\n",sum);
	
	
}
