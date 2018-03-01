

#ifndef BEIBAO_3_H
#define BEIBAO_3_H
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct obj {
    double weight;
    double price;
    double price_dencity;
    int state; //0 wait;1 yes;2 no

    obj() {
    };

    obj(double a, double b, int c = 0) {
        weight = a;
        price = b;
        price_dencity = b / a;
        state = c;
    }

} Obj;

void beibao_init(char file[], std::vector<Obj>& objs, double& bag_contain) {
    //出现意外标记，说明自己有地方写的无法理解，导致后面错乱如char[] file;
    ifstream in;
    in.open(file, ios::in);
    if (!in) {
        cerr << "Error opening input stream" << endl;
        return;
    }
    int N = 0;
    in >> bag_contain>>N;
    //    cout<<bag_contain<<endl;// for_test
    double w[N], p[N];

    for (int i = 0; i < N; i++) {
        in >> w[i];
    }
    for (int i = 0; i < N; i++) {
        in >> p[i];
    }
    for (int i = 0; i < N; i++) {
        //        cout<<w[i]<<"  "<<p[i]<<endl;//        for_test
        Obj obj(w[i], p[i]);
        objs.push_back(obj);
    }
    in.close();
    return;
}

int best_index(std::vector<Obj>& objs, string flag) {
    //多次显示相同结果，表示没有重新编译
    int size = objs.size();
    if (flag == "price") {
        int t = 0;
        int index = -1;
        int i = 0, j = size - 1;
        while (true) {
            //jump when the obj has been selected
            while (objs.at(i).state != 0) i++;
            while (objs.at(j).state != 0) j--;
            //when i=j means that find the max or min
            if (i == j) {
                index = i;
                break;
            }
            if (objs.at(i).price > objs.at(j).price) {
                index = i;
                j--;
            } else {
                index = j;
                i++;
            }
        }
        return index;
    } else if (flag == "price_dencity") {
        int t = 0;
        int index = -1;

        int i = 0, j = size - 1;
        while (true) {
            while (objs.at(i).state) i++;
            while (objs.at(j).state) j--;
            if (i == j) {
                index = i;
                break;
            }
            if (objs.at(i).price_dencity > objs.at(j).price_dencity) {
                index = i;
                j--;
            } else {
                index = j;
                i++;
            }
        }
        return index;

    } else if (flag == "weight") {
        int t = 0;
        int index = -1;

        int i = 0, j = size - 1;
        while (true) {
            while (objs.at(i).state) i++;
            while (objs.at(j).state) j--;
            if (i == j) {
                index = i;
                break;
            }
            if (objs.at(i).weight < objs.at(j).weight) {
                index = i;
                j--;
            } else {
                index = j;
                i++;
            }
        }
        return index;

    } else {
        cerr << "try to check flag is in {weight/price/price_dencity}" << endl;
        return -1;
    }
}

double bag_pro(std::vector<Obj>& objs, std::vector<int>& final_list, double bag_contain, string flag) {
    int size = objs.size();
    double final_price = 0.0;
    int i = 0, index = 0;
    do {
        //长时间不出结果也许是没有设置停止符i
        index = best_index(objs, flag);
        if(index==-1) cerr<<"something wrong in the index"<<endl;
        i++;
         bag_contain -=objs[index].weight ;
        //有点穷举的意味，不行就返回去，保证检测一遍都装一下试试,直到装满为止
        if ( bag_contain<0) {
            bag_contain +=objs[index].weight ;
            objs.at(index).state = 2;
        } else if (0 < bag_contain) {
            objs.at(index).state = 1;
            final_price += objs[index].price;
            final_list.push_back(index);
        } else {
            final_price += objs[index].price;
            final_list.push_back(index);
            break;
        }
    } while (i < size);
    return final_price;
}

void beibao_test3() {
    std::cout << "newsimpletest test 3" << std::endl;
    char file[] = "E:\\JAVA\\TanLanFa\\test1.txt";
    std::vector<Obj> objs;
    std::vector<int> final_list;
    string str[] = {"price", "weight", "price_dencity"};
    double bag_contain = 0;
    double final_price = 0.0;
    beibao_init(file, objs, bag_contain);

    for (int i = 0; i < 3; i++) {
        final_price = bag_pro(objs, final_list, bag_contain, str[i]);
        cout << "The final price in the bag : " << final_price << endl;
        cout << "NO: ";
        for (vector<int>::iterator it = final_list.begin(); it != final_list.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        for (vector<Obj>::iterator it = objs.begin(); it != objs.end(); it++) {
            //            cout<<(*it).state<<endl;//注意每次切换时状态要恢复为wait即state=0
            (*it).state = 0;
        }
        final_list.clear();
    }
}


#endif /* BEIBAO_3_H */

