/*

Check AB
Send Feedback
Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated 
using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.

Input format :
String S
Output format :
'true' or 'false'

Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb
Sample Output 1 :
true

Sample Input 2 :
abababa
Sample Output 2 :
false

Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.

*/


// Using Helper Function
#include<bits/stdc++.h>
using namespace std;

bool helper(char input[],int start,int end)
{
    if(start == end)
        return true;
    
    
    if(input[0] == 'a' && start==0)
          helper(input,start+1,end);
    else if(input[start] == 'a' && (input[start -1] == 'a' || input[start-1] == 'b' && input[start-2] == 'b'))
          helper(input,start+1,end);
    else if(input[start] == 'b' && input[start+1] == 'b' && input[start-1] == 'a')
          helper(input,start+2,end);
     else
        return false;
   
}
bool checkAB(char input[]) {
    int start=0,end = strlen(input);
    
    return helper(input,start,end);
}





// Not working for all Case eg abbaabb
bool checkAB(char input[]) {
	
	if(input[0] == '\0')
	  return true;
    
	if(input[0] == 'a')
	   return checkAB(input+1);   
    else if (input[0] == 'a' && input[1] == 'a')
	     return checkAB(input+2);

    else if (input[0] == 'b' && input[1] == 'b' && input[2] == 'a')
	  return checkAB(input+3);
	
	else if(input[0] = 'a'  && input[1] == 'b' && input[2] == 'b')
	   return checkAB(input+3);
	
	else if(input[0] == 'b' && input[1] == 'b')
	  return checkAB(input+2);   
	
	else 
	 return false;  
}

