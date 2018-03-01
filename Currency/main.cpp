
/* 
 * File:   main.cpp
 * Author: 李
 *
 * Created on 2017年9月12日, 下午3:50
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "currency.h"
#include "errorAndexcepction.h"
using namespace std;

template<class Ta, class Tb, class Tc>
Ta abc(const Ta& a, const Tb& b, const Tc& c) {
    if (a <= 0)
        throw 1;
    else if (b <= 0)
        throw 2;
    else if (c <= 0)
        throw 3;
    else if (a > 100 || b > 100 || c > 100)
        throw errorAndexcepction("input number should be smaller than 100 ."); //this char const *
    return a + b - c;
}

template <class T>
T count(T* a, T length) {
    return length;
}

template <class T>
void fill(T* a, int start, int end, const T& value) {
    for (int i = start; i < end; i++)
        *(a + i) = value;
}

template<class T>
T inner_product(const T* a, const T* b, int length) {
    T sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i] * b[i];
        cout << "a=" << a[i] << " b=" << b[i] << endl;
    }
    return sum;
}

template<class T>
void iota(T* a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) += i;
    }
}

template<class T>
bool is_sorted(T* a, int length) {
    int i = 0;
    int changes = 0;
    while (i < length) {
        if (a[i] > a[++i]) {
            changes++;
        }
    }
    if (changes == 0 || changes == length - 1) return true;
    else return false;
}

template<class T>
int mismatch(T* a, T* b, int len) {
    int i = 0;

    while (i < len) {
        if (a[i] == b[i]) {
            i++;
            continue;
        } else {
            cout << "not match in this place : ";
            return i;
        }
    }
    if (i == len) {
        cout << "matching perfect !!" << endl;
    }
}

template <class T>
void changeLength1D(T* &x, int oldlen, int newlen) {
    T* temp = new T[newlen];
    int min_len = 0;
    if (oldlen < newlen) min_len = oldlen;
    else min_len = newlen;
    for (int i = 0; i < min_len; i++)
        temp[i] = x[i];
    delete [] x;
    x = temp;
    temp = NULL;
    //        x=NULL;
    //        return temp;
    //本打算返回一个temp引用，但是给了warning，local变量不要传出去
    // 但是这是为什么？new不是在main里申请的空间吗？为什么warning。
}

template <class T>
void make2dArray(T** &s, int rows, int *num) {
    s = new T*[rows];
    for (int i = 0; i < rows; i++) {
        s[i] = new T[num[i]];
    }
}

template <class T>
T rsum(T *a, int n) {
//    return the sum of array
    if (n == 0) return 0;
    return (rsum(a, n - 1) + a[n - 1]);
}

int main(int argc, char** argv) {
    //    int * * s;
    //    int * n_0=new int [4];
    //    for(int i=0;i<4;i++)
    //        n_0[i]=7-i;
    //    make2dArray(s,4,n_0);
    //    for(int i=0;i<4;i++)
    //    {
    //        for(int j=0;j<n_0[i];j++)
    //            s[i][j]=i+j;
    //    }
    //    cout<<s[0][6]<<"   "<<s[1][4]<<"   "<<s[2][3];
    //    
    try {
        int a = 90, b = 90;
        double c = 999;
        cout << abc(a, b, c) << endl;
        currency *temp1 = new currency(cplus, 78, 839);
        currency *temp2 = new currency(cminus, 88, 90);
        cout << (*temp1)+(*temp2) << endl;
    } catch (errorAndexcepction e) {
        cout << "an error has been found !!" << endl;
        //when found one then it will stop;
        e.output_message();
        return 1;
    }


    //    (*temp1).output_1();
    //    (*temp2).output();
    //    long dollar=(*temp2).getDollars();
    //    cout<<dollar<<endl;
    //    if((*temp2)<(*temp1))
    //    {  
    //        currency ff=(*temp1).add(*temp2);
    //        ff.output();
    //        ff.increment(ff);
    //        ff.output_1();
    //        ff=ff.add(*temp1);
    //        ff.output_1();
    //    } else
    //        cout<<"compare is runing good"<<endl; 
    //       try{
    //           int *a=new int[10];
    //           fill(a,0,10,23);
    //           changeLength1D(a,10,7);
    //           cout<<a[4]<<endl;
    //       }catch(bad_alloc e){
    //           cout<<"an error has happened."<<endl;
    //           return 1;
    //       }

    //    int *b=new int[10];
    //    int a1,b1,c1;
    //    cin>>a1>>b1>>c1;
    //    try {
    //        cout<<abc(a1,b1,c1)<<endl;
    //    }catch(char const* e){
    //        cout<<"An exception has been thrown. "<<endl;
    //        cout<<e<<endl;
    //        return 1;
    //    }catch(int e){
    //        cout<<"An exception has been thrown."<<endl;
    //        cout<<"No." <<e<<" should >0 "<<endl;
    //    }
    //    fill(a,0,10,1);
    //    fill(b,0,10,9);
    //    iota(a,10);
    //    int c=inner_product(a,b,10);
    //    cout<<"累加a*b= "<<c<<endl;
    //    cout<<is_sorted(a,10)<<endl;
    //    cout<<mismatch(a,b,10)<<endl;
    //    delete [] a;
    //    delete [] b;
    //    a=NULL;
    //    b=NULL;
    return 0;
}

