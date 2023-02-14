/*

Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all 
characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.

E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters 
of t=”coding” in the same order. So function will return true.

Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
true or false

Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding

Sample Output 1 :
true

Sample Input 2 :
abcde
aeb

Sample Output 2 :
false

*/

#include <bits/stdc++.h>
bool helper(char large[],int l,char *small,int s)
{

    if(s == 0 )
     return true;

    if(l == 0 && s != 0)
      return false; 


    if(large[0] == small[0])
    {
        return helper(large+1,l-1,small+1,s-1);
    }
    else
    {
        return helper(large+1,l-1,small,s);
    }
}

bool checksequenece(char large[] , char*small) {
   
   int l = strlen(large);
   int s = strlen(small);

   return helper(large,l,small,s);
}
