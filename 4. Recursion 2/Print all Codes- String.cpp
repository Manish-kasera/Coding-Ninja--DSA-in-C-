/*

Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from 
the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S
Output Format :
All possible codes in different lines

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

void helper(string input,string output)
{
    if(input.empty())
    {
        cout << output << endl;
        return;
    }
    
    // first digit into char
    char c1 = input[0] - '0' + 'a' - 1;
    
    // first  two digit 
    int b = stoi(input.substr(0,2));
    
    // first two digits into char
    char c2 = b -1 +'a';
    
    // taking 1 dig and moving forward
    helper(input.substr(1),output+ c1);

    if(b >= 10 && b <= 26)
    {
      // taking 2 dig and moving forward
      helper(input.substr(2), output + c2);
    }
}

void printAllPossibleCodes(string input) {
    
    helper(input,"");
}

