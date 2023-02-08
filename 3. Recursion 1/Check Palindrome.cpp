/*

Check Palindrome (recursive)
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false


*/

// Using helper function
#include<bits/stdc++.h>

bool helper(int i,int n,char input[])
{
    if(i > n)
      return true;
    return input[i] == input[n] && helper(i+1,n-1,input);
}

bool checkPalindrome(char input[]) {
  
  return helper(0,strlen(input)-1,input);
}

