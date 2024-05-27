#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;

	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value)
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}
	void printList()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void append(int value)
	{
		Node* newNode = new Node(value);

		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void deleteLast()
	{
		if (length == 0)
		{
			return;
		}

		Node* pre = head;
		Node* temp = head;

		while (temp->next != nullptr)
		{
			pre = temp;
			temp = temp->next;
		}

		tail = pre;
		tail->next = nullptr;
		length--;
		
		if (length == 0)
		{
			head = nullptr;
			tail = nullptr;
		}
		delete temp;

	}

	void prepend(int value)
	{
		Node* newNode = new Node(value);

		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	void deleteFirst()
	{
		if (length == 0)
		{
			return;
		}
		Node* temp = head;
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->next;
		}
		delete temp;
		length--;
	}

	Node* get(int index)
	{
		
		if (index < 0 || index >= length)
		{
			return nullptr;
		}

		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
	
	bool set(int index, int value) {
		Node* temp = get(index);
		if (temp != nullptr) {
			temp->value = value;
			return true;
		}
		return false;
	}

	bool insert(int index, int value) {
		if (index < 0 || index > length) {
			return false;
		}
		if (index == 0) {
			prepend(value);
			return true;
		}
		if (index == length) {
			append(value);
			return true;
		}

		Node* newNode = new Node(value);
		Node* temp = get(index-1);

		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}

	void deleteNode(int index) {
		if (index < 0 || index >= length) {
			return;
		}

		if (index == 0) {
			return deleteFirst();
		}
		if (index == length - 1) {
			return deleteLast();
		}

		Node* pre = get(index - 1);
		Node* temp = pre->next;

		pre->next = temp->next;
		delete temp;
		length--;	
	}

	void reverse() {
		Node* temp = head;
		head = tail;
		tail = temp;
		Node* after = temp->next;
		Node* before = nullptr;

		for (int i = 0; i < length; i++) {
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
	}

	~LinkedList()
	{
		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

int main()
{

	LinkedList* myLinkedList = new LinkedList(1);
	myLinkedList->append(2);
	myLinkedList->append(3);
	myLinkedList->append(4);
	myLinkedList->append(5);


	//myLinkedList->prepend(1);
	//myLinkedList->deleteNode(1);
	cout << "LL Before reverse():" << endl;
	myLinkedList->printList();

	myLinkedList->reverse();
	cout << "LL After reverse():" << endl;
	myLinkedList->printList();

	//cout << myLinkedList->get(2)->value;



}

