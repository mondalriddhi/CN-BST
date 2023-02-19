/*  Given a Binary tree, find the largest BST subtree. 
That is, you need to find the BST with maximum height in the given binary tree. 
You have to return the height of largest BST.
Note :
The binary tree will be consisting of only unique elements.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space.
 If any node does not have left or right child, take -1 in its place.
  Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

#include<climits>

class info {
	public:
	int size;
	int mini;
	int maxi;
	int ans;
	bool isBST;
};

info largestBSTinBT(BinaryTreeNode<int>* root) {
	if(root==NULL) {
		return {0, INT_MAX, INT_MIN, 0, true};
	}
	if(root->left==NULL&&root->right==NULL) {
		return {1, root->data, root->data, 1, true};
	}

	info fromleft=largestBSTinBT(root->left);
	info fromright=largestBSTinBT(root->right);

	info curr;
	curr.size=1+max(fromleft.size, fromright.size);
	
	if(fromleft.isBST&&fromright.isBST&&fromleft.maxi<root->data&&fromright.mini>root->data) {
		curr.mini = min(fromleft.mini, min(fromright.mini, root->data));
		curr.maxi = max(fromleft.maxi, max(fromright.maxi, root->data));

		curr.ans=curr.size;
		curr.isBST=true;

		return curr;
	}

	curr.ans=max(fromleft.ans, fromright.ans);

	curr.isBST=false;
	return curr;

}


int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	info getans=largestBSTinBT(root);
	int h=getans.ans;
	return h;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
