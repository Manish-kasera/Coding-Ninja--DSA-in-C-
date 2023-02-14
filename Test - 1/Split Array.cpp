/*

Split Array
Send Feedback
Given an integer array A of size N, check if the input array can be splitted 
in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) 
should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous.
And you need to consider each and every element of input array in some group.

Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false
Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2

Sample Output 1 :
false

Sample Input 2 :
3
1 4 3

Sample Output 2 :
true


*/

bool helper(int arr[],int i,int n,int sum1,int sum2)
{
    if(i == n)
    {
        if(sum1 == sum2)
           return true;

        return false;   
    }

    if(arr[i] % 5 == 0)
    {
        return helper(arr,i+1,n,sum1+arr[i],sum2);
    }
    else if(arr[i]% 3 == 0)
    {
      return helper(arr, i + 1, n, sum1, sum2+ arr[i]);
    }
    else
    {
      // as the rest element which are not divisible by 3 or 5 can be added in both sums
      return helper(arr, i + 1, n, sum1 + arr[i], sum2)  || helper(arr, i + 1, n, sum1, sum2+ arr[i]) ;
    }
}

bool splitArray(int *input, int size) {
    int sum1=0 , sum2 =0;
    return helper(input,0,size,sum1,sum2);
}
