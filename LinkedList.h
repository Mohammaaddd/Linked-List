#pragma once
struct Node {
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr){}

    ~LinkedList(){
        Clear();
    }

    void InsertAtBeginning(int value);
    void InsertAtEnd(int value);
    void InsertAfter(int prevValue, int newValue);
    void DeleteByValue(int value);
    Node* Search(int value);
    void Print();
    void Clear();
};

