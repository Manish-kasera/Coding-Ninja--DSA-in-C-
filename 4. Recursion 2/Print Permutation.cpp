/*

Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be 
the same permutations.
The order of permutations doesn’t matter.

Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line

Constraint:
1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

*/

#include <iostream>
#include <string>
using namespace std;

void helper(string input,int l,int r)
{
	// base case
  if (l == r) {
    cout << input << endl;
   	return;
  } 
  else 
  { 
	for(int i=l ;i <= r;i++)
	{
		// swapping and fixing a character
		swap(input[l] , input[i]);

		// calling helper to find permutation of rest string 
		helper(input,l+1,r);
		
		// backtrack
		swap(input[l],input[i]);
	}
  }
}

void printPermutations(string input){
   
   helper(input,0,input.size()-1);
   return ;
}
