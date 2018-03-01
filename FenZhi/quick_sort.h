
#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
int make_part(vector<T>& v, int left, int right) {
    // 怎样找到数字尽量靠中间的数
    int i=left,j=right+1;
    T Part_point = v.at(left);
    while (true) {
        // 一个取等一个不等，保证一个等一个追
        while (v[++i] < Part_point && i<right) ;
        while (v[--j] > Part_point) ;
        if (i >= j) break;
        //swap
        T temp = v.at(i);
        v.at(i) = v.at(j);
        v.at(j) = temp;
    }
    v[left]=v[j];
    v[j]=Part_point;
    return j;
}

template<typename T>
void quick_sort(vector<T>& v, int l, int r) {
    if (l == r) return;
    if (l < r) {
        int mid = make_part(v, l, r);
        //mid 的位置已经准确
        quick_sort(v, l, mid - 1);
        quick_sort(v, mid + 1, r);
    }
}

template<class T>
void init(vector<T>& vec, char file[]) {
    ifstream in;
    in.open(file, ios::in);
    if (!in) {
        cerr << "Error opening input stream" << endl;
        return;
    }
    T num = -1;
    while (true) {
        in>>num;
        if (num)
            vec.push_back(num);
        else break;
    }
    return;
}

template<class T>
void show_vector(vector<T>& v) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v.at(i) << "  ";
    }
    std::cout << std::endl;
}


#endif /* QUICK_SORT_H */

