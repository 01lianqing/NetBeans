

#include <cstdlib>
#include<iostream>
#include<iomanip>
#include "Height.h"
#include"arrayList.h"
#include "iterator.h"
#include "List_vector.h"
using namespace std;

void show() {
    Height h1;
    double t0, t1, dert;
    cout << "pay attention! time is by hours" << endl;
    cout << "input start time  ";
    cin>>t0;
    cout << "\ninput inscrement  ";
    cin>>dert;
    cout << "\ninput end  time  ";
    cin>>t1;
    cout << "time(/h)       height(/m)     speed(m/s)" << endl;
    for (double i = t0; i <= t1; i = i + dert) {
        cout << setw(6) << i << "       " << setw(10) << h1.getHeight(i) << "       " << setw(10) << h1.getSpeed(i) << endl;
    }
}

int main(int argc, char** argv) {
    List_vector<char> a(23);
    List_vector<char> b(23);
    List_vector<char> c(25);
    for (int i = 0; i < 24; i++) {
        c.push_back(i + 65);
    }
    c.split(a, b);
    cout << a << endl;
    cout << b << endl;
    cout << c;
    return 0;
}

