#include<stdio.h>
long long hard[100000];

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
	long long N=0,K=0;
	long long sum=0;
	scanf("%d %d",&N,&K);
	long long g=0;
	long long i=0;
	//long long hard[N];
	for(i=0;i<N;i++)
	{
		long long temp ;
		scanf("%lld",&temp);
		if(temp<K)
		{
			hard[g] = temp;
			g++;
		}
	}
	mergeSort(hard,0,g-1);
	long long m = K-hard[0];
	for(i=0;i<g;i++)
	{long long h = K-hard[i];
		long long start = i+1;
		long long end = g-1;
		/*if(i!=0)
		{
			if(hard[i] == hard[i-1])
				continue;
		}*/
		while(start<=end)
		{
			long long mid = (start+end)/2;
			//printf("Start: %d %d %d %d\n",sum,hard[mid],hard[start],hard[end]);
			if(hard[i]+hard[mid]<K) start = mid +1;
			else if(hard[i]+hard[mid]>=K) end = mid -1; 
			//printf("End: %d %d %d %d\n",sum,hard[mid],hard[start],hard[end]);
			if(start>end)
			{
				if(mid==end)  sum += (mid-i);
				if(mid>end)  sum += (end-i);
				break;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
