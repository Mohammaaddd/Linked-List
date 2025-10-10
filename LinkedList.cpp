#include <iostream>
#include "LinkedList.h"

void LinkedList::InsertAtBeginning(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void LinkedList::InsertAtEnd(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
}

void LinkedList::InsertAfter(int prevValue, int newValue)
{
	Node* prev = Search(prevValue);
	if (prev == nullptr) {
		std::cout << "Value " << prevValue << " not found.\n";
		return;
	}

	Node* newNode = new Node{ newValue, prev->next };
	prev->next = newNode;
}

void LinkedList::DeleteByValue(int value)
{
	if (head == nullptr) return;

	if (head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* current = head;
	while (current->next && current->next->data != value)
		current = current->next;

	if (current->next == nullptr) return;
	
	Node* temp = current->next;
	current->next = current->next->next;
	delete temp;

}

 Node* LinkedList::Search(int value)
{
	 Node* current = head;
	 while (current)
	 {
		 if (current->data == value)
			 return current;
		 current = current->next;
	 }
	 return nullptr;
}

void LinkedList::Print()
{
	Node* current = head;
	while (current)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}

void LinkedList::Clear()
{
	Node* current = head;
	while (current) 
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	//delete head;
	head = nullptr;
}
