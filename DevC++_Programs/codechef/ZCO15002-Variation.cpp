#include<stdio.h>
long long array[65000];

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
	long long N,K,sum=0,i;
	
	scanf("%lld %lld",&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%lld",&array[i]);
	}
	mergeSort(array,0,N-1);
	for(i=0;i<N;i++)
	{
		long long start = i+1;
		long long end = N-1;
		while(start<=end)
		{
			//printf("Hello");
			long long mid = (start+end)/2;
			//printf("Start: %d %d %d %d\n",sum,array[mid],array[start],array[end]);
			if(array[mid]-array[i]<K) start = mid+1;
			else if(array[mid]-array[i]>=K) end = mid-1;
			//printf("End: %d %d %d %d\n",sum,array[mid],array[start],array[end]);
			if(start>end)
			{
				if(end==mid) sum += (N-1-mid);
				else if(end<mid) sum+=(N-start);
				break;
			} 
		}
	}
	printf("%lld\n",sum);
	
	
	
}
