

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <ostream>
#include "virtual_line.h"
#include "iterator.h"
#include "ErrorCatching.h"
#include <cmath>
#include <algorithm>
using namespace std;


template<class T>
class arrayList : public  virtual_line <T>
{
public:
    arrayList(int initialCapacity=10);
    arrayList( const arrayList<T>& orig);
    ~arrayList() { delete [] element;}
    //ADT
      bool empty() const { return listSize==0;} 
      int size() const { return listSize;}
      T&  get(int theIndex) const ;
      int indexOf(const T& theElement) const ;
      void erase(int theIndex)  ;
      void insert(int theIndex, const T& theElement)  ;
      void output(ostream&) const  ;

      //other methods
      int capacity() const { return arrayLength;} 
      void free_array(){  delete [] element; arrayLength=0;listSize =0;element =NULL;}
      void goToEnd() {   return element+listSize-1;}
      //iterator
//      class iteratorForMe ;
//      iteratorForMe begin() {  return iteratorForMe(element);  }
//      iteratorForMe  end() {   return iteratorForMe(element + listSize); }
protected:
    void checkIndex(int) const;
    void checkLength();
    T * element;
    int arrayLength;
    int listSize;

};

template <typename T>
arrayList<T>::arrayList(int initialcapacity) {
    if (initialcapacity < 1) {
        throw ErrorCatching("initialcapacity must be > 0 ");
    }
    arrayLength = initialcapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T>& orig) {
    arrayLength = orig.arrayLength;
    listSize = orig.listSize;
    element = new T[arrayLength];
    //from to dest
    copy(orig.element, orig.element + listSize, element);
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        throw ErrorCatching("error : index < 0 or index >= listSize !");
    }
}

template <typename T>
T& arrayList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

template <typename T>
int arrayList<T>::indexOf(const T& theElement) const {//find function: from to goal,return to a pointer
    int theIndex = (int) (find(element, element + listSize, theElement) - element);
    if (theIndex == listSize)
        return -1;
    else return theIndex;
}

template <typename T>
void arrayList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    checkLength();
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
    //具体的含义是什么？？
}
template <typename T>
void changeLength1D(T*& a, int oldlength, int newlength) {
    if (newlength < 0) {
        throw ErrorCatching("new length must be > 0");
    }
    T* temp = new T[newlength];
    int small_len = (oldlength < newlength ? oldlength : newlength);
    copy(a, a + small_len, temp);
    delete [] a;
    a = temp;
}
template <typename T>
void arrayList<T>::checkLength() {
    if (listSize == arrayLength) {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    if(listSize<arrayLength/4){
        changeLength1D(element,arrayLength,arrayLength/2);
    }
}

template <typename T>
void arrayList<T>::insert(int theIndex, const T& theElement) {//attention : can insert into the final position
    if (theIndex == listSize);
    else checkIndex(theIndex);
    checkLength();
    copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}

template <typename T>
void arrayList<T>::output(ostream& out) const {
    // copy(element ,element+listSize,ostream_iterator<T>(cout,""));
    for (int i = 0; i < listSize; i++)
        out << element[i] << "  ";
}

template <typename T>
ostream& operator<<(ostream& out, const arrayList<T>& x) {
    x.output(out);
    return out;
}

#endif /* ARRAYLIST_H */