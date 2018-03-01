
/* 
 * File:   main.cpp
 * Author: 李
 *
 * Created on 2017年9月7日, 下午9:47
 */

#include <cstdlib>
#include <cstdio>
#include<iostream>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>
#include "Permutations.h"
#include "ErrorCatching.h"


using namespace std;

template <typename T>
void Array_show(T a[], int len) {
    for (int i = 0; i < len; ++i) {
        //        cout << "N0. " << i << " : " << a[i] << endl;
        printf("NO.%3d: %4d\n", i, a[i]);
    }
}

template <typename T>
void arrayOneline_show(T a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "--";
    }
    printf("\n");
}

template<class T>
void show(T list[], int from, int to) {
    if (from == to) {
        //copy(list,list+from+1,cout_iterator<T>(cout,""));
        for (int i = 0; i < from + 1; i++)
            cout << list[i];
        cout << endl;
    } else {
        for (int i = from; i <= to; i++) {
            swap(list[from], list[i]);
            show(list, from + 1, to);
            swap(list[from], list[i]);
        }
    }
}

void find_number() {
    cout << "think a number in 0~100(must be int), let us do a game to find your number." << endl;
    cout << "you need tell me some information.\nIf it's smaller : input  'S' ,if not ,input  'B' " << endl;
    cout << "If I get it, you can input '1' to tell me that it is OK." << endl;
    int left = 0;
    int right = 100;
    int mid;
    int times = 0;
    char ch;
    while (1) {
        mid = (left + right) / 2;
        cout << "is it " << mid << " ? " << endl;
        times++;
        cin>>ch;
        if (ch == 's' || ch == 'S') {
            left = mid;
        } else if (ch == 'b' || ch == 'B') {
            right = mid;
        } else if (ch == '1') {
            cout << "I use " << times << " times to guess the answer. " << endl;
            cout << "I am so happy to guess what you think!!" << endl;
            cout << "Do you want try again ? input 'y' or 'n'   " << endl;
            cin>>ch;
            if (ch == 'y' || ch == 'Y') {
                left = 0;
                right = 100;
                times = 0;
                continue;
            }
            if (ch == 'n' || ch == 'N') break;
        }
    }
}

int from_2_to_next(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else {
        return from_2_to_next(n - 1) + from_2_to_next(n - 2);
    }
}

int from_2_to_next_(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else {
        //        return before2_to_next(n - 1) + before2_to_next(n - 2);
        int a0 = 1, a1 = 2, sum = 0, i = 0;
        while (i < n - 2) {
            sum = a0 + a1;
            a0 = a1;
            a1 = sum;
            i++;
        }
        return a1;
    }
}

int function(unsigned int n) {
    if (n % 2) {
        return function(3 * n + 1);
    } else return n / 2;
}

int function_(unsigned int n) {
    if (n % 2) {
        return 3 * (n - 1) / 2 + 2;
    } else return n / 2;
}
//ackermann's function

int Afun(int i, int j) {
    if (i < 1 || j < 1) {
        cout << "i and j must be >=1 " << endl;
        return (1);
    }
    if (i == 1) return pow(2, j);
    else if (i >= 2 && j == 1) return Afun(i - 1, 2);
    else Afun(i - 1, Afun(i, j - 1));
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (b > 0)
        return gcd(b, a % b);
}

template<class T>
T accumulateByOprator(T* start, T* end, T theAns, char op) {
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
T accumulate_1(T *start, T*end, T theSum) {
    for (int i = 0; i < end - start; i++) {
        theSum += *(start + i);
    }
    return theSum;
}

template<class T>
void copy_me(T* start, T* end, T* to) {
    for (int i = 0; i < end - start; i++) {
        *(to + i) = *(start + i);
    }
}

template<class T>
T product(T* a, int length) {
    int theProduct = 1;
    // return accumulateByOprator(a,a+length,theProduct,'*');
    //product意思是相乘
    for (int i = 0; i < length; i++) {
        theProduct *= a[i];
    }
    return theProduct;
}

template<class T>
T sum(T* a, int length) {
    int sum = 0;
    //return accmulate_1(a,a+length,sum);
    for (int i = 0; i < length; i++)
        sum += a[i];
    return sum;
}

template <typename T>
void permutations_1(T list[], int k, int m) {
    do {
        //???have some errors
        copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list, list + m + 1));
}

