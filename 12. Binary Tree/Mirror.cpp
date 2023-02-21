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
// USING RECURSION

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
     
	if(root == NULL)
	  return;

	mirrorBinaryTree(root -> left);
	mirrorBinaryTree(root -> right);

	BinaryTreeNode<int>* tempNode = root -> left;
	root -> left = root -> right;
	root -> right = tempNode; 
}


// USING QUEUE
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
     
	queue <BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0)
	{
		BinaryTreeNode <int> *first = pendingNodes.front();
		pendingNodes.pop();
        
		// if both left and right node are not null then swap
		if(first -> left != NULL && first -> right != NULL)
		{
			pendingNodes.push(first -> left);
			pendingNodes.push(first -> right);

			BinaryTreeNode<int> *tempNode = first -> left;
			first -> left = first -> right;
			first -> right = tempNode;
		}
		// if left is not null but right is null then swap
		else if(first -> left != NULL)
		{
			first -> right = first -> left;
			first -> left = NULL;
		}

		// if right is not null but left is null then swap
		else if(first -> right != NULL)
		{
			first -> left = first -> right;
			first -> right = NULL;
		}
	} 
}