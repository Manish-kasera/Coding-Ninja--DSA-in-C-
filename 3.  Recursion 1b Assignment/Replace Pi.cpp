/*

Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" 
have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 

Sample Input 1 :
xpix
Sample Output :
x3.14x

Sample Input 2 :
pipi
Sample Output :
3.143.14

Sample Input 3 :
pip
Sample Output :
3.14p

Constraints:-
1<=|S|<=50

*/

// Change in the given string itself. So no need to return or print anything


#include<bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
   
    if(input[0] == '\0')
       return;
    
	if(input[0] == 'p' && input[1] == 'i')
	{
        int n = strlen(input);
        int i = n - 1;
        for (; i >= 2; i--) 
		{
          input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';

        input[n + 2] = '\0';
        replacePi(input + 1);
        }
	else
	{
		replacePi(input+1);
	}
}





// Using Helper Function

#include<bits/stdc++.h>
using namespace std;

void helper(char input[],int i,int n,string &s)
{
	if(i == n)
	  return;

	if(input[i] =='p'  && input[i+1] == 'i' )
	{
		s += "3.14";
	   i++;
	}  
	else
	{
		s += input[i];
	}

	helper(input,i+1,n,s);
}

void replacePi(char input[]) {
	 
	string s ="";
    
	helper(input,0,strlen(input),s);
    
	int i=0;
	for(; i< s.size();i++)
	   input[i] = s[i];

	input[i] = '\0'; 
  
}


