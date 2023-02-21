/***********************************************************
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

// For more details watch Code helper by Love Babber


// Inorder (left,root,right)
// PreOrde (root,left,right)

int findPosition(int val,int *inorder,int n)
{
	for(int i=0;i < n;i++)
	{
		if(val == inorder[i])
		  return i;
	}
	return -1;
}

BinaryTreeNode<int>* helper(int *preorder,int* inorder,int &index,int inStart,int inEnd,int n)
{
	// if index > n or inOrderStart > inOrderEnd
	if(index >= n || inStart > inEnd)
	{
		return NULL;
	}
    
	// Getting the root  value which found in preOrder and make a root Node 
	int val = preorder[index++];
    
	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(val);
  
   // getting the postion in inOrder so we can seperate them in left(till position -1)
   // and right(starts from position+1)
	int position = findPosition(val,inorder,n);

	// recursive call
	// inorder left part from inStart to position -1
	root -> left = helper(preorder,inorder,index,inStart,position-1,n);

    // inorder right part from position + 1 to inOrderEnd
    root -> right = helper(preorder,inorder,index,position+1,inEnd,n);

	return root;

} 

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
	int preOrderIndex = 0;
	int inStart = 0;
	int inEnd = inLength;
	int n = inLength;

    return helper(preorder,inorder,preOrderIndex,inStart,inEnd,n);
}