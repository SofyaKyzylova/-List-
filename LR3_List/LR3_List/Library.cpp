#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

struct  Node
{
    int data;
    Node* next;
};

Node* addHead(Node* head, int val)
{
    Node* temp = new Node;
    temp->next = head;
    temp->data = val;

    head = temp;

    return head;
}

Node* addTail(Node* head, int val)
{
    Node* temp = new Node;
    temp->next = head;
    temp->data = val;

    Node* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->next = NULL;

    return head;
}

bool insert(Node* head, int pos, int val)
{
    if (pos == 1)
        return false;

    Node* p = findPos(head, pos - 1); 

    if (p == NULL)
        return false; 

    Node* temp = new Node;
    temp->data = val;
    temp->next = p->next;
    p->next = temp;

    return true;
}

Node* removeHead(Node* head)
{
    if (head == NULL)
        return 0;

    Node* temp = head;   
    head = temp->next;  
    delete temp;        

    return head;        
}

void removeTail(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp->next != NULL) 
    {
        temp = temp->next;
        count++;
    }

    delete temp;
    Node* p = findPos(head, count);
    p->next = NULL;
} 

void removeAll(Node*& head)
{
    Node* temp = head;
    Node* ptr;

    while (temp != NULL)
    {
        ptr = temp ->next;
        delete temp;
        temp = ptr;
    }
    head = NULL;
}

void outList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << setw(5) << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;
}

Node* findData(Node* head, int val)
{
    Node* temp = head;
    int pos = 0;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << " Ёлемент " << val << " находитс€ в €чейке " << pos + 1;
            return temp;
        }
        pos++;
        temp = temp->next;
    }
    return NULL;
}

Node* findPos(Node* head, int pos)
{
    Node* temp = head;

    while (temp != NULL && pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    return temp;
}

void remove(Node*& head, int pos)
{
    Node* p = findPos(head, pos);
    if (head == p)
        head = removeHead(head);

    Node* temp = head;
    while (temp->next && temp->next != p)
        temp = temp->next;

    if (temp->next)
    {
        temp->next = temp->next->next;
        delete p;
    }
}

bool isEmpty(Node* head) 
{
    return head == NULL;
}

Node* retrieve(Node*& head, int pos)
{
    Node* p = findPos(head, pos); 

    if (p == NULL)
        return head;
    else
        cout << p->data << endl;

    return head;
}

void SortedInsert(Node*& head, Node* node)
{
    if (!head || node->data < head->data)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node* current = head;
        while (current->next && !(node->data < current->next->data))
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }
}

Node* InsertionSort(Node*& head)
{
    Node* result = nullptr;

    while (head)
    {
        Node* node = head;
        head = head->next;
        SortedInsert(result, node);
    }

    return result;
}

Node* addHead_(Node* head_, int val)
{
    Node* temp = new Node;
    temp->next = head_;
    temp->data = val;

    head_ = temp;

    return head_;
}

void outList_(Node* head_)
{
    Node* temp = head_;

    while (temp != NULL)
    {
        cout << setw(5) << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;
}

void SortedInsert_(Node*& head_, Node* list)
{
    if (!head_ || list->data < head_->data)
    {
        list->next = head_;
        head_ = list;
    }
    else
    {
        Node* current = head_;
        while (current->next && !(list->data < current->next->data))
        {
            current = current->next;
        }

        list->next = current->next;
        current->next = list;
    }
}

Node* InsertionSort_(Node*& head_)
{
    Node* result = nullptr;

    while (head_)
    {
        Node* list = head_;
        head_ = head_->next;
        SortedInsert_(result, list);
    }

    return result;
}

void merge(Node* head, Node* head_)
{
    int count = 0;
    Node* temp = head;

    while (temp->next != NULL) 
    {
        temp = temp->next;
        count++;
    }
    Node* p = findPos(head, count); 
    p->next = head_;
}