#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter number of children of " << front -> data << endl;
		int numChild;
		cin >> numChild;
		for(int i=0; i < numChild; i++){
			int childData;
			cout << "Enter " << i <<"th-child of" << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput(){
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter number of children of " << rootData << endl;
	cin >> n;

	for(int i=0; i < n; i++){
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}

	return root;
}

void printTree(TreeNode<int>* root) {

	//EDGE Case not Base Case

	if(root == NULL){
		return;
	}

	cout << root -> data << ":";
	for (int i = 0; i < root->children.size(); i++){
		cout << root->children[i]->data<<",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++){
		printTree(root->children[i]);
	}
}

void printTreeLevelWise(TreeNode<int>* root){
	cout << "Level Order Traversal: " << endl;
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << " ";
		for(int i = 0; i < front->children.size(); i++){
			pendingNodes.push(front->children[i]);
		} 
	}

	cout << endl;
}

int countNodes(TreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	int result = 1;
	for(int i = 0; i < root->children.size(); i++){
		result += countNodes(root->children[i]);
	}
	return result;
}

int height(TreeNode<int>* root) {
	if(root == NULL){
		return 0;
	}

	int maxDepth = 0;
	for(int i = 0; i < root->children.size(); i++){
		maxDepth = max(maxDepth, height(root->children[i]));
	}

	return 1 + maxDepth;
}

void printKlevelNodes(TreeNode<int>* root, int k){
	if(root == NULL){
		return;
	}

	if(k == 0){
		cout << root->data << endl;;
	}

	for(int i = 0; i < root->children.size(); i++) {
		printKlevelNodes(root->children[i], k-1);
	}
}

void printLeafNodes(TreeNode<int>* root) {
	if(root == NULL){
		return;
	}

	if(root->children.size() == 0){
		cout << root->data << " ";
	}

	for(int i = 0; i < root->children.size(); i++) {
		printLeafNodes(root->children[i]);
	}

}

int main() {
	TreeNode<int>* root = takeInputLevelWise();

	printLeafNodes(root);

	// printTreeLevelWise(root);

	// printKlevelNodes(root, 3s);

	// cout << "Number of Nodes: " << countNodes(root);

	// cout << "Height of Tree: " << height(root) << endl;

	// TreeNode<int>* root = new TreeNode<int>(1);
	// TreeNode<int>* node1 = new TreeNode<int>(2);
	// TreeNode<int>* node2 = new TreeNode<int>(3);
	// root->children.push_back(node1);
	// root->children.push_back(node2);
	
	// TODO delete tree
}
