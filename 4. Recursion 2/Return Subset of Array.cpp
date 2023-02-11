/*

Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note : The order of subsets are not important.


Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

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


int helper(int input[],int n,int startIndex,int output[][20])
{
    if(startIndex == n)
	{
		output[0][0] = 0;
		return 1;
	}

	int smallSize = helper(input,n,startIndex+1,output);

	for(int i=0; i< smallSize;i++)
	{
		output[i+smallSize][0] = output[i][0] +1;
        output[i + smallSize][1] = input[startIndex];

		for(int j=1;j<= output[i][0];j++)
		{
			output[i+smallSize][j+1] = output[i][j];
		}
    }

	return 2 * smallSize;
}

int subset(int input[], int n, int output[][20]) {

   return helper(input,n,0,output);
}





// Returning vector<vector<int>> as a answer

#include<bits/stdc++.h>
using namespace std;

void helper(int input[],int i,int n,vector<vector<int>> &v,vector<int> temp)
{
	if(i > n)
	{
		v.push_back(temp);
		temp.clear();
		return;
	}


	temp.push_back(input[i]);
    helper(input,i+1,n,v,temp);
    temp.pop_back();
     
	helper(input,i+1,n,v,temp);
}

vector<vector<int>>  subset(int input[], int n, int output[][20]) {
   
   vector<vector<int>> v;
   vector <int> temp;
   
   helper(input,0,n,v,temp);
    
    return  v;


}
