#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

void insert(Node **head, int data) {
	Node *temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(*head == NULL) {
		cout<<*head<<"\n";
		*head = temp1;
		cout<<*head<<"\n";
		return;
	}
	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = temp1;
}

void insert(Node **head, int data, int pos) {
	Node *temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;

	if(pos == 0) {
		temp1->next = *head;
		*head = temp1;
	}
	else {
		int index = 0;
		Node *temp = *head;
		while(temp->next != NULL && index < pos-1) {
			temp = temp->next;
			index++;
		}
		if(index == pos-1) {
			temp1->next = temp->next;
			temp->next = temp1;
		}
		else {
			cout<<"Invalid position!\n";
		}
	}
}

void deleteNode(Node **head, int pos) {
	Node *temp = *head;
	if(pos == 0) {
		*head = temp->next;
		delete temp;
	}
	else {
		int index = 0;
		while(temp->next != NULL && index < pos-1) {
			temp = temp->next;
			index++;
		}

		if(index == pos - 1) {
			Node *temp1 = temp->next;
			temp->next = temp1->next;
			delete temp1;
		}
		else {
			cout<<"Invalid position!\n";
		}
	}
}

Node* reverse(Node *head) {
	Node *altHead = NULL;
	Node *temp = head, *prev = NULL, *next;
	while(temp != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	altHead = prev;
	return altHead;
}

Node *altHead1 = NULL;
void reverseRecursion(Node *prev, Node *cur) {
	if(cur != NULL) {
		reverseRecursion(cur, cur->next);
		cur->next = prev;
	}
	else {
		altHead1 = prev;
	}
}

void print(Node *head) {
	Node *temp = head;
	cout<<"List: ";
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void printForwardRecursion(Node *node) {
	if(node != NULL) {
		cout<<node->data<<" ";
		printForwardRecursion(node->next);
	}
}

void printReverseRecursion(Node *node) {
	if(node != NULL) {
		printReverseRecursion(node->next);
		cout<<node->data<<" ";
	}
}

int main(){
	Node *head = NULL;
	insert(&head, 6, 0);
	print(head);
	insert(&head, 76, 0);
	print(head);
	insert(&head, 3, 2);
	print(head);
	insert(&head, 4, 1);
	print(head);
	deleteNode(&head, 1);
	cout<<"FwdRecur List: ";
	insert(&head, 9, 1);
	printForwardRecursion(head);
	cout<<"\n";
	cout<<"RevRecur List: ";
	printReverseRecursion(head);
	cout<<"\n";

	Node *altHead = reverse(head);
	cout<<"Inplace Rev ";
	print(altHead);
	reverseRecursion(NULL, altHead);
	cout<<"Inplace RevRecur ";print(altHead1);
	return 0;
}
