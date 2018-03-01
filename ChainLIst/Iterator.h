
#ifndef ITERATOR_H
#define ITERATOR_H

class iterator{
public:
    iterator(ChainNode<T> * theNode = NULL){
        node = theNode;
    }
    T& operator*() const {
        return node->element;
    }
    T* operator&()const {
        return &node->element;
    }
    iterator& operator++() {
        node=node->next;
        return *this;
    }
protected:
    ChainNode<T> * node;

};

#endif /* ITERATOR_H */

