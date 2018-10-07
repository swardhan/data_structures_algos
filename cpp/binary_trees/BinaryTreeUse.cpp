#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter Data: " ;
	cin >> rootData;

	if(rootData == -1){
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	root->left = leftChild;
	root->right = rightChild;
	return root;
}

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter Data: " ;
	cin >> rootData;

	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter Left Child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}

		cout << "Enter Right Child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}

	return root;
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout << root->data << ":";

	if (root->left != NULL){
		cout<<"L"<<root->left->data << " ";
	}

	if (root->right != NULL){
		cout<<"R"<<root->right->data << " ";
	}

	cout << endl;

	printTree(root->left);
	printTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ": " << endl;	
		if(front->left != NULL){
			pendingNodes.push(front->left);
		}
		if(front->right != NULL){
			pendingNodes.push(front->right);
		}
	}
}

int countNodes(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}

	return 1 + countNodes(root->right) + countNodes(root->left);
}

void preOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

//Sample Tree: 1 2 3 4 5 6 7 -1 -1 -1 -1  8 9 -1 -1 -1 -1 -1 -1

int main(){
	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

	// root->right = node1;
	// root->left = node2;
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	// cout << "inOrder: " << inOrder(root) << endl;
	// cout << "preOrder: " << preOrder(root) << endl;
	// cout << "postOrder: " << postOrder(root) << endl;	
	// cout << "Number of Nodes: " << countNodes(root) << endl;

	delete root;
}
