
#ifndef STR_DISTANCE_H
#define STR_DISTANCE_H

#include <algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int editDistance(char* src, char* dest) {
    // 其实可以增加两个指针来遍历这两个字符串，不至于到最后丢失了原来的首地址
    int len1 = strlen(src), len2 = strlen(dest);
    if (len1 == 0 || len2 == 0) {
        return (len1 > 0) ? len1 : len2;
    }

    if (src[0] == dest[0]) {
        return editDistance(src + 1, dest + 1);
    }
    // 相当于是三个选择，每次可以选择三种出口递归
    // 每次都是对src串所做的操作
    int insert_dis = editDistance(src, dest + 1) + 1;
    int erase_dis = editDistance(src + 1, dest) + 1;
    int change_dis = editDistance(src + 1, dest + 1) + 1;

    return min(min(insert_dis, erase_dis), change_dis);
}
void show_0(char d[][])
{
     cout<<"       0  1  2  3  4  5  6  "<<endl;
        for (int i = 0; i < 7; i++) {
            cout <<i<<"      ";
        for (int j = 0; j < 7 ; j++) {
            int a=d[i][j];
            if(a>0)
            cout << a << "  ";
            else
            {
                cout<< "   ";
            }
        }
        cout << endl;
    }
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
}
void show_1(char d[][])
{
     cout<<"       0  1  2  3  4  5  6  "<<endl;
        for (int i = 0; i < 7; i++) {
            cout <<i<<"      ";
        for (int j = 0; j < 7 ; j++) {
            int a=d[i][j].distance;
            if(a>0)
            cout << a << "  ";
            else
            {
                cout<< "   ";
            }
        }
        cout << endl;
    }
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
}
typedef struct list_record {
    int distance;
    int times;
    //    bool used;
} Record;
Record memo[7][7]={0};

int editDistance_1(char* src, char* dest, int i, int j) {

    if (memo[i][j].times != 0) {
        memo[i][j].times++;
        return memo[i][j].distance;
    }

    int ans = 0;
    if (strlen(src + i) == 0) {
        ans = strlen(dest + j);
    } else if (strlen(dest + j) == 0) {
        ans = strlen(src + i);
    } else {
        if (src[i] == dest[j]) {
            ans = editDistance_1(src, dest, i + 1, j + 1);
        } else {
            int insert_dis = editDistance_1(src, dest, i, j + 1) + 1;
            int erase_dis = editDistance_1(src, dest, i + 1, j) + 1;
            int change_dis = editDistance_1(src, dest, i + 1, j + 1) + 1;

            ans = min(min(insert_dis, erase_dis), change_dis);
        }
    }
    memo[i][j].distance = ans;
    memo[i][j].times = 1;
    show_1(memo);
    return ans;
}

const long MAXLEN = 50;

int editDistance_2(char *src, char* dest) {
    int i, j;
    int d[MAXLEN][MAXLEN] = {0xffff};

    for (int i = 0; i < strlen(src); i++) {
        d[i][0] = i;
    }
    for (int i = 0; i < strlen(dest); i++) {
        d[0][i] = i;
    }
    //零行零列都已经被初始化好了，从低端的第一行第一列开始向上推导
    for (int i = 1; i <= strlen(src); ++i) {
        for (int j = 1; j <= strlen(dest); ++j) {
            if (src[i - 1] == dest[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                int insert_dis = d[i][j - 1] + 1;
                int erase_dis = d[i - 1][j] + 1;
                int change_dis = d[i - 1][j - 1] + 1;
                //                这三种方法都可使得当前的字符相同，但是想要他们中的最小的那个
                d[i][j] = min(min(insert_dis, erase_dis), change_dis);
            }
        }
    }
    show_0(d);
    return d[strlen(src)][strlen(dest)];
}

void test_distance() {
    char src[] = "SNOWY";
    char dest[] = "SUNNY";
    int ans = editDistance(src, dest);
    cout << ans << endl;
    ans = editDistance_2(src, dest);
    cout << ans << endl;
    ans = editDistance_1(src, dest, 0, 0);
    cout << ans << endl;

}
#endif /* STR_DISTANCE_H */

