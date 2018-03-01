 
#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include<string>
#include<stack>
#include<iostream>
#include<set>
#include<map>

using namespace std;
const unsigned int INSIZE = 25;
const unsigned int MAX_NO = 5;

typedef struct N_ending {
    char ch;
    int n;
} No_end;

typedef struct Ending {
    char ch;
    int n;
} End_char;

const No_end no[] = {
    {'E', 0},
    {'A', 1}, //here using A as E'
    {'T', 2},
    {'B', 3}, //here using B as T'
    {'F', 4}
};

const End_char end[] = {
    {'i', 0},
    {'+', 1},
    {'*', 2},
    {'(', 3},
    {')', 4},
    {'#', 5}
};
//也可以从文件流输入
string yuFa[5][2] = {
    "TA", "",
    "+TA", "_",
    "FB", "",
    "*FB", "_",
    "(E)", "i"
};

bool is_ending_char(char ch) {
    for (int i = 0; i < 6; i++) {
        if (ch == no[i].ch) {
            return false;
        }
    }
    return true;
}

int find_number1(char ch) {
    if (!is_ending_char(ch)) {
        for (int i = 0; i < MAX_NO; i++) {
            if (ch == no[i].ch) {
                return i;
            }
        }
    } else {
        for (int i = 0; i < 6; i++) {
            if (ch == end[i].ch) {
                return i;
            }
        }
    }
}
set<char> first[MAX_NO];
set<char> follow[MAX_NO];

void follow_set() {

}

bool has_null(char ch) {
    int i = find_number1(ch);
    bool ans = false;
    for (set<char>::iterator it = first[i].begin(); it != first[i].end(); it++) {
        if ((*it) == '_')
            ans = true;
    }
    return ans;
}

void search_second(set<char> follow[], No_end Nchar) {
    int n = Nchar.n;
    char ch = Nchar.ch;
    if (n == 0) {
        follow[0].insert('#');
    }
    for (int i = 0; i < MAX_NO; i++) {
        for (int j = 0; i < 2; j++) {
            string temp = yuFa[i][j];
            int size_s = temp.size();
            size_t num = temp.find(ch);
            if (num + 1 < size_s) {
                char ch1 = temp.at(num + 1);
                if (is_ending_char(ch1)) {
                    follow[n].insert(ch1);
                } else {
                    //把非终结的first集合加入到当前的set集合;
                    int i = find_number1(ch1);
                    for (set<char>::iterator it = first[i].begin(); it != first[i].end(); it++) {
                        follow[n].insert(*it);
                    }
                }
            }
            if ((num + 1) == size_s) {//恰好是最后的字符
                char ch1 = temp.at(num + 1);
                if (!is_ending_char(ch1)) {
                    //  把这个非终结符的来源字符的follow加入到当前的set集合;
                    int i = find_number1(ch1);
                    for (set<char>::iterator it = follow[i].begin(); it != follow[i].end(); it++) {
                        follow[n].insert(*it);
                    }
                }
            }
            char ch2 = temp.at(size_s - 1);
            if (!is_ending_char(ch2) && has_null(ch2)) {
                // 把这个非终结符的来源字符的follow加入到当前的set集合;
                for (set<char>::iterator it = follow[i].begin(); it != follow[i].end(); it++) {
                    follow[n].insert(*it);
                }
            }
        }
    }
    follow[n].erase('_'); //处理掉那个空的动作
}

void test_forfollow() {
     for (int i = 4; i >= 0; i--)
        search_follow(follow, no[i]);
//     暂且认为这里经历了两次的循环之后，可以到达所谓的follow集合不再变化
//     否则我应该在写一个判定follow集合不再放大，不再改变
    for (int i = 0; i < MAX_NO; i++) {
        for (set<char>::iterator it = follow[i].begin(); it != follow[i].end(); it++) {
            cout << (*it) << " ";
        }
        cout << endl;
    }
}

void search_first(set<char> first[], No_end Nchar) {
    set<char> setdemo;
    int i = Nchar.n;

    for (int j = 0; j < 2; j++) {
        if (yuFa[i][j] != "") {
            char ch = yuFa[i][j].at(0);
            if (is_ending_char(ch)) {
                setdemo.insert(ch);
            } else {
                int n = find_number1(ch);
                for (set<char>::iterator it = first[n].begin(); it != first[n].end(); it++) {
                    setdemo.insert(*it);
                }
            }
        }
    }
    for (set<char>::iterator it = setdemo.begin(); it != setdemo.end(); it++) {
        first[i].insert(*it);
    }
}

void test_first() {
    for (int i = 4; i >= 0; i--)
        search_first(first, no[i]);
    for (int i = 0; i < 5; i++) {
        for (set<char>::iterator it = first[i].begin(); it != first[i].end(); it++) {
            cout << (*it) << " ";
        }
        cout << endl;
    }
}
string list_[5][6];
// false using "0" ;nothing using "$"

void init() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++) {
            list_[i][j] = "0";
        }

    list_[0][0] = "AT";
    list_[0][3] = "AT";
    list_[1][1] = "AT+";
    list_[1][4] = "$";
    list_[1][5] = "$";
    list_[2][0] = "BF";
    list_[2][3] = "BF";
    list_[3][1] = "$";
    list_[3][2] = "BF*";
    list_[3][4] = "$";
    list_[3][5] = "$";
    list_[4][0] = "i";
    list_[4][3] = ")E(";
    // as string : from 0 to n put into stack
}

template<class T>
void push_stack(string ans, stack<T> &stack_) {
    for (int i = 0; i < ans.size(); i++) {
        stack_.push(ans[i]);
    }
}

bool search_list_(char no_end, char end_c, string &ans) {
    int no_n = find_number1(no_end);
    int end_n = find_number1(end_c);
    if (list_[no_n][end_n] == "0") {
        return false;
    } else if (list_[no_n][end_n] == "$") {
        ans = "";
        return true;
    } else {
        ans = list_[no_n][end_n];
        return true;
    }
}

template<class T>
void show_stack(stack<T> &stack_) {
    //only for show the process
    int len = stack_.size();
    T temp[len];
    int index = len - 1;
    while (!stack_.empty()) {
        temp[index] = stack_.top();
        stack_.pop();
        index--;
    }
    for (int i = 0; i < len; i++) {
        cout << temp[i];
        stack_.push(temp[i]);
    }
    cout << endl;
}
// 5 main function

void yufa_fenxi() {
    stack<char> stack_;
    stack_.push('#');
    stack_.push('E');

    init();
    string input_stream;
    int n = 0;
    string ans; //keep list_
    cin>>input_stream;
    char now_ch = input_stream[n];
    char top_ch;
    bool flag = true;
    //    cin>>now_ch;
    while (flag) {
        top_ch = stack_.top();
        //        cout << " top_stack:  " << top_ch << endl;
        show_stack(stack_);
        stack_.pop();
        if ((top_ch != '#') && is_ending_char(top_ch)) {
            if (top_ch == now_ch) {
                if (n < (input_stream.size() - 1))
                    now_ch = input_stream[++n];
            } else {
                cerr << "there is something wrong 001 !" << endl;
                exit(1);
            }
        } else if (top_ch == '#') {
            if (top_ch == now_ch) {
                flag = false;
            } else {
                cerr << "there is something wrong 002 !" << endl;
                exit(1);
            }
        } else if (!is_ending_char(top_ch)) {
            if (search_list_(top_ch, now_ch, ans)) {
                if (ans != "") {
                    push_stack(ans, stack_);
                    ans = "";
                }
            } else {
                cerr << "there is something wrong 003 !" << endl;
                exit(1);
            }
        } else {
            cerr << "there is something wrong 004 !" << endl;
            exit(1);
        }
    }
}

//keep stack's content
// see the content of stack_ in debug windows
#endif /* STATIC_LIST_H */