template <class T>
int indexOfMax(T a[], int n) {
    if (n <= 0) throw ErrorCatching("n must be > 0");
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[ans] <= a[i]) {
            ans = i;
        }
    }
    return ans;
}

template <class T>
int Find_index(T a[], int len, const T& key) {
    int i;
    for (i = 0; i < len && a[i] != key; i++)
        if (i == len) return -1;
    return i;
}

template <class T>
int FindIndex(T a[], int n, const T& key) {//这个是倒序在搜索的和原来是的不一样的
    if (n < 1) return -1;
    if (a[n - 1] == key) return n - 1;
    else return FindIndex(a, n - 1, key);
}
//求多项式：累加Ci*x^n在x处的值

template <typename T>
T polyEval(T coeff[], int n, const T& x) {
    //正向求解，每次y都是多乘上一个x
    T y = 1, value = coeff[0];
    for (int i = 1; i <= n; i++) {
        y *= x;
        value += y * coeff[i];
        // coffee是系数
    }
    return value;
}

template <typename T>
T polyEval_rescusion(T coeff[], int n, const T& x) {
    //逆向求解
    T value = coeff[n];
    for (int i = 1; i <= n; i++) {
        value = value * x + coeff[n - i];
        // 乘法的次数减少了，速度加快了
    }
    return value;
}

template <typename T>
void sort_position(T a[], int n) {
    int index_list[n];
    for (int i = 0; i < n; i++) index_list[i] = 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i]) index_list[i]++;
            else index_list[j]++;
        }
    Array_show(index_list, n);
}

template <typename T>
T * sort_position(T a[], int n, int r[]) {
    for (int i = 0; i < n; i++) r[i] = 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i]) r[i]++;
            else r[j]++;
        }
    return r;
}

template <typename T>
void sortBYposition(T a[], int n, T r[]) {
    //     int r[n];
    //    for (int i = 0; i < n; i++) r[i] = 0;
    //
    //    for (int i = 1; i < n; i++)
    //        for (int j = 0; j < i; ++j) {
    //            if (a[j] <= a[i]) r[i]++;
    //            else r[j]++;
    //        }
    T *temp = new T[n];
    for (int i = 0; i < n; ++i) {
        temp[r[i]] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = temp[i];
    }
    delete [] temp;
    temp = NULL;
}

template <typename T>
void sortBYposition_h(T a[], int n, T r[]) {//使其总保持映射的关系，直到映射和序号index相同为止
    for (int i = 0; i < n; i++) {
        while (r[i] != i) {
            int t = r[i];
            swap(a[i], a[t]);
            swap(r[i], r[t]);
        }
    }
}

template <typename T>
void select_sort(T a[], int n) {
    for (int size = n; size > 0; --size) {
        int j = indexOfMax(a, size);
        swap(a[j], a[size - 1]);
    }
}

template <typename T>
void bubble(T a[], int n) {//记录最后一次交换的位置可以减少比较的次数
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
}

template <typename T>
int bubble_h(T a[], int n) {//记录最后一次交换的位置可以减少比较的次数
    int pos = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            pos = i + 1;
        }
    }
//     arrayOneline_show(a,n);
}

template <typename T>
void bubble_sort(T a[], int n) {
    for (int i = n; i > 1;) {//为什么逆序？当每次结束之后总能够找到最大的值，下次搜索的长度自然要缩短
        i = bubble_h(a, i);
         arrayOneline_show(a,6);
    }
}

template <typename T>
void insert(T a[], int &n, const T& x) {//put x insert into array a[0...n-1],and size of array must be > n
    int i;
    for (i = 0; i < n && x > a[i]; ++i);
    for (int j = i; j < n; j++) {
        a[i] = a[i + 1];
    }
    a[i] = x;
    n++;
}

template <typename T>
void selectionSort(T a[], int n) {
    bool sorted = false;
    for (int size = 1; !sorted && (size > 1); size--) {//从后向前找到最大的数，交换位置
        int indexOfMax = 0;
        sorted = true;
        // 如果交换结果是空那证明已经全部有序
        for (int i = 0; i < size; ++i) {
            if (a[indexOfMax] <= a[i]) indexOfMax = i;
            else sorted = false;
            swap(a[indexOfMax], a[size - 1]);
        }
    }
}

template <typename T>
bool bubble_1(T a[], int n) {
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            swapped = true;
        }
    }
    //如果不再发生交换，那么已经排序完成
    return swapped;
}

