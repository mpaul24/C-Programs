#include<stdio.h>
void merge(long long arr[], long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m - l + 1;
    long long n2 =  r - m;
 
    /* create temp arrays */
    long long L[n1], R[n2];
 
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
        if (L[i] >= R[j])
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
void mergeSort(long long arr[], long long l, long long r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long long m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main()
{
	long long sum=0;
	long long N;
	scanf("%lld",&N);
	long long strength[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%lld",&strength[i]); 
	}

	mergeSort(strength,0,N-1);//arranging in decending order
	for(i=0;i<N;i++)
	{
		sum += (strength[i]*(N-1-i) - strength[i]*i);//after position i : strength[i] will be positive and before i : it will be negative
	}
	
	printf("%lld\n",sum);
	return 0;
}
