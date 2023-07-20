// dlinked.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
template<class T>
class Node
{
public:
    T info;
    Node* prev;
    Node* next;

    Node(T val, Node* p = 0, Node* n = 0)
    {
        info = val;
        prev = p;
        next = n;
    }
    Node* getNext() { return next; }
    void setNext(Node* pt) { next = pt; }
    Node* getPrev() { return prev; }
    void setPrev(Node* pt) { prev = pt; }
    int getInfo() { return info; }
    void setInfo(int n) { info = n; }
};

template<class T>
class DLL
{
    Node<T>* head, * tail;
public:
    DLL() { head = tail = 0; }
    void addtoHead(T da)
    {
        head->setInfo(da);
    }
    bool removeItem(T d)
    {
        Node<T>* current = head;
        Node<T> * prevv=NULL;
        while (current != NULL)
        {
            if (current->data == d)
            { 
                prevv->next = current->next;
                current->next->prev = prevv
                    delete current;
                    return true;
            }
            prevv = current;
            current = current->next;
            
        }
        return false;


    }//returns true if item is found
    void removeallItem()
    {
        Node<T>* cuurent = head;
        Node<T>* deleteptr=head;
        while (cuurent !=NULL)
        {
            delete cuurent;
            deleteptr = deleteptr->next;
            cuurent = deleteptr;
        }
    }
    void addInOrder(T val)
    {
        Node<T>* cc = head;
        if (head == NULL || head->getinfo > val)
        {
            addtoHead(val);
        }
        else
        {
            while (cc->getNext() != 0 && cc->getNext()->getInfo() > val)
            {
                if (cc->getInfo() == 0)
                {
                    //addtotail
                    cc->getNext()->setInfo(val);
                }
                else
                {
                    Node<T>* nm = new Node(val, , cc->getNext());
                    cc->getNext()->setInfo(val);
                }
                
            }
            
        }
    }
    friend ostream& operator<<(ostream& os, const DLL<T>& obj)
    {
        Node<T>* n = obj.head;
        while (n != 0)
        {
            os << n->getInfo() << "->";
            n = n->getNext();
        }
        return os;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

