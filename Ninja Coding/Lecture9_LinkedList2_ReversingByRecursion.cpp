#include <iostrea>
using namespace std;
#include "Node.cpp"

Node* reverseLL(Node *head) {
	
	//base case
	if(head == NULL || head -> next == NULL) {
		return head;
	}
	
	//breakimg ll into two
	//Assuming that we have alreadt reversed ll except forst one
	Node *smallAns = reverseLL(head -> next);
	
	//appending the head at end
	Node *temp = smallAns;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	//putting null at end
	temp -> next = head;
	head -> next = NULL;
	return smallAns;
}

Node* takeInput_Better() {
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

int main() {

	Node *head = takeInput_Better();
	head = reverseLL(head);
	print(head);



}
