/*

Triplet sum
Send Feedback
You have been given a random integer array/list(ARR) and a number X. Find 
and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases 
or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the 
size of the first array/list.

Second line contains 'N' single space separated integers representing the 
elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5


*/


// Not the Best Solution
int tripletSum(int *arr, int n, int num)
{
	 int ans = 0;
 
    // Fix the first element as A[i]
    for (int i = 0; i < n - 2; i++) {
 
        // Fix the second element as A[j]
        for (int j = i + 1; j < n - 1; j++) {
 
            // Now look for the third number
            for (int k = j + 1; k < n; k++)
 
                if (arr[i] + arr[j] + arr[k] ==num)
                    ans++;
        }
    }
 
    return ans;
}