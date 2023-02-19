/*  Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. 
If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST.
 If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. 
x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.

Sample Input 1:
8
1 4
1 4
1 4
1 4
4
3 4
2 4
4
Sample Output:
4:L:4,
4:L:4,
4:L:4,
4:
true
4:L:4,
4:L:4,
4:

*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
   public:

    BST() { 
        // Implement the Constructor
        root=NULL;
    }
    ~BST() {
        delete root;
    }
//*********************FOR REMOVING********************************
    private:

    BinaryTreeNode<int>* removeNode(BinaryTreeNode<int>* root, int key) {
        if(root==NULL) {
            return NULL;
        }
        if(root->data<key) {
            root->right=removeNode(root->right, key);
            return root;
        }
        else if(key<root->data) {
            root->left=removeNode(root->left, key);
            return root;
        }
        else{
            if(root->left==NULL&&root->right==NULL) {
                delete root;
                return NULL;
            }
            else if(root->left==NULL) {
                BinaryTreeNode<int>* temp=root->right;
                root->right=NULL;
                //delete root;
                root=root->right;
                return temp;
            }
            else if(root->right==NULL) {
                BinaryTreeNode<int>* temp=root->left;
                root->left=NULL;
                //delete root;
                root = root->left;
                return temp;
            }
            else {
                BinaryTreeNode<int>* rightMin=root->right;
                while(rightMin->left!=NULL) {
                    rightMin=rightMin->left;
                }
                root->data=rightMin->data;
                root->right=removeNode(root->right, rightMin->data);
                return root;
            }
        }
    }
	
    public:
    void remove(int data) { 
        // Implement the remove() function
        root=removeNode(root, data); 
    }
//*************************************************************************

//************************FOR PRINTING**********************************
    private:
    void printTree(BinaryTreeNode<int>* root) {
        if(root==NULL) {
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL) {
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL) {
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);

    }

    public:
    void print() { 
        // Implement the print() function
        printTree(root);
    }
//***************************************************************************

//*****************************FOR INSERTING******************************
    private:
    BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>* root, int key) {
        if(root==NULL) {
            BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(key);
            return newNode;
        }
        if(root->data<key) {
            root->right=insertNode(root->right, key);
            return root;
        }
        else if(key<=root->data) {
            root->left=insertNode(root->left, key);
            return root;
        }
    }
    public:
    void insert(int data) { 
        // Implement the insert() function 
        root=insertNode(root, data);
    }
//****************************************************************************

//**************************FOR SEARCHING*********************************
    private:
    bool searchNode(BinaryTreeNode<int>* root, int key) {
        if(root==NULL) {
            return false;
        }
        if(root->data==key) {
            return true;
        }
        if(root->data<key) {
            return searchNode(root->right, key);
        }
        else if(key<root->data) {
            return searchNode(root->left, key);
        }
    }
    public:
    bool search(int data) {
		// Implement the search() function 
        return searchNode(root, data);
    }
    //**************************************************************************
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
