/*

Level order traversal

For a given a Binary Tree of type integer, print it in a level order fashion 
where each level will be printed on a new line. Elements on every level 
will be printed in a linear fashion and a single space will separate them.

Input Format:
The first and the only line of input will contain the node data, all 
separated by a single space. Since -1 is used as an indication whether 
the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The given input tree will be printed in a level order fashion where each 
level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space 
will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 

Sample Output 1:
10 
20 30 
40 50 60 

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 

*/

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void printLevelWise(BinaryTreeNode<int> *root) {
    
	queue <BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	cout << root -> data << endl;

	while(pendingNodes.size() != 0)
	{
	    int n = pendingNodes.size(); 
	
		while(n != 0)
		{
            BinaryTreeNode<int> *first =pendingNodes.front();
			pendingNodes.pop();

            if (first->left != NULL) 
			{
				cout << first -> left -> data <<" ";
                pendingNodes.push(first->left);
			} 

			if(first -> right != NULL)
			{
				cout << first -> right -> data <<" ";
				pendingNodes.push(first -> right);
			}
			n--;
		}
		cout << endl;
	}
}