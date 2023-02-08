/*

Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :

Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 

Sample Input 1 :
xaxb
Sample Output 1:
ab

Sample Input 2 :
abc
Sample Output 2:
abc

*/



// Change in the given string itself. So no need to return or print anything

// Best Solution
#include<bits/stdc++.h>
using namespace std;
void removeX(char input[]) {
   
   if(input[0] == '\0')
       return;

   if(input[0] == 'x')
   {
       int n = strlen(input);
       int i=0;
       for(; i< n-1;i++)
       {
           input[i] = input[i+1];
       }

       input[i] ='\0';
       removeX(input);
  
   }   
   else
   {
       removeX(input+1);
   } 
}



// Using helper and creating O(n) space
#include<bits/stdc++.h>
using namespace std;

void helper(char input[],int i,int n,string &s)
{
  if(i == n)
    return;

   if(input[i] != 'x')
     s += input[i];

   helper(input,i+1,n,s) ;  
}



void removeX(char input[]) {
   
   string s="";

   helper(input,0,strlen(input),s);
   
   int i=0;
   for(; i< s.size();i++)
     input[i] = s[i];

   input[i] = '\0';  
}
