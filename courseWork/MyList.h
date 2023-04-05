#pragma once
#include <iostream>
using namespace std;
template<typename T>
class MyList
{
public:
   
    struct Node {
        T val;
        Node* next;

        Node(T _val) : val(_val), next(nullptr) {}
    };
 
    MyList() : first(nullptr), last(nullptr) {}

    bool is_empty();
    void push_back(T _val);
    void remove_last();
    int size();
    void remove_first();
    Node* first;
    Node* last;
};
template<typename T>
inline bool MyList<T>::is_empty()
{
    return first == nullptr;
}

template<typename T>
void MyList<T>::push_back(T _val)
{
    Node* p = new Node(_val);
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}
template<typename T>
void MyList<T>::remove_first()
{
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
}

template<typename T>
void MyList<T>::remove_last()
{
    if (is_empty()) return;
    if (first == last) {
        remove_first();
    }
}

template<typename T>
int MyList<T>::size()
{
    if (!is_empty())
    {
        Node* p = first;
        int count = 1;
        while (p->next != nullptr) {

            count++;
            p = p->next;
        }
        return count;
    }
    else return 0;
}




