#include <iostream>
using namespace std;
#include "Node.cpp"

Node* take_input_better() {
	cout << "Enter Data (-1 terminates): " << endl;
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

void print_recursive(Node *head){
	if(head == NULL){
		return ;
	}else {
		cout << head -> data << endl;;
	}
	print_recursive(head->next);
}

int length(Node *head){
	Node *temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}

void print_ith(Node *head, int i){
	int len = length(head);
	if(len < i){
		cout << "Out of Index" << endl;
		return ;
	}
	int pos = 1;
	Node *temp  = head;
	while(pos != i){
		temp = temp -> next;
		pos++;
	}

	cout << temp->data << endl;
	return ;
}

void insert_at_i(Node **head, int data, int i){
	Node *temp = *head;
	Node *newNode = new Node(data);
	int pos = i-1;
	Node *prev = NULL;
	if(pos == 0){
		newNode -> next = *head;
		*head = newNode;
		return ;
	}
	while(pos--){
		prev = temp;
		temp = temp -> next;
	}
	newNode->next = prev->next;
	prev->next = newNode;
}

void delete_at_i(Node **head, int i){
	Node *temp = *head;
	Node *prev = NULL;
	int pos = i-1;
	if(pos == 0){
		*head = temp -> next;
		delete temp;
		return;
	}
	while(pos--){
		prev = temp;
		temp = temp -> next;
	}
	prev -> next = temp -> next;
	delete temp;
}

void mid_point(Node* head){
	Node* first = head;
	Node* second = head;
	Node* prev = NULL;
	int flag = 0;
	while(second -> next != NULL){
		prev = first;
		first = first -> next;
		second = second -> next;
		if(second -> next == NULL){
			flag = 1;
			break;
		}
		second = second -> next;
	}
	(flag)?(cout << prev->data << " " << first -> data << endl):(cout << first -> data << endl);
}

Node* reverse_ll(Node* head){
	Node* prev = NULL;
	Node* current = head;
	Node* next = NULL;
	while(current != NULL){
		next = current->next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

Node* reverse_recursive(Node* current, Node* prev = NULL, Node* next = NULL){
	if(current == NULL){
		return prev;
	}
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	return reverse_recursive(current, prev, next);
}

Node* basic_merge(Node* head, Node* head2){
	Node* merged = NULL;
	Node* ll1 = head;
	Node* ll2 = head2;
	Node* first = NULL;
	while(ll1 != NULL && ll2 != NULL){
		if(ll1 -> data < ll2 -> data){
			if(merged == NULL){
				merged = new Node(ll1 -> data);
				first = merged;
			}else{
				merged -> next = new Node(ll1->data);
				merged = merged -> next;
			}
			ll1 = ll1 -> next;
		}else{
			if(merged == NULL){
				merged = new Node(ll2 -> data);
				first = merged;
			}else{
				merged -> next = new Node(ll2->data);
				merged = merged -> next;
			}
			ll2 = ll2 -> next;
		}
	}

	if(ll1 != NULL){
		while(ll1 != NULL){
			merged->next = new Node(ll1 -> data);
			merged = merged -> next;
			ll1 = ll1 ->next;
		}
	}
	if(ll2 != NULL){
		while(ll2 != NULL){
			merged->next = new Node(ll2 -> data);
			merged = merged -> next;
			ll2 = ll2 ->next;
		}
	}
	return first;
}

int main() {

	int i;
	Node *head = take_input_better();
	print(head);

	// Node* head2 = take_input_better();
	// print(head2);

	// Node* merged = merge_ll(head, head2);
	// print(merged);

	// // Reversing a LL
	// head = reverse_ll(head);
	// print(head);
	// // Reversing a LL Recursively
	// head = reverse_recursive(head);
	// print(head);


	// cout << "Enter Index: ";
	// cin >> i;

	// //print ith node
	// print_ith(head, i);

	// int data, pos, del_pos;
	// cout << "Enter the Element: " << endl;
	// cin >> data;
	// cout << "Enter the Position: " << endl;
	// cin >> pos;

	// // Insert data at i-th node
	// insert_at_i(&head, data, pos);
	// print(head);

	// cout << "Delete element at pos? ";
	// cin >> del_pos;
	// cout << "Deleting" << endl;

	// // Delete i-th Node
	// delete_at_i(&head, del_pos);
	// print(head);

	// cout << "Length of the linked list is: " << length(head) << endl;

	// // Finding mid-point of the Linked List 
	// mid_point(head);
	

	// // Static Allocation
	// Node n1(1);
	// Node *head = &n1;

	// Node n2(2);

	// Node n3(3);
	// Node n4(4);
	// Node n5(5);

	// n1.next = &n2;
	// n2.next = &n3;
	// n3.next = &n4;
	// n4.next = &n5;

	// print(head);

	// print(head);
	
	
	// // Dynamic allocation
	// Node *n3 = new Node(10);
	// Node *head = n3;
	
	// Node *n4 = new Node(20);
	// n3 -> next = n4;

}

