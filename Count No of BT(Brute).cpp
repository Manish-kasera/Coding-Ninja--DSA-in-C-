
/*

Code : No. of balanced BTs Brute
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).

Input Format :
The first and only line of input contains an integer, that denotes the value of h. 
Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees 
modulus 10^9 + 7.

Constraints :
1 <= h <= 10^6
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315

*/

#define ll long long
ll mod = 1000000000+ 7;


// BRUTE FORCE
int balancedBTs(int n) {
    
    if(n <= 1)
      return 1;
    
    // ll x = (balancedBTs(n-1) * balancedBTs(n-1)) % mod;
    // ll y = (balancedBTs(n-1) * balancedBTs(n-2)) % mod;
    // ll z = (balancedBTs(n-2) * balancedBTs(n-1)) % mod;
    
    // return ((x+y+z) % mod);


    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;

}