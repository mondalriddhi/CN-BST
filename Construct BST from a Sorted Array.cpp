/*  Given a sorted integer array A of size n, which contains all unique elements. 
You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. 
The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.


Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 
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

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int pos(int *input, int start, int end) {
  	if(start>end) {
		  return -1;
	  }
	int mid=(start+end)/2;
	return mid;
}

BinaryTreeNode<int>* createBST(int *input, int start, int end) {
	
	int mid=pos(input,start,end);
	if(mid==-1) {
		return NULL;
	}
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(input[mid]);
	BinaryTreeNode<int>* leftn=createBST(input,start,mid-1);
	BinaryTreeNode<int>* rightn=createBST(input,mid+1,end);
	root->left=leftn;
	root->right=rightn;
	return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
	if(n==0) {
		return NULL;
	}
	int start=0;
	int end=n-1;
    BinaryTreeNode<int> * root=createBST(input, start, end);
    return root;
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}
