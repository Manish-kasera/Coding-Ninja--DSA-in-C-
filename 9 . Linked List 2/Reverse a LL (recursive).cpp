/*

Code : Reverse LL (Recursive)
Send Feedback
Given a singly linked list of integers, reverse it using recursion and return 
the head to the modified list. You have to do this in O(N) time complexity 
where N is the size of the linked list.
 Note :
No need to print the list, it has already been taken care. Only return 
the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test 
cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the 
elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end 
of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1

Sample Output 1 :
8 7 6 5 4 3 2 1

Sample Input 2 :
2
10 -1
10 20 30 40 50 -1

Sample Output 2 :
10 
50 40 30 20 10 

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

// SOLUTION 1 O(N^2)
Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL || head -> next == NULL)
	  return head;

	Node *smallAns = reverseLinkedListRec(head -> next);

	Node *temp = smallAns;
   
    // last node
	while(temp-> next != NULL)
	{
       temp = temp -> next;
	}  
	
	temp -> next = head;
	head -> next = NULL;

	return smallAns;
}

// BEST SOLUTION O(N) (Just little change from above solution)
Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL || head -> next == NULL)
	  return head;
     
	// suppose it reverse the remaining node 
	Node *smallAns = reverseLinkedListRec(head -> next);
    
	// tail node is just after the head node
	Node *tail = head -> next;
	
	// tail node ka next connect kro head ko 
	tail -> next = head;

	// head ka next equal to NULL
	head -> next = NULL;
    
	// return smallAns
	return smallAns;
}

// SOLUTION 2  O(N) -> but little jhol jhal

class Pair{
	public :
	Node *head ;
	Node *tail;
};

Pair reverse(Node *head)
{
	if(head == NULL || head -> next == NULL)
	{
		Pair ans;
		ans.head = head;
		ans.tail = head;
		
		return ans;
	}

	Pair smallAns = reverse(head -> next);

	smallAns.tail -> next = head;
	head -> next = NULL;

	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;


	return ans;
  
}

Node *reverseLinkedListRec(Node *head)
{
    return reverse(head).head;
}