
/*并查集：
集合U，关系集合R是等价关系（自反，对称，传递）
等价：如果(a,b)属于R,就说a与b是等价的
等价类：包涵了等价元素的最大集合（可以推出的元素不包含在内）
举个简单点的例子，就是不想交的最大子图，各自形成一个最大的等价类

离线等价类：
就是已知到U,R，归纳得到静态的等价类
在线等价类：
combine(a,b) 相当于 A=find(a),B=find(b),if(A != B) { unite(A,B); }
find(a)
unite(classA,classB)

这里的在线等价类问题又叫并查集(union-find)问题
有两个主要的应用：机器调度问题和布线问题
1*机器调度问题
 i 按开始时间递减排序,记为list
ii 按list从头到尾，对于每一个任务确定一个
   空闲的时间段，如果这个时间段在开始的时间之前，失败，否则成功
 */
#ifndef ONESET_H
#define ONESET_H

#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;

const int MAX_TASK = 4;
const int ERROR = -1;
pair<int, int> task[MAX_TASK];
int nearest[MAX_TASK + 1];
//注意到这里简化了，并查集的本身自然不止是一个数，但是，
//这里可以用一个数来代表具体的集合属性
//实际上应是 classA[],find(classA)=>nearest(classA);

void init_() {
    int a1, a2;
    for (int i = 0; i < MAX_TASK; ++i) {
        cin >> a1>>a2;
        task[i] = make_pair(a1, a2);
        nearest[i] = i;
    }
    nearest[MAX_TASK] = MAX_TASK;
}

void unite(int classA, int classB) {
    nearest[classA] = nearest[classB];
}

int work_process() {
    sort(task, task + MAX_TASK);
    for (int i = 0; i < MAX_TASK; i++) {
        int start = task[i].first;
        int end = task[i].second;
        bool flag_find = false;
        for (int j = end; j > start; j--) {
//从末位的时间段找，不小于起始时间内可以找到，则为真
            if (nearest[end] != 0) {
                flag_find = true;
                unite(end, end - 1);
                break;
            }
        }
        if (flag_find) {
            continue;
        } else {
            return ERROR;
        }
    }
    return 1;
}

void for_test() {
    init_();
    int ans = work_process();
    cout << ans << endl;
}

#endif /* ONESET_H */

