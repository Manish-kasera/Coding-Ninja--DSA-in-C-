/*

ZigZag tree

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed 
from left to right, level 2 from right to left and so on. This means odd levels 
should get printed from left to right and even level right to left.

Input format:
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have 
a left or right child, take -1 in its place. Since -1 is used as an indication 
whether the left or right nodes exist, therefore, it will not be a part of the 
data of any node.

Output Format:
The binary tree is printed level wise, as described in the task. Each level is
printed in new line.

Constraints
Time Limit: 1 second

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9

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
#include<bits/stdc++.h>
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
 
  if(root == NULL)
    return;

  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  
  int level = 1;

  while (!q.empty()) 
  {

    int n = q.size();
    vector<int> v;

    while(n != 0)
    {
      BinaryTreeNode<int> *frontNode = q.front();
      q.pop();

      v.push_back(frontNode->data);

      if (frontNode->left)
        q.push(frontNode->left);

      if (frontNode->right)
        q.push(frontNode->right);

     n--;  
    }
  
    if(level % 2 == 0)
    reverse(v.begin(),v.end());

    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
    // incresing level
    level++;
  }
  
}