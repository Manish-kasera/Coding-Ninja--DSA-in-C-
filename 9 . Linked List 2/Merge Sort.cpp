/*

Code: Merge Sort
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return 
the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of 
test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the 
elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end
of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 */
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
  // New Head which contain new merge sorted LL
  Node *newHead = NULL;

  // Base Case
  if (head1 == NULL)
    return head2;

  // Base Case
  if (head2 == NULL)
    return head1;

  // Finding our new Head and after getting just shift that previous head
  if (head1->data < head2->data) {
    newHead = head1;
    head1 = head1->next;
  } else {
    newHead = head2;
    head2 = head2->next;
  }

  // using for traversing Both LL
  Node *temp = newHead;

  while (head1 != NULL && head2 != NULL) {
    // if head1 data is less then connect this node with temp,then shift
    // temp,shift head1 also
    if (head1->data < head2->data) {
      temp->next = head1;
      temp = head1;
      head1 = head1->next;
    }
    // else head3 data is less then connect this node with temp,then shift
    // temp,shift head2 also
    else {
      temp->next = head2;
      temp = head2;
      head2 = head2->next;
    }
  }

  // while head1 is not NULL connect with temp,shift temp,shift head1
  while (head1 != NULL) {
    temp->next = head1;
    temp = head1;
    head1 = head1->next;
  }

  // while head2 is not NULL connect with temp,shift temp,shift head2
  while (head2 != NULL) {
    temp->next = head2;
    temp = head2;
    head2 = head2->next;
  }

  return newHead;
}

Node* middle(Node *head)
{
  Node *fast = head->next;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
Node *mergeSort(Node *head)
{

  if (head == NULL || head->next == NULL)
    return head;

  Node *mid = middle(head);
 
  Node *first = head;
  Node *second = mid->next;

  mid->next = NULL;

  first = mergeSort(first);
  second = mergeSort(second);

  head = mergeTwoSortedLinkedLists(first, second);

  return head;
}