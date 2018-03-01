
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include"quick_sort.h"
using namespace std;

template<class T>
void test_quick_sort(char file[], vector<T>& vec) { 
    init(vec, file);
    int size = vec.size();
    cout << "~sorted:";
    show_vector(vec);
    quick_sort( vec , 0 , size - 1);
    cout << " sorted:"; 
    show_vector(vec);
}

int main(int argc, char** argv) {
    char file[] = "E:\\JAVA\\FenZhi\\vector.txt";
    char file1[] = "E:\\JAVA\\FenZhi\\vector2.txt";
    vector<int> vec;
    test_quick_sort(file,vec);
    vec.clear();
    test_quick_sort(file1,vec);
    return 0;
}

