/*

Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
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
Sample Input 2 :

*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot = arr[start];
    int count = 0;
    
    for(int i=start+1;i <= end;i++)
    {
        if(pivot >= arr[i])
            count++;
    }
    // cout << count << endl;
    
    int pivotIndex = start+count;
    swap(arr[start],arr[pivotIndex]);
    
    int i=start,j=end;
    
    while( i <= j)
    {
        if(arr[i] <= pivot)
            i++;
        else if(arr[j] > pivot)
            j--;
        else
            swap(arr[i++],arr[j--]);
    }
    
    return pivotIndex; 
}

void QuickSort(int arr[],int start,int end)
{
    if(start >= end)
        return;
    
    int p = partition(arr,start,end);

    QuickSort(arr,start,p-1);
    QuickSort(arr,p+1,end);
}

void quickSort(int input[], int size) {
  
    int start = 0 ,end = size - 1;
    
    QuickSort(input,start,end);
}