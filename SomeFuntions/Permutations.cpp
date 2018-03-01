
/* 
 * File:   Permutations<T>.cpp
 * Author: 李
 * 
 * Created on 2017年9月18日, 下午8:32
 */
//i want to write a class ,which can contain many ways to do same things;
#include "Permutations.h"
#include <iostream>
#include <cstdlib>
using namespace std;
template<class T> 
T Permutations<T>::accumulateByOprator( T* start,  T* end, T theAns, char op) {
    switch (op) {
        case'+':
            for (int i = 0; i < end - start; i++)
                theAns += *(start + i);
            break;
        case'-':
            for (int i = 0; i < end - start; i++)
                theAns -= *(start + i);
            break;
        case'*':
            for (int i = 0; i < end - start; i++)
                theAns *= *(start + i);
            break;
        case'/':
            for (int i = 0; i < end - start; i++)
                theAns /= *(start + i);
            break;
        case'%':
            for (int i = 0; i < end - start; i++)
                theAns %= *(start + i);
            break;
        default:break;
    }
    return theAns;
}
template<class T> 
T Permutations<T>::accumulate_1( T *start,  T*end, T theSum) {
    for (int i = 0; i < end - start; i++) {
        theSum += *(start + i);
    }
    return theSum;
}
template<class T> 
void Permutations<T>::copy_me( T* start,  T* end,  T* to) {
    for (int i = 0; i < end - start; i++) {
        *(to + i) = *(start + i);
    }
}
template<class T> 
T Permutations<T>::product(T* a, int length) {
    int theProduct = 1;
    // return accumulateByOprator(a,a+length,theProduct,'*');
    for (int i = 0; i < length; i++) {
        theProduct *= a[i];
    }
    return theProduct;
}
template<class T> 
T Permutations<T>::sum(T* a, int length) {
    int sum = 0;
    //return accmulate_1(a,a+length,sum);
    for (int i = 0; i < length; i++)
        sum += a[i];
    return sum;
}