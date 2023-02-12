

// Best Solution Time Complexity O(N)
int findDuplicate(int *arr, int n) {
  int t_sum = 0;
  for (int i = 0; i < n; i++)
    t_sum += arr[i];

  int x = n - 2;
  int originalSum = (x * (x + 1)) / 2;

  return (t_sum - originalSum);
}

// Time Complexity O(N)
#include<bits/stdc++.h>
int findDuplicate(int *arr, int n)
{
   sort(arr,arr+n);

   for(int i=0;i < n;i++)
   {
       if(arr[i] != i)
         return arr[i];
   }
}