/*

Print Level Wise

Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn

where, N is data of any node present in the generic tree. x1, x2, x3, ...., 
xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.

Input format :
The first line of input contains data of the nodes of the tree in level 
order form. The order is: data for root node, number of children to 
root node, data of each of child nodes and so on and so forth for 
each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the elements of the tree in level wise order, as described in the task.
Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:

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

// USING RECURSION


void printLevelWise(TreeNode<int>* root) {
   
   if(root == NULL)
    return;

    cout << root -> data <<":";

    for(int i=0;i < root -> children.size();i++)
    {
        cout << root -> children[i] -> data ;

        if(i < root -> children.size() -1)
        {
            cout <<",";
        }
    } 
   cout << endl;
    for(int i=0;i < root -> children.size();i++)
    {
        printLevelWise(root -> children[i]);
    }
}


// USING QUEUE
#include<bits/stdc++.h>
using namespace std;


void printLevelWise(TreeNode<int>* root) {
      
    if(root == NULL)
      return ;
    
    // Making a queue and pushing root TreeNode      
    queue < TreeNode <int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        // Getting the parent TreeNode each time and printing it,removing from queue
        TreeNode <int> * first = pendingNodes.front();
        pendingNodes.pop();
             
        cout << first -> data <<":";
        
        // Printing all the children and pushing all the children(which 
        //can be parent for other TreeNode)  
        for(int i=0;i< first -> children.size();i++)
        {
            cout << first -> children[i] -> data ;
            if(i != first-> children.size() -1)
            {
                cout <<",";
            }
            pendingNodes.push(first -> children[i]);
        }
        // after each level giving new line
        cout << endl;
    }  

}