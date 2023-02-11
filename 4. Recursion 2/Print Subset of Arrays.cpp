/*

Print Subsets of Array

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12


*/


#include<bits/stdc++.h>

void helper(int input[],int i,int n,vector <int> v)
{
	if(i > n)
	{
		for(auto x: v)
		{
			cout << x <<" ";
		}
		cout << endl;
		v.clear();
		return;
	}
	
	// pushing the element and calling for i+1 element
	v.push_back(input[i]);
	helper(input,i+1,n,v);

	// backtrack(when returning back we must have tp pop that included element)
	v.pop_back();
	
	// not inclding the element
	helper(input,i+1,n,v);

}

void printSubsetsOfArray(int input[], int size) {
	
	vector <int> ans;

	return helper(input,0,size-1,ans);

}
