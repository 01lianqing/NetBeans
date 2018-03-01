
#ifndef CHAINNODE_H
#define CHAINNODE_H

template<class T>
struct ChainNode {
    T element;
    ChainNode<T> *next;

    ChainNode() {
    }

    ChainNode(const T& element) {
        this->element = element;
    }
    //in the index to insert a new node 

    ChainNode(const T& element, ChainNode<T> *next) {
        this->element = element;
        this->next = next;
    }

};

#endif /* CHAINNODE_H */

