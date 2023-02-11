/*

Binary Search (Recursive)

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 

*/

int helper(int arr[],int start, int end,int key)
{
    if(start > end)
      return -1;
    int mid = (start + end)/2;

    if(arr[mid] == key)
      return mid;
    else if(key > arr[mid])
      return helper(arr,mid+1,end,key);
    else
      return helper(arr,start,mid-1,key);    
}
int binarySearch(int input[], int size, int element) {
  
  return helper(input, 0,size-1,element);
}
