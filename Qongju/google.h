

#ifndef GOOGLE_H
#define GOOGLE_H
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

// google 

typedef struct tagCharValue {
    bool used;
    int value;
} CHAR_VALUE;

typedef struct tagCharItem {
    char c;
    int value;
    bool leading;
} CHAR_ITEM;
typedef void (* CharListReadyFuncPtr) (CHAR_ITEM *);

const int max_char_count = 9;
const int max_num_count = 10;
// 中间看错了当成了一个值就是max_char_count,9就出不来
//常量变量定义一定要明确而且整齐，全部放到一个明白的地方
CHAR_ITEM ci[] = {
    {'W', -1, true},
    {'D', -1, true},
    {'O', -1, false},
    {'T', -1, false},
    {'G', -1, true},
    {'L', -1, false},
    {'E', -1, false},
    {'C', -1, false},
    {'M', -1, false}
};

CHAR_VALUE cv[] = {
    {false, 0},
    {false, 1},
    {false, 2},
    {false, 3},
    {false, 4},
    {false, 5},
    {false, 6},
    {false, 7},
    {false, 8},
    {false, 9}
};
int quan[] = {100000, 10000, 1000, 100, 10, 1};

int to_int(CHAR_ITEM ci[], char ch[]) {
    int ans = 0;
    for (int t = 0; t < strlen(ch); t++) {
        for (int i = 0; i < max_char_count; ++i) {
            if (ci[i].c == ch[t])
                ans += ci[i].value * quan[t];
        }
    }
    return ans;
}

void onCharListReady(CHAR_ITEM ci[]) {
    char minuend[] = "WWWDOT";
    char subtrahend[] = "GOOGLE";
    char diff[] = "DOTCOM";

    int m = to_int(ci, minuend);
    int n = to_int(ci, subtrahend);
    int p = to_int(ci, diff);

    if (!(m - n - p)) {
        cout << m << " - " << n << " = " << p << endl;
    }
}

bool IsValueValid(CHAR_ITEM ci, CHAR_VALUE cv) {
    if ((ci.leading && (cv.value == 0)) || cv.used)
        return false;
    return true;
}

void Searching_result(CHAR_ITEM ci[], CHAR_VALUE cv[], int index, CharListReadyFuncPtr callback) {
    if (index == max_char_count) {
        callback(ci);
        return;
    }
    for (int i = 0; i < max_num_count; ++i) {
        if (IsValueValid(ci[index], cv[i])) {
            cv[i].used = true;
            ci[index].value = cv[i].value;
            Searching_result(ci, cv, index + 1, callback);
            cv[i].used = false;//递归的释放使用权
        }
    }
}

void test_google() {
    Searching_result(ci, cv, 0, onCharListReady);

}
#endif /* GOOGLE_H */

