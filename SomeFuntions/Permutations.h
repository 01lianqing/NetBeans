
/* 
 * File:   Permutations.h
 * Author: 李
 *
 * Created on 2017年9月18日, 下午8:31
 */

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
template<typename T>
class Permutations {
public:
    Permutations(){};
     ~Permutations(){};
    
    //member method
    T sum(T *,int );
    T product(T*,int );
    void copy_me( T* ,  T* ,  T* );
    void next_permutation(T *,T*);
    T accumulate_1( T *,  T*,T);
    T accumulateByOprator( T *,  T*,T,char);
   
};

#endif /* PERMUTATIONS_H */

