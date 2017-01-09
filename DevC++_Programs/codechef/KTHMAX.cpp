#include<stdio.h>
#include<stdlib.h>

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
	int test=0;
	int i=0;
	scanf("%d",&test);
	while(test--)
	{
		int size,query;
		scanf("%d %d",&size,&query);
		int *array = (int*)malloc(size*sizeof(int));
		for(i=0;i<size;i++)
		{
			scanf("%d",&array[i]);//taking the array elements
		}
		
		int sub = size;
		int total = size*(size+1)/2;//total no of subarray possible
		int **subarray;
		subarray = (int**)malloc(total*sizeof(int*));
		
		int m,n;
		int *final = (int*)malloc(total*sizeof(int));
		
		for(i=0;i<total;i++)
		{
			subarray[i]=(int*) malloc(sub*sizeof(int));
			if(sub == size)
			{//when sub is size
				int p=0;
				for(;p<size;p++)
				{
					subarray[i][p] = array[p];
					
				}
				
				mergeSort(subarray[i],0,size-1);
				final[i] = subarray[i][0];
				//
				sub--;
				i++;
			}
			else
			{//when sub is not size
				int j;				
				for(j=0;j<=size-sub;j++)
				{
					subarray[i]=(int*) malloc(sub*sizeof(int));
					//selecting all possible 'sub' size array
					int g=0;
					int k=0;
					
					for(k=j;k<j+sub;k++)
					{//inserting all the elements in subarray
						subarray[i][g] = array[k];
						g++;
					}
					mergeSort(subarray[i],0,sub-1);
					final[i] = subarray[i][0];
					i++;
				}
				sub--;
			}
			i = i-1;
		}
			
		/*for(i=0;i<total;i++)
		{
			mergeSort(subarray[i],0,size-1);
		}*/
		mergeSort(final,0,total-1);
		/*for(m=0;m<total;m++)
		{
			for(n=0;n<size;n++)
			{
				printf("%d  ",subarray[m][n]);
			}
			printf("\n");
		}
		for(m=0;m<total;m++)
		{
			printf("%d  ",final[m]);
		}*/
		for(i=0;i<query;i++)
		{
			int num;
			scanf("%d",&num);
			num--;
			printf("%d\n",final[num]);
		}
	}
	
}
