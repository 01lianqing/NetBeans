/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List_vector.h
 * Author: 李
 *
 * Created on 2017年10月15日, 下午6:50
 */

#ifndef LIST_VECTOR_H
#define LIST_VECTOR_H
#include <vector>
#include <ostream>
#include "virtual_line.h"
#include "ErrorCatching.h"
using namespace std;

template<class T>
class List_vector : public virtual_line <T> {
public:
    List_vector(int initialCapacity = 10);
    List_vector(const List_vector<T>& orig);

    ~List_vector() {
        delete element;
    }

    bool empty() const {
        return element->empty();
    }

    int size() const {
        return element->size();
    }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream&) const;

    // incrasing method 
    void half();
    void meld(List_vector<T>& a, List_vector<T>& b);
    void marge(List_vector<T>& a, List_vector<T>& b);
    void split( List_vector<T>& a, List_vector<T>& b);
    //const 修饰下，不能够直接调用iterator访问元素
    void push_back(const T& theElement);

    int capacity()const {
        return element->capacity();
    }

    //  add iterator
    typedef typename vector<T>::iterator iterator;

    iterator begin() {
        return element->begin();
    }

    iterator end() {
        return element->end();
    }
protected:

    void checkIndex(int theIndex) const {
        if (theIndex < 0 || theIndex >= element->size())
            throw ErrorCatching("Index must be valid ");
    }
    vector<T>* element;
};

template<class T>
inline List_vector<T>::List_vector(int initialCapacity) {
    if (initialCapacity < 1) {
        throw ErrorCatching("initialcapacity must be > 0 ");
    }
    element = new vector<T>;
    element->reserve(initialCapacity);
}

template<class T>
List_vector<T>::List_vector(const List_vector& orig) {
    element = new vector<T>(*orig.element);
}

template<class T>
void List_vector<T>::erase(int theIndex) {
    checkIndex(theIndex);
    element->erase(begin() + theIndex);
}

template<class T>
void List_vector<T>::insert(int theIndex, const T& theElement) {
    if (theIndex != element->size())
        checkIndex(theIndex);
    element->insert(element->begin() + theIndex, theElement);
}

template<class T>
T& List_vector<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return *(element->begin() + theIndex);
}

template<class T>
int List_vector<T>::indexOf(const T& theElement) const {
    int index = 0;
    bool find = 0;
    typedef typename vector<T>::iterator iterator;
    for (iterator it1 = element->begin(); it1 != element->end(); it1++, index++) {
        if ((*it1) == theElement) {
            find = 1;
            break;
        }
    }
    if (find == 0) {
        cout << "there is not theElement" << endl;
        return -1;
    } else
        return index;
}

template<class T>
void List_vector<T>::output(ostream& out) const {
    typedef typename vector<T>::iterator iterator;
    for (iterator it1 = element->begin(); it1 != element->end(); it1++) {
        out << *it1 << " ";
    }
}

template <typename T>
ostream& operator<<(ostream& out, const List_vector<T>& x) {
    x.output(out);
    return out;
}

template<class T>
void List_vector<T>::half() {
    //奇数位置的元素都删掉,规律是动态变化的删除数字的下标连续改变
    //复杂度在O（n）
    typedef typename vector<T>::iterator iterator;
    int num = element->size() / 2;
    int i = 1;
    for (iterator it = element->begin(); i <= num;) {
        element->erase(it + i);
        i++;
    }
}

template<class T>
void List_vector<T>::meld(List_vector<T>& a, List_vector<T>& b) {
    //交替包涵ab里面的元素
    typedef typename vector<T>::iterator iterator;
    int alen = a.size();
    int blen = b.size();
    int num = alen + blen;
    element->reserve(num);
    int min = (alen < blen ? alen : blen);
    iterator it1 = a.begin();
    iterator it2 = b.begin();
    for (int i = 0; i < min; i++) {
        element->push_back(*it1);
        it1++;
        element->push_back(*it2);
        it2++;
    }
    int t = num - min;
    if (alen > min) {
        while (t--)
            element->push_back(*it1);
        it1++;
    } else {
        while (t--)
            element->push_back(*it2);
        it2++;
    }
}

template<class T>
void List_vector<T>::marge(List_vector<T>& a, List_vector<T>& b) {
    typedef typename vector<T>::iterator iterator;
    int alen = a.size();
    int blen = b.size();
    int num = alen + blen;
    element->reserve(num);
    int min = (alen < blen ? alen : blen);
    iterator it1 = a.begin();
    iterator it2 = b.begin();
    for (int i = 0; i < min; i++) {
        if (*it1<*it2) {
            element->push_back(*it1);
            it1++;
        } else {
            element->push_back(*it2);
            it2++;
        }
    }
    int t = num - min;
    if (alen > min) {
        while (t--) {
            element->push_back(*it1);
            it1++;
        }
    } else {
        while (t--) {
            element->push_back(*it2);
            it2++;
        }
    }

}
template<class T>
void List_vector<T>::split( List_vector<T>& a, List_vector<T>& b){

 typedef typename vector<T>::iterator iterator;
for(iterator it=element->begin();it!=element->end();)
{
  a.push_back(*it);it++;
  b.push_back(*it);it++;
}

}
template<class T>
void List_vector<T>::push_back(const T& theElement) {
    element->push_back(theElement);
}
#endif /* LIST_VECTOR_H */
