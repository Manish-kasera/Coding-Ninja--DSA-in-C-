/*

Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given 
a numeric string S. Write a program to return the list of all possible 
codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include<bits/stdc++.h>
using namespace std;

void helper(string input,string ans,vector <string> &v)
{
    if(input.empty())
    {
        v.push_back(ans);
        return;
    }

    char c1 = input[0] - '0' + 'a'-1;

    // first  two digit
    int b = stoi(input.substr(0, 2));

    // first two digits into char
    char c2 = b - 1 + 'a';

    // taking 1 dig and moving forward
     helper(input.substr(1),ans + c1,v);

    if (b >= 10 && b <= 26) {
      // taking 2 dig and moving forward
        helper(input.substr(2),ans + c2,v);
    }
}

int getCodes(string input, string output[10000]) {
  
  vector <string> v;
  helper(input,"",v);

  for(int i=0; i < v.size();i++)
    output[i] = v[i];

   return v.size(); 
  
}

