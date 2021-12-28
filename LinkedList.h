// #ifndef _LinkedList_H
// #define _LinkedList_H
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class Node
{
public:
    T Data;
    Node *pNext;
    Node();
    Node(T);
    ~Node();
};

template <class T>
class LinkedList
{
private:
    Node<T> *pTail;
    Node<T> *pHead;

public:
    LinkedList();
    LinkedList(const LinkedList &);
    ~LinkedList();
    bool IsEmpty();
    int Size();
    void AddTail(const T &);
    void AddHead(const T &);
    void Insert();
    Node<T> *getHead();
    Node<T> *getTail();
    int Search(const T &);
    void RemoveHead();
    void RemoveTail();
    void RemoveNode(const T &);
    T &operator[](const int &);
};
template <class T>
Node<T>::Node(T value)
{
    this->Data = value;
    this->pNext = nullptr;
}
template <class T>
Node<T>::Node()
{
}
template <class T>
Node<T>::~Node()
{
}
template <class T>
LinkedList<T>::LinkedList()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList &l)
{
    this->pHead = l.pHead;
    this->pTail = l.pTail;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p;
    while (this->pHead != NULL)
    {
        p = this->pHead;
        this->pHead = this->pHead->pNext;
        delete p;
    }
}
template <class T>
bool LinkedList<T>::IsEmpty()
{
    if (this->pHead == NULL && this->pTail == NULL)
        return true;
    else
        return false;
}
template <class T>
int LinkedList<T>::Size()
{
    if (IsEmpty())
    {
        return 0;
    }
    Node<T> *temp = pHead;
    int NodeCounter = 0;
    while (temp != NULL)
    {
        NodeCounter = NodeCounter + 1;
        temp = temp->pNext;
    }
    return NodeCounter;
}
template <class T>
//test
void LinkedList<T>::AddHead(const T &value)
{
    Node<T> *p = new Node<T>(value);
    if (p != NULL)
    {
        if (this->pHead = NULL)
        {
            this->pHead = p;
            this->pTail = this->pHead;
        }
        else
        {
            p->pNext = this->pHead;
            this->pHead = p;
        }
    }
}
template <class T>
void LinkedList<T>::AddTail(const T &value)
{
    Node<T> *p = new Node<T>(value);
    if (p != NULL)
    {
        if (this->pHead == NULL)
        {
            this->pHead = p;
            this->pTail = this->pHead;
        }
        else
        {
            this->pTail->pNext = p;
            this->pTail = p;
        }
    }
}
template <class T>
Node<T> *LinkedList<T>::getHead()
{
    return this->pHead;
}
template <class T>
Node<T> *LinkedList<T>::getTail()
{
    return this->pTail;
}
template <class T>
int LinkedList<T>::Search(const T &value)
{
    int index = -1;
    if (!this->IsEmpty())
    {
        Node<T> *temp = this->pHead;
        while (temp)
        {
            index++;
            if (temp->Data == value)
            {
                return index;
            }
            temp = temp->pNext;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
    return -1;
}
template <class T>
void LinkedList<T>::RemoveHead()
{
    if (this->pHead != NULL)
    {
        Node<T> *p = this->pHead;
        this->pHead = this->pHead->pNext;
        delete p;
        if (this->pHead == NULL)
            this->pTail = NULL;
    }
    else
        return;
}
template <class T>
void LinkedList<T>::RemoveTail()
{
    Node<T> *p = nullptr;
    for (Node<T> *k = pHead; k != NULL; k = k->pNext)
    {
        if (k == pTail)
        {
            pTail = p;
            pTail->pNext = NULL;
            delete k;
            return;
        }
        p = k;
    }
}
template <class T>
void LinkedList<T>::RemoveNode(const T &value)
{
    Node<T> *p = this->pHead;
    Node<T> *q = NULL;
    while (p != NULL)
    {
        if ((p->Data) == value)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return;
    if (q != NULL)
    {
        if (p == this->pTail)
            this->pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        this->pHead = p->pNext;
        if (this->pHead == NULL)
            this->pTail = NULL;
    }
}
template <class T>
T &LinkedList<T>::operator[](const int &index)
{
    assert(index >= 0 && index < this->Size());
    Node<T> *p = this->pHead;
    for (int i = 0; i < index; i++)
    {
        p = p->pNext;
    }
    return p->Data;
}