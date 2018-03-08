#include <iostream>
#include <stdio.h>

using namespace std;

struct Node {
	int data;
	Node *next;
};

int find(Node *node, int& result, int n){
	if(node == NULL) {
		return 0;
	}

	int index = find(node->next, result, n) + 1;
	if(index == n) {
		result = node->data;
	}
	return index;
}

void insert(Node **head, int data) {
	Node *temp = new Node();
	temp->data =data;
	temp->next = NULL;

	if(*head == NULL) {
		*head = temp;
	}
	else {
		Node *temp1 = *head;
		while(temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}

void printList(Node *head) {
	cout<<"List: ";
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

int main(int argc, char const *argv[]) {
	Node *head = NULL;
	insert(&head, 1);insert(&head, 45);insert(&head, 23);insert(&head, 58);
	printList(head);
	int result = -1;
	int n = 4;
	find(head, result, n);
	if(result == -1) {
		cout<<"Invalid index!\n";
	}
	else {
		cout<<n<<" from last: "<<result<<"\n";
	}
	return 0;
}
