
#ifndef LINERARLIST_H
#define LINERARLIST_H
//这里是想干什么啊？使用虚函数有啥用？
template<class T>
class extendLinearList : linearList<T> {
public:
    virtual ~extendLinearList(){ }
    virtual void clear() = 0;
    virtual void push_back(const T & theElement) = 0;
    //将theElment 插入到表尾
};

template<class T>
void extendLinearList<T>::clear() {
//    firstnode指针，当在删除之前先将下一只留下
//    然后，删除，下一个
//    直到当前的元素是空的结，束
    while (firstNode != NULL) {
        chainNode<T> * nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    listSize = 0;
}

template<class T>
void extendLinearList<T>::push_back(const T& theElement) {
//    压入到队尾，队头是firstnode，队尾是lastnode
//    如果是第一个交接点，要注意把首尾节点全部的初始下
//    如果不是第一个，直接放到了lastnode的下一个，lastnode，下移
    chainNode<T> * newNode = new chainNode(theElement, NULL);
    if (firstNode == NULL) {
        firstNode = lastNode = newNode;
    } else {
        lastNode->next = newNode;
        lastNode = newNode;
    }
    listSize++;
}


#endif /* LINERARLIST_H */

