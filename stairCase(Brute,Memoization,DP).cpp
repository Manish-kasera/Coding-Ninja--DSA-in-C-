/*

Code : Staircase using Dp

A child is running up a staircase with n steps and can hop either 1 step, 2 steps 
or 3 steps at a time. Implement a method to count how many possible ways the 
child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)

Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.

Output Format:
For each test case print the answer in new line

Constraints :
1 <= T < = 10
1 <= N <= 10^5

Sample input 1
2
2
3

Sample output 1
2
4

Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)

Sample input 2:
2
5
10
Sample output 2:
13
274

*/


#include<bits/stdc++.h>
using namespace std;

int mod = 1000000000+7;
#define ll long long


// BRUTE FORCE
int staircase(ll n)
{
    // n=1 (1) , n=2 (1,1),(2)
    if(n <= 2)
      return n;

    //(1,1,1) ,(2,1),(1,2),(3)
    if(n == 3)
      return 4;  
    
    // there is only three possiblity 
    // we can take 1 or 2 or 3 steps
    ll x = staircase(n-1);
    ll y = staircase(n-2);
    ll z = staircase(n-3);
    
    // adding because we have to find total possible steps 
    return (x+y+z)%mod;  
}


// MEMOIZATION
ll stairCaseMemoization(ll n,ll ans[])
{
    if(n <= 2)
      return n;
    if(n == 3)
      return 4;  
    
    // if ans already exits then return it
    if(ans[n] != -1)
      return ans[n];

    // Calculation  
    ll x = staircase(n-1);
    ll y = staircase(n-2);
    ll z = staircase(n-3);
    
    // saving the answer for future use
    ans[n] = ( x+y+z ) % mod;
    
    return ans[n];  
}


// DP
ll stairCaseDP(ll n,ll ans[])
{

  if(n <= 2)
    return n;

  // Smaller Problem ans
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 4;
   
  // Calculating for i=4 to i<=n 
  for(ll i =4 ;i <= n;i++)
  {
    ans[i] = (ans[i-1] + ans[i-2] + ans[i-3]) % mod;
  } 
  
  return ans[n];
}

int main(){
   
  ll t;
  cin >> t;
  while (t--) {
  ll n;
  cin >> n;
  
  // cout << staircase(n) << endl;
    
  ll ans[n+1] ;
    
  // Putting -1 as default
  memset(ans,-1,sizeof(ans));
 
  // cout << stairCaseMemoization(n,ans) << endl;

  cout << stairCaseDP(n,ans) << endl;
  }
    return 0;
}