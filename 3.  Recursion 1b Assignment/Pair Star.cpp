/*

Pair Star
Send Feedback
Given a string S, compute recursively a new string where identical chars 
that are adjacent in the original string are separated from each other by a "*".

Input format :
String S
Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo

Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/


// Change in the given string itself. So no need to return or print the changed string.

#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    
    if(input[0] =='\0')
        return ;

    if(input[0] == input[1])
    {
       int n = strlen(input);
       int i= n-1;

       for(; i>= 1;i--)
       {
           input[i+1] = input[i];
       }

       input[1] ='*';
       input[n+1] ='\0';
       pairStar(input+1);
    }   
    else
    {
        pairStar(input + 1);
    } 

}


// Another Solution

#include <bits/stdc++.h>
using namespace std;

string helper(int i,int n,string s,char input[])
{
  if(i== n)
    return s;

  if(input[i] == input[i+1])
  {
    s += input[i];
    s += '*';
  }else{
    s += input[i];
  }

  return helper(i+1,n,s,input);
}


void pairStar(char input[]) {
   
    string s="";
    int n = strlen(input);
    s = helper(0,n,s,input);
    
    int i=0;
    for(i;i <s.size();i++)
    {
      input[i] = s[i];    
    }
    input[i] = '\0';
}
