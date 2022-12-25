#pragma once
#include <iostream>

struct  Node;
Node* addHead(Node* head, int val);
Node* addTail(Node* head, int val);

bool insert(Node* head, int pos, int val);

Node* removeHead(Node* head);
void removeTail(Node* head);
void removeAll(Node*& head);

void outList(Node* head);

Node* findData(Node* head, int val);
Node* findPos(Node* head, int pos);

void remove(Node*& head, int pos);

bool isEmpty(Node* head);

Node* retrieve(Node*& head, int pos);

void SortedInsert(Node*& head, Node* node);
Node* InsertionSort(Node*& head);

Node* addHead_(Node* head_, int val);
void outList_(Node* head_);
void SortedInsert_(Node*& head_, Node* list);
Node* InsertionSort_(Node*& head_);

void merge(Node* head, Node* head_);