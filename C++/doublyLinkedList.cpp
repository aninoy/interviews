#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
};
Node *head = NULL;

void print() {
	Node *temp = head;
	cout<<"List: ";
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void printReverse() {
	Node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	cout<<"Reversed List: ";
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
}

void insertHead(int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = head;
	if(head != NULL) {
		head->prev = temp;
	}
	temp->prev = NULL;
	head = temp;
}

void insertTail(int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node *temp1 = head;
	while(temp1->next != NULL) {
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
}

void deleteNode(int pos) {
	Node *temp = head;
	if(pos == 0) {
		if(temp != NULL) {
			head = temp->next;
			head->prev = NULL;
			delete temp;
		}
		else {
			cout<<"List is already empty!\n";
		}
	}
	else {
		int index = 0;
		while(temp != NULL && index < pos) {
			temp = temp->next;
			index++;
		}
		if(index == pos) {
			Node *next = temp->next;
			Node *prev = temp->prev;
			prev->next = next;
			if (next != NULL) {
				next->prev = prev;
			}
			delete temp;
		}
		else {
			cout<<"Invalid position\n";
		}
	}
}

int main(int argc, char const *argv[])
{
	deleteNode(0);
	insertHead(5);
	insertHead(6);
	insertTail(7);
	insertTail(1);
	insertHead(2);
	print();
	deleteNode(2);
	print();
	printReverse();
	return 0;
}
