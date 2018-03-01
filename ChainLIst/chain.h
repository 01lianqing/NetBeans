

#ifndef CHAIN_H
#define CHAIN_H
#include<ostream>
#include<iostream>
#include<cstdlib>
#include "linearList.h"
#include "ChainNode.h"
using namespace std;



template <class T>
class Chain : public LinearList<T> {
public:
    Chain(int intialCapacity);
    Chain(const Chain<T>&);

    ~Chain();

    bool empty() const {
        return listSize == 0;
    }

    int size() const {
        return listSize;
    }
    T& get(int theIndex) const;
    void change(int theIndex,const T& element) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

protected:
    void checkIndex(int theIndex) const;
    ChainNode<T>* firstNode;
    int listSize;
};

template<class T>
void Chain<T>::checkIndex(int theIndex) const {
    if (theIndex < 1 || theIndex > listSize) {
        cerr << "index happened error !!! " << endl;
    }
}
template<class T>
Chain<T>::~Chain(){
    ChainNode<T> * ptr = firstNode;
    while (ptr !=NULL) {
        ChainNode<T> *  temp=ptr;
        ptr=ptr->next;
        delete temp;
        temp=NULL;
    }
    firstNode=NULL;
}
template<class T>
Chain<T>::Chain(int intialCapacity) {
    ChainNode<T> *ptr = new ChainNode<T>(0);
    firstNode=ptr;
    for (int i = 2; i <= intialCapacity; i++) {
        ChainNode<T> * now = new ChainNode<T>(0);
        ptr->next =now;
        ptr=now;
    }
    ptr->next=NULL;
    listSize = intialCapacity;
}

template<class T>
Chain<T>::Chain(const Chain<T>& x) {
    ChainNode<T> * temp = new ChainNode<T>(x.get(1));
    firstNode = temp;
    for (int i = 2; i <= x.size(); i++) {
        ChainNode<T> * newNode = new ChainNode<T>(x.get(i));
        temp->next = newNode;
        temp = newNode;
    }
    listSize=x.size();
}

template<class T>
T& Chain<T>::get(int theIndex) const {
    checkIndex(theIndex);
    ChainNode<T> * ptr = firstNode;
    while (--theIndex) {
        ptr = ptr->next;
    }
    return ptr->element;
}
template<class T>
void Chain<T>::change(int theIndex,const T& element) const{
        checkIndex(theIndex);
    ChainNode<T> * ptr = firstNode;
    while (--theIndex) {
        ptr = ptr->next;
    }
    ptr->element =element;
}
template <class T>
int Chain<T>::indexOf(const T& theElement) const {
    ChainNode<T> * ptr_now = firstNode;
    int index = 1;
    while (ptr_now != NULL && ptr_now->element != theElement) {
        ptr_now = ptr_now->next;
        index++;
    }

    if (ptr_now == NULL) {
        return -1;
    } else {
        return index;
    }
}

template<class T>
void Chain<T>::erase(int theIndex) {
    checkIndex(theIndex);

    ChainNode<T> *deleteNode;
    if (theIndex == 1) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        //find the deleteNode 前一个节点
        ChainNode<T> *ptr = firstNode;
        for (int i = 1; i < theIndex - 1; i++) {
            ptr = ptr->next;
        }
        deleteNode = ptr;
        // 跳过要删除的节点，修改前一个的指针
        ptr->next = ptr->next->next;
    }

    listSize--;

    delete deleteNode;
}

template<class T>
void Chain<T>::insert(int theIndex, const T& theElement) {
    checkIndex(theIndex);

    if (theIndex == 1) {
        firstNode = new ChainNode<T>(theElement, firstNode);
    } else {
        ChainNode<T>* ptr = firstNode;
        for (int i = 1; i < theIndex - 1; i++) {
            ptr = ptr->next;
        }
        ptr->next = new ChainNode<T>(theElement, ptr->next);
    }
    listSize++;
}

template<class T>
void Chain<T>::output(ostream &out) const {
    for (ChainNode<T>* ptr_now = firstNode; ptr_now != NULL; ptr_now = ptr_now->next) {
        out << ptr_now->element << " ";
    }
}

template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x) {
    x.output(out);
    return out;
}

void for_test() {
    Chain<int> s1(7);
    cout<<s1<<endl;
    int index = 1;
    for (int i = 1; i < 8; i++) {
        s1.change(index, i);
        index++;
    }

    cout<<s1<<endl;
    s1.insert(6,100);
    s1.erase(1);
    cout<<s1<<endl;

}

#endif /* CHAIN_H */

