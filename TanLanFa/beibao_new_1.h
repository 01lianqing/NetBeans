#ifndef BEIBAO_NEW_1_H
#define BEIBAO_NEW_1_H
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
    bool state;//for_sort
    obj(){};

    obj(double a, double b, bool c = false) {
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

bool cmp(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;
}

bool cmp_(pair<Obj, int> a, pair<Obj, int>b) {
    return a.first.price > b.first.price || (a.first.price == b.first.price && a.first.weight < b.first.weight);
}

void sort_beibao(std::vector<Obj> objs, std::vector<int>& index_list, string flag) {
    int size = objs.size();
    std::pair<double, int> pair1[size];
    std::pair<Obj, int> pair2[size];
    bool button = true;// 选择不同的cmp方法
    if (flag == "price") {
        if (button) {
            for (int i = 0; i < size; i++) {
                double t = objs.at(i).price;
                pair1[i] = make_pair(t, i);
            }
            sort(pair1, pair1 + size, cmp);
            for (int i = 0; i < size; i++) {
                int n = pair1[i].second;
                index_list.push_back(n);
            }
        } else {
            /***************another way to compare*******************/
            for (int i = 0; i < size; i++) {
                pair2[i] = make_pair(objs.at(i), i);
            }
            sort(pair2, pair2 + size, cmp_);
            for (int i = 0; i < size; i++) {
                int n = pair2[i].second;
                index_list.push_back(n);
            }
        }
    } else if (flag == "price_dencity") {
        for (int i = 0; i < size; i++) {
            double t = objs.at(i).price_dencity;
            pair1[i] = make_pair(t, i);
        }
        sort(pair1, pair1 + size, cmp);
        for (int i = 0; i < size; i++) {
            int n = pair1[i].second;
            index_list.push_back(n);
        }
    } else if (flag == "weight") {
        for (int i = 0; i < size; i++) {
            double t = objs.at(i).weight;
            pair1[i] = make_pair(t, i);
        }
        sort(pair1, pair1 + size);
        for (int i = 0; i < size; i++) {
            int n = pair1[i].second;
            index_list.push_back(n);
        }
    } else {
        cerr << "try to check flag is in {weight/price/price_dencity}" << endl;
        return;
    }
    return;
}

void sort_beibao_(std::vector<Obj> objs, std::vector<int>& index_list, string flag) {
    int size = objs.size();
    //多次显示相同结果，表示没有重新编译
    if (flag == "price") {
        int t = 0;
        int index = -1;
        do {
            //            cout << "before" << index << "  "; //手动监控index
            int i = 0, j = size - 1;
            while (true) {
                //jump when the obj has been selected
                while (objs.at(i).state) i++;
                while (objs.at(j).state) j--;
                //when i=j means that find the max or min
                if (i == j) {
                    index = i;
                    break;
                }
                /*       if (i > j) break;
                 *这里我注意到对于双指针而言，不会出现left > right的状况
                 * 所以看到的是 i == j 就是唯一的出口
                 */
                if (objs.at(i).price > objs.at(j).price) {
                    index = i;
                    j--;
                } else {
                    index = j;
                    i++;
                }
            }
            //            cout << "after " << index << endl; //手动监控index
            objs.at(index).state = true;
            index_list.push_back(index);
            t++;
        } while (t < size);
    } else if (flag == "price_dencity") {
        int t = 0;
        int index = -1;
        do {
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
            objs.at(index).state = true;
            index_list.push_back(index);
            t++;
        } while (t < size);
    } else if (flag == "weight") {
        int t = 0;
        int index = -1;
        do {
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
            objs.at(index).state = true;
            index_list.push_back(index);
            t++;
        } while (t < size);
    } else {
        cerr << "try to check flag is in {weight/price/price_dencity}" << endl;
        return;
    }
    return;
}

double bag_pro(std::vector<Obj> objs, std::vector<int>& final_list, double bag_contain, string flag) {
    std::vector<int> index_list;
    int size = objs.size();
    sort_beibao(objs, index_list, flag); //pair<,>
    //    sort_beibao_(objs, index_list, flag);//双指针
    double final_price = 0.0;
    int i = 0, index = 0;
    do {
        index = index_list[i++];
        //        cout<<index<<" ";//for_test
        bag_contain -= objs[index].weight;
        //        有点穷举的意味，不行就返回去，保证检测一遍都装一下试试,直到装满为止
        if (bag_contain < 0) {
            bag_contain += objs[index].weight;
        }else if (bag_contain > 0) {
            final_price += objs[index].price;
            final_list.push_back(index);
        }else{
             final_price += objs[index].price;
            final_list.push_back(index);
            break;
        }
    } while (i < size);
    index_list.clear();
    return final_price;
}

void beibao_test2() {
    std::cout << "newsimpletest test 2" << std::endl;
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
        final_list.clear();
    }
}

#endif /* BEIBAO_NEW_1_H */

