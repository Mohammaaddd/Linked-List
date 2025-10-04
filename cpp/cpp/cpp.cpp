
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void InsertAtBeginning(Node** head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = *head;

    *head = newNode;

}

void InsertAtEnd(Node** head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node* last = *head;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = newNode;
}

void Insert(Node* previous, int value) {
    if (previous == nullptr)
    {
        std::cout << "cant not be null";
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = previous->next;
    previous->next = newNode;
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    InsertAtBeginning(&head, 0);
    Insert(third, 4);
    InsertAtEnd(&head, 5);

    Node* cur = head;

    while (cur)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}


