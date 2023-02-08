/*

String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, you need 
to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 < |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231
Sample Output 1 :
1231

Sample Input 2 :
12567
Sample Output 2 :
12567

*/

// Using helper Function
#include<bits/stdc++.h>
using namespace std;

void helper(int n,char input[],int &num)
{
    if(n < 0)
      return;
    
    int x = input[n] - 48;
    num = num * 10 + x;

    helper(n-1,input,num);    

}

void reverse(int &num)
{
    int rev = 0;
    while(num != 0)
    {
        int temp = num % 10;
        rev = rev * 10 + temp;
        num /= 10;
    }
   num = rev;
}

int stringToNumber(char input[]) {
   int num = 0;

   helper(strlen(input)-1,input,num);

   reverse(num);

   return num;

}


// 2nd Solution

#include<bits/stdc++.h>
using namespace std;

int helper(int i,int n,int num,int temp,char input[])
{
    if(i == n)
        return num;
    
    int rem = int(input[i]) - 48;
    
    return helper(i+1,n,num + (rem * pow(10,temp)),temp-1,input);
}

int stringToNumber(char input[]) {
  
    int num = 0;
    int n = strlen(input);
    int temp = n-1;
    
    return helper(0,n,num,temp,input);

}


