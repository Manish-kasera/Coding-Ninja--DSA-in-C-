/*

Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a 
function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test 
cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the 
elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end 
of the singly linked list and hence, would never be a list element.

Output format :
For each test case, the only line of output that print 'true' if 
the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1

Sample Output 2 :
false
true

Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.

*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/
Node *mid(Node *head) {
  Node *first = head;
  Node *second = head;

  while (second != NULL && second->next != NULL) {
    first = first->next;
    second = second->next->next;
  }
  return first;
}

Node *reverse(Node *head) {
  Node *prev = NULL;
  Node *next = NULL;
  Node *curr = head;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

bool isPalindrome(Node *head) {
  
  Node *first = head;
  Node *second = mid(head);

  second = reverse(second);

  Node *i = first;
  Node *j = second;

  while (j) {
    // cout << i->val << endl;
    if (i->data != j->data) {
      return false;
    }
    i = i->next;
    j = j->next;
  }

  return true;
}