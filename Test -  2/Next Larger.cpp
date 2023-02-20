/*

Next Number

Given a large number represented in the form of a linked list. Write code to 
increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements 
and return the head of updated LL.

Input Constraints:
1 <= Length of Linked List <=10^6.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)

Output Format :
Line 1: Updated linked list elements 

Sample Input 1 :
3 9 2 5 -1

Sample Output 1 :
3 9 2 6

Sample Input 2 :
9 9 9 -1

Sample Output 1 :
1 0 0 0 

*/
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* reverse(Node* head)
{
  Node *next = NULL;
  Node *prev = NULL;
  Node *curr = head;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

Node *addOne(Node *head)
{
  // res is head node of the resultant list 
  Node *res = head;
  Node *temp, *prev = NULL;

  int carry = 1, sum;

  while (head != NULL) // while both lists exist
  {
    // Calculate value of next digit in resultant list.
    // The next digit is sum of following things
    // (i) Carry
    // (ii) Next digit of head list (if there is a next digit)
    sum = carry + head->data;

    // update carry for next calculation
    carry = (sum >= 10) ? 1 : 0;

    // update sum if it is greater than 10
    sum = sum % 10;

    // Create a new node with sum as data
    head->data = sum;

    // Move head and second pointers to next nodes
    temp = head;
    head = head->next;
  }

  // if some carry is still there, add a new node to result list.
  if (carry > 0)
    temp->next = new Node(carry);

  // return head of the resultant list
  return res;
}

Node* NextLargeNumber(Node *head) {
    
  head = reverse(head);

  head = addOne(head);

  head = reverse(head);

  return head;

}


