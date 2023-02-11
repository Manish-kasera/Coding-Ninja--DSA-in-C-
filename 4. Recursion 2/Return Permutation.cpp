/*

Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations 
will also be duplicates.

Input Format :
String S
Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/

#include <string>
#include<bits/stdc++.h>
using namespace std;

void helper(string input,int l,int r,vector <string> &v)
{
   if(l == r)
     v.push_back(input);
    else
	{
	 for(int i=l ;i <=r;i++)
	 {
		swap(input[l],input[i]);
         helper(input,l+1,r,v);
        swap(input[l], input[i]);
     }
	}	 
}


int returnPermutations(string input, string output[]){
   	
	vector <string> v;

	helper(input,0,input.size()-1,v);

	for(int i=0;i < v.size();i++)
	{
		output[i] = v[i];
	}

	return v.size();


}
