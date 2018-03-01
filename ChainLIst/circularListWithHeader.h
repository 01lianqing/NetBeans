
#ifndef CIRCULARLISTWITHHEADER_H
#define CIRCULARLISTWITHHEADER_H

#include<cstdlib>
#include "linearList.h"
#include "ChainNode.h"
using namespace std;

/*先声明几点:
 * 第一：带头结点，但是头节点是空的，没有元素
 * 第二:元素下标从头节点开始算起，头节点是0号位置
 * 第三：注意到访问数据的时候，我看是不考虑0的（对用户而言，没有必要）
 * 
 * */

template <class T>
class circularListWithHeader : public LinearList<T> {
public:
    circularListWithHeader();

    ~circularListWithHeader() {
    }

    bool empty() const {
        return listSize == 0;
    }

    int size() const {
        return listSize;
    }
    T& get(int theIndex) const;
    void change(int theIndex, const T& element) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

protected:
    ChainNode<T>* headerNode;
    int listSize;
};

template<class T>
circularListWithHeader<T>::circularListWithHeader() {
    headerNode = new ChainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}

template<class T>
T& circularListWithHeader<T>::get(int theIndex) const {

    // 
    ChainNode<T>* currentNode = headerNode ->next;
    while (theIndex--) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<class T>
void circularListWithHeader<T>::change(int theIndex, const T& element) const {
    this->get(theIndex) = element;
}

template<class T>
void circularListWithHeader<T>::erase(int theIndex) {

    if (theIndex == 1) {
        ChainNode<T>* currentNode = headerNode ->next;
        headerNode->next = headerNode->next->next;
        delete currentNode;
    } else {
        theIndex--; //因为我要找的事目标节点的前一个值
        ChainNode<T>* currentNode = headerNode ->next;
        while (theIndex--) {
            currentNode = currentNode->next;
        }
        ChainNode<T>* deleteNode = currentNode ->next;
        currentNode->next = currentNode->next->next;
        delete deleteNode;
    }
}

template<class T>
void circularListWithHeader<T>::insert(int theIndex, const T& theElement) {
    ChainNode<T>* insertNode = new ChainNode<T>(theElement, NULL);

    //find the before one
    ChainNode<T>* nowNode = headerNode;
    while (theIndex--) {
        nowNode = nowNode->next;
    }
    ChainNode<T>* next_one = nowNode->next;
    nowNode->next = insertNode;
    insertNode->next = next_one;
}

template<class T>
int circularListWithHeader<T>::indexOf(const T& theElement) const {
    headerNode->element = theElement;
    // 头节点原来是个空的节点
    ChainNode<T>* currentNode = headerNode ->next;
    int index = 0;
    while (currentNode->element != theElement) {
        index++;
        currentNode = currentNode->next;
    }

    if (currentNode == headerNode) {
        return -1;
    } else {
        return index;
    }
}

template<class T>
void circularListWithHeader<T>::output(ostream &out) const {
    for (ChainNode<T>* ptr_now = headerNode->next; ptr_now != headerNode; ptr_now = ptr_now->next) {
        out << ptr_now->element << " ";
    }
}

template<class T>
ostream& operator<<(ostream& out, const circularListWithHeader<T>& x) {
    x.output(out);
    return out;
}

void for_test2() {
    circularListWithHeader<int> cc;
    for (int i = 0; i < 3; i++) {
        cc.insert(i, i);
    }
    cout << cc <<endl;
}
#endif /* CIRCULARLISTWITHHEADER_H */

