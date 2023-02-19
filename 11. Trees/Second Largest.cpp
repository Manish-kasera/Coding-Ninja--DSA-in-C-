/*

Second Largest Element In Tree

Given a generic tree, find and return the node with second largest 
value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in 
level order form. The order is: data for root node, number of children to 
root node, data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
int nodeCount(TreeNode <int> *root)
{
    int ans = 1;

    for(int i=0;i < root -> children.size();i++)
    {
        ans += nodeCount(root -> children[i]);
    }

    return ans;
}

int largest(TreeNode<int> *root) {
  int maxi = INT_MIN;

  for (int i = 0; i < root->children.size(); i++) {
    int ch = largest(root->children[i]);
    maxi = max(ch, maxi);
  }

  maxi = max(maxi, root->data);
  return maxi;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root) {

    if(root == NULL)
      return  NULL;

    int count = nodeCount(root);

    if(count <= 1)
      return NULL;  

    int maxi = largest(root);
    int s_maxi = INT_MIN;
    TreeNode<int> * ansNode = NULL;
    int c = 0;

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *first = pendingNodes.front();
        pendingNodes.pop();

        if(first-> data < maxi && first-> data > s_maxi)
        {
            s_maxi = first -> data;
           ansNode = first;
           c++;
        }

        for(int i=0;i < first -> children.size();i++)
          pendingNodes.push(first-> children[i]);
    }
  
   if(c >= 1)
     return ansNode;
   else
     return NULL;
}