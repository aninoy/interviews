#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

//Function to find some data in the tree
Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
struct Node* FindMin(struct Node* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

//Function to find Inorder Successor in a BST
struct Node* Getsuccessor(struct Node* root,int data) {
	// Search the Node - O(h)
	struct Node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}

Node* successor(Node *node, int data) {
	Node *sNode = NULL;

	if(node == NULL) {
		return node;
	}

	if(data < node->data) {
		sNode = successor(node->left, data);
		if(sNode != NULL && sNode->data == data) {
			sNode = node;
		}
	}
	else if(data > node->data) {
		sNode = successor(node->right, data);
	}
	else {
		sNode = FindMin(node->right);
		if(sNode == NULL) {
			sNode = node;
		}
	}
	return sNode;
}
int main() {
	Node* root = NULL;
	root = Insert(root,15); root = Insert(root,10);
	root = Insert(root,8); root = Insert(root,6);
	root = Insert(root,12); root = Insert(root,11);
	root = Insert(root,20); root = Insert(root,17);
	root = Insert(root,16); root = Insert(root,25);
	root = Insert(root,27);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node.
	// struct Node* successorNode = Getsuccessor(root,10);
	struct Node* successorNode = successor(root, 5);
	if(successorNode == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successorNode->data<<"\n";
}
