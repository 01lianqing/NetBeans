
#ifndef ITERATOR_H
#define ITERATOR_H
template<class T>
class iteratorForMe
{
public:
  typedef T value_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef T& reference;


  iteratorForMe(T * thePosition =0){ position = thePosition;}
  T& operator*() const { return *position;}
  T* operator->() const { return &*position;}

  iteratorForMe& operator++() { ++position;return *this;}
  iteratorForMe& operator++(int) { iteratorForMe old=*this;++position;return old;}

  iteratorForMe& operator--() { --position;return *this;}
  iteratorForMe& operator--(int) { iteratorForMe old=*this;--position;return old;}

  bool operator==(const iteratorForMe right) const{
    return position == right.position;
  }
  bool operator!=(const iteratorForMe right) const{
    return position != right.position;
  }
  protected:
    T* position;
};

#endif /* ITERATOR_H */

