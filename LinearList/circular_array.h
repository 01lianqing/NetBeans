

#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H
template <class T>
class circular_array : public arrayList<T>
{
    public:
        circular_array(){ this->arrayList();end=this->goToEnd();}
        
        void erase(int theIndex)  ;
        void insert(int theIndex, const T& theElement)  ;
    private :
        T* end;
};
template <typename T>
void circular_array<T>::insert(int theIndex, const T& theElement) {//attention : can insert into the final position
    if (theIndex == listSize);
    else checkIndex(theIndex);
    checkLength();
    if(theIndex>listSize/2){
//        copy_backward(element + theIndex, end+1, end + +2);
        for(int i=listSize;i>theIndex;i--)
        {
            element[i]=element[i-1];
        }
        end++;
    }  
    else{
        for(int i=0;i<=theIndex;i++)
        {
            element[i-1]=element[i];
        }
        element--;
    }     
    element[theIndex] = theElement;
    listSize++;
}

#endif /* CIRCULAR_ARRAY_H */

