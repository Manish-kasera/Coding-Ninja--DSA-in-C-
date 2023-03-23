#include<bits/stdc++.h>
using namespace std;

int ans[20];


// MEMOIZATION (Top Down Approach) 
// find exist or not , save at end
int fiboDP(int n)
{
  if(n <= 1)
  	return n;
  
  // if ans already exits return it
  if(ans[n] != -1)
    return ans[n]; 
  
  // finding the n-1 and n-2 element
  int a = fiboDP(n-1);
  int b = fiboDP(n-2);

  // saving it for future use
  ans[n] = a + b;  
  // returning the ans
  return ans[n];	   
}


// Dynamic Programming (Bottom Up Approach)
// set ans for smaller problems
int fiboIterative(int n)
{
  if(n <= 1)
    return n;

  ans[0] = 0;
  ans[1] = 1;

  for(int i=2; i<=n ;i++)
  {
    ans[i] = ans[i-1] + ans[i-2];
  } 

  return ans[n];
}

// Brute Force Approach
int fibo(int n)
{
	if(n <= 1)
		return n;
    
  int a = fibo(n-1);
  int b = fibo(n-2);
  return a+b;	
}


int main()
{
  //cout << fibo(10) << endl;
  
  // filling ans array with -1 value  
  memset(ans,-1,sizeof(ans));
 
  for(int i=0; i<= 10;i++)    
    cout << fiboDP(i) <<" ";
	
  for(int i=0; i<= 10;i++)    
    cout << fiboIterative(i) <<" ";
  

	return 0;
}