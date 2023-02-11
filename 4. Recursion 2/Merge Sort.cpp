/*

Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

*/

void merge(int arr[],int l,int mid,int r)
{

	int n1 = mid - l +1;
	int n2 = r -mid;

    // creating two array 
	int arr1[n1],arr2[n2];
   
    // copying data from main array into two half arrays
	for(int i=0;i < n1;i++)
	{
		arr1[i] = arr[l+i];
	}

	for(int j=0;j< n2;j++)
	{
		arr2[j] = arr[mid +1+j];
	}

	int i=0,j=0,k=l;

	while(i < n1 && j < n2)
	{
		if(arr1[i] < arr2[j])
		{
			arr[k++] = arr1[i++];
		}
		else
		{
			arr[k++] = arr2[j++];
		}
	}

	while(i < n1)
	{
		arr[k++] = arr1[i++];
	}

	while(j < n2)
	{
		arr[k++] = arr2[j++];
	}

}

void mergeSortt(int arr[],int l,int r)
{
	if(l >= r)
	  return;

	int mid = (l +r )/2;
    
	// Dividing into two half
	mergeSortt(arr,l, mid);
	mergeSortt(arr,mid+1,r);

	// merging two sorted array
	merge(arr,l,mid,r);  
}

void mergeSort(int input[], int size){
	mergeSortt(input,0,size-1);  
}
