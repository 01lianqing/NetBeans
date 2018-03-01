/*布线问题：
测试数据：两个 两个是相连的一条电线 (10组)
1 11 7 11 2 12 8 12 3 13 4 13 13 14 9 14 5 14 6 10

一：离线网络搜索
已知管脚n和电线(a,b)，确定网络(可以是图)最大数组
二：在线网络搜索
开始只知道一对管脚，然后加入边，不断的合并

概要分析:
边的集合R
顶点集合P
遍历R,找一个不再增大的集合P1
如果R的边没有全部处理掉，就继续

具体分析：
写了一会儿代码才有点感觉~
并查集的本质是群的概念，举个例子来讲就是
在非洲有很多的部落，每一个部落有一位首领
这样的首领是很有威信的，且只有一位
但不同的部落之间会有冲突，挑战
如果一方的首领打了败仗，自然就会被吞并
两者合并为一个部落，保持一个首领
每个部落的人根据自己首领的不同分为不同的类别和地位
至于连接可以认为是，个体的胜利，也有拉入阵营的效果
 template<class T>
typedef struct class_equ {
    vector<T> ans;
    //   char name;
    //   如果内容是字符，这里就不好使了。那不妨用数字
    //   string name;
    //   map<string,chain<T> > cla;
    //   name为首领标识

    class_equ(T i, char ch) {
        ans.push_back(i);
        name = ch;
    }

    bool has(T element) {
        if (ans.indexOf(element) != -1)
            return true;
        return false;
    }
} ECLASS;
 * 
 关于反复修改部落的标志：
 * 到目前来看，这个标志是与部落一一映射的，所以只要满足唯一性就是可行的
 * 至于类型可以是int，char，string都是可以的，只是作为直接的下标int更好
 * 简而言之，这些部落都要在一张大表上登记，vector<T> list[MAX_P];
 * 为了一次确定某一个值的族群，需要查表，从list -> 部落 就只需要一个下标
 * 
 * 
 * debug:
 * 1,template<class T>中的T必须在参数列表里或返回值上体现类型
 * 2, vector<T>::iterator it;//出现在代码中，总是报错
 * 3.函数的分布没有一定的逻辑，让这个思路也相当的烦躁
 * 4，出现的细节定义上的错误，要改就从头开始，中间的命名都是毛病
 * 所以前面想好了，再开始，不要怕简单，越是简单的工作越是有意义
 * 5.重名的问题，find，get之类直接的函数在头文件里都有，怕有歧义，就改的不同些
 * 6，找个有插座的教室，不要让电脑老是闪闪的
 * 7.改过之后，清理并编译
 * 8.临时变量 与 本身 使用clear(),效果不同？？
 * 9.想来算法本事就是一种动作到具体放入语言形式的不同细节处理
 *   这样看来我至少需要亲自运转一下具体的步骤，然后由具体到描述
 *   在转化为语言的版本
 */
#ifndef ONESET__H
#define ONESET__H
#include<iostream>
#include<vector>
#define DType int
using namespace std;


const int ERROR = -1;
const int MAX_B = 10;
const int MAX_P = 14;

typedef struct line {
    int start, end;

    line() {
    }

    line(int x, int y) {
        start = x;
        end = y;
    }
} D_XIAN;
D_XIAN R[MAX_B];
vector<int> P[MAX_P];

void init() {
    int a, b;
    for (int i = 0; i < MAX_B; ++i) {
        cin >> a>>b;
        //        cout<<a<<" "<<b<<" || ";
        R[i] = line(a, b);
    }
    for (int i = 0; i < MAX_P; ++i) {
        P[i].push_back(i + 1);
    }
}

void unite_(int &c1, int &c2) {
    // 将P[1] P[2] 的链表合并
    vector<DType> temp = P[c2];
    vector<DType>::iterator it;
    for (it = temp.begin(); it != temp.end(); it++)
        P[c1].push_back(*it);


    temp.clear(); //???

}

int find_(const DType &element) {
    for (int index = 0; index < MAX_P && (P[index].size()); index++) {
        vector<DType > t = P[index];
        vector<DType >::iterator it;
        for (it = t.begin(); it != t.end(); it++)
            if ((*it) == element)
                return index;
    }
    return -1;
}

void show_(vector<DType > t) {
    vector<DType >::iterator it;
    cout << " vector contain :";
    for (it = t.begin(); it != t.end(); it++)
        cout << " " << *it;
    cout << endl;
}

void process() {
    for (int i = 0; i < MAX_B; ++i) {
        line temp = R[i];
        int a = find_(temp.start);
        int b = find_(temp.end);
        cout << a + 1 << " <- index --" << b + 1 << endl;
        unite_(a, b);
    }
}

void test_for2() {
    init();
    process();
    for (int i = 0; i < MAX_P&&!P[i].empty(); i++) {
        cout << "NO. " << i + 1;
        show_(P[i]);
    }
}
#endif /* ONESET__H */