template <typename T>
void bubble_sort1(T a[], int n) {
    for (int i = n; i > 1 && bubble_1(a, i); i--);
}

template <typename T>
void insert_sort(T a[], int n) {
    for (int i = 1; i < n; ++i) {
        T t = a[i];
        insert(a, i, t);
    }
}

template <typename T>
void insert_sort_1(T a[], int n) {
    //假定0到i-1之间的数字有序，而将a[i]插入,这个已经有序的序列
    for (int i = 1; i < n; i++) {
        T t = a[i];
        int j;
        for (j = i - 1; j >= 0 && t < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
        arrayOneline_show(a,n);
    }
     
}

template <typename T>
int binarySearch(T a[], int n, const T& x) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int middle = (left + right);
        if (x == a[middle]) return middle;
        if (x < a[middle]) return right = middle - 1;
        else return left = middle + 1;
    }
    return -1;
}
//template <typename T>
//void permutations_2(T list[], int k, int m) {
//    set<int> temp;
//    for(int i=k;i<m;i++)
//    {   
//        temp.insert(list[i]);
//    }
//    int len=temp.size();
//    int a[len],j=0;
//    for(set<int>::iterator ptr=temp.begin();!temp.empty();ptr++,j++)
//    {
//        a[j]=*ptr;
//        cout<<a[j];
//    }
//    do {
//        //???have some same output
//        copy(a, a + len + 1, ostream_iterator<T>(cout, ""));
//        cout << endl;
//    } while (prev_permutation(a, a + len + 1));
//}
//void subset(int length) {
//    if(length==1)
//    {
//        
//        
//    }  
//    return ans+="0"+subset(--length);
//}

//int g(unsigned int n)//haiMingsDistance
//{
//	if(n==1) return  1;
//                  cout<< g(n-1)<<n<<g(n-1);
//                  cout<<n;
//                 return g(n-1);
//}

int main(int argc, char** argv) {
    //1:    find_number();
    //2:   char list[3] = {
    //        'a', 'c', 'b'
    //    };
    //    show(list, 0, 2);
    // 3:   cout << "do you want to using recursive funtion? input 1 for YES and 0 for NO ." << endl;
    //    bool sign;
    //    cin>>sign;
    //    if (sign)
    //        cout << from_2_to_next(5) << endl;
    //    else
    //        cout << from_2_to_next_(5) << endl;
    // 4:   for(int i=1;i<11;i++)
    //    cout << function(i) <<"  "<<function_(i)<< endl;
    //5:    cout<<Afun(1,2)<<endl;cout<<Afun(2,1)<<endl;cout<<Afun(2,2)<<endl;
    // 6:   cout<<gcd(24,120)<<endl;
    //    char a[5] = {'a', 'b', 'c', 'd', 't'};
    //    int length = sizeof (a);
    //    cout << length << endl;
    //    subset(length);
    //    7:cout<<g(3)<<endl;
    //   8: int a[5] = {2, 3, 4, 5, 6};
    //     Permutations<int> temp;
    //    int product = sum(a, 5);
    //    int product1 = accumulateByOprator(a, a + 5, 1, '*');
    //    cout << product << endl;
    //    cout << product1 << endl;
    //   9:    char list[4]={'A','S','S','G'};;
    //        permutations_2(list,0,4);
    //     10:   int a[4]={
    //            2,67,4,0
    //        };
    //        int b[5];
    //        copy_me(a,a+4,b);sort(b,b+4);
    //        for(int i=0;i<4;i++){
    //            cout<<b[i];
    //        }
    // 11.   try{
    //        int a[4]={
    //            2,22,21,211
    //        };
    //        int x=indexOfMax(a,0);
    //        cout<<x<<endl;
    //    }catch(ErrorCatching e){
    //        cout<<"error happening !!!    ";
    //        e.output();
    //        exit(0);
    //    }
    int a[] = {
        6, 5, 8, 4, 3, 1
    };
     arrayOneline_show(a,6);
    //  if(binarySearch(a,6,26));
    //insert_sort_1(a, 6);
    //    select_sort(a, 4);
    insert_sort_1(a, 6);
    //    int r[4];
    //    sort_position(a, 4, r);
    //    sortBYposition(a, 4, r);
    //    Array_show(a, 16);
   
    return 0;
}

