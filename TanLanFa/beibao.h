#ifndef BEIBAO_H
#define BEIBAO_H
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

/*
 N objects, the bag can contain weight 0~C kg
 w[] to keep the object's weight
 p[] to keep the object's price
 try to find we should select which one or some to make the sum of price be maximising
 return the numbered list
 */

typedef struct obj {
    double weight;
    double price;
    double price_dencity;
    bool state;
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
    in>>bag_contain>>N;
//    cout<<bag_contain<<endl;// for_test
    double w[N], p[N];

    for (int i = 0; i < N; i++) {
        in>>w[i];
    }
    for (int i = 0; i < N; i++) {
        in>>p[i];
    }
    for (int i = 0; i < N; i++) {
//        cout<<w[i]<<"  "<<p[i]<<endl;//        for_test
        Obj obj(w[i], p[i]);
        objs.push_back(obj);
    }
    in.close();
    return;
}
bool cmp(pair<double,int> a,pair<double,int> b){
    return a.first>b.first;
}
void sortByprice(std::vector<Obj> objs, std::vector<int>& index_list) {
    //    create pair array -> sort by price Descending -> return index_list
    int size = objs.size();
    std::pair<double, int> pair1[size];

    for (int i = 0; i < size; i++) {
        double t=objs.at(i).price;
//        cout<<t<<" ";//        for_test
        pair1[i]=make_pair(t,i);
    }
//        cout<<endl;//        for_test
    sort(pair1, pair1 + size,cmp);
    
      for (int i = 0; i < size; i++) {
        int n=pair1[i].second;
//        cout<<n<<endl;// for_test
        index_list.push_back(n);
    }
}
void sortBywight(std::vector<Obj> objs, std::vector<int>& index_list) {
   //    create pair array -> sort by weight Ascending -> return index_list
    int size = objs.size();
    std::pair<double, int> pair1[size];

    for (int i = 0; i < size; i++) {
        pair1[i]=make_pair(objs.at(i).weight,i);
    }
    sort(pair1, pair1 + size);
    
      for (int i = 0; i < size; i++) {
        int n=pair1[i].second;
//        cout<<n<<endl;// for_test
        index_list.push_back(n);
    }
}
void sortByPrice_dencity(std::vector<Obj> objs, std::vector<int>& index_list) {
    int size = objs.size();
    std::pair<double, int> pair1[size];
    for (int i = 0; i < size; i++) {
        pair1[i]=make_pair(objs.at(i).price_dencity,i);
    }
    sort(pair1, pair1 + size,cmp);
      for (int i = 0; i < size; i++) {
        int n=pair1[i].second;
        index_list.push_back(n);
    }
}

double bag_pro_1(std::vector<Obj> objs, std::vector<int>& final_list, double bag_contain) {
    //    select by maxima of price 
    //    sort -> max -> check goto the next max until weight bigger than bag_contain
    std::vector<int> index_list;
   
    sortByprice(objs, index_list);
    double final_price = 0.0;
    int i = 0, index = 0;
    do {
        index=index_list[i++];
//        cout<<index<<" ";//for_test
        bag_contain -= objs[index].weight;
//        有点穷举的意味，不行就返回去，保证检测一遍都装一下试试,直到装满为止
        if (bag_contain < 0) {
            bag_contain += objs[index].weight;
        }else if(bag_contain>0){
            final_price += objs[index].price;
            final_list.push_back(index);
        }else{
             final_price += objs[index].price;
            final_list.push_back(index);
            break;
        }
    } while (true);
    index_list.clear();
    return final_price;
}
double bag_pro_2(std::vector<Obj> objs, std::vector<int>& final_list, double bag_contain) {
    //    select by min of weight 
    //    sort -> min -> check goto the next min until weight bigger than bag_contain
    std::vector<int> index_list;
   
     sortBywight(objs, index_list);
    double final_price = 0.0;
    int i = 0, index = 0;
    do {
        index=index_list[i++];
//        cout<<index<<" ";//for_test
        bag_contain -= objs[index].weight;
        if (bag_contain < 0) {
            bag_contain += objs[index].weight;
        }else {
            final_price += objs[index].price;
            final_list.push_back(index);
        }
    } while (true);
    index_list.clear();
    return final_price;
}
double bag_pro_3(std::vector<Obj> objs, std::vector<int>& final_list, double bag_contain) {
    //    select by min of weight 
    //    sort -> min -> check goto the next min until weight bigger than bag_contain
    std::vector<int> index_list;
   
    sortByPrice_dencity(objs, index_list);
    double final_price = 0.0;
    int i = 0, index = 0;
    do {
        index=index_list[i++];
//        cout<<index<<" ";//for_test
        bag_contain -= objs[index].weight;
        if (bag_contain < 0) {
            bag_contain += objs[index].weight;
        }else {
            final_price += objs[index].price;
            final_list.push_back(index);
        }
    } while (true);
    index_list.clear();
    return final_price;
}
 /*
     *     test1:w={35,30,60,50,40,10,25}
     *     p[]={10,40,30,50,35,40,30};
     *     bag_contain=150
     * 
     */
void beibao_test1() {
    std::cout << "newsimpletest test 1" << std::endl;
    char file[] = "E:\\JAVA\\TanLanFa\\test1.txt";
    std::vector<Obj> objs;
    std::vector<int> final_list, ans_list, ans_array; //意思相同，都是保存挑选的序号
    double bag_contain = 0;
    double final_price = 0.0;
    beibao_init(file, objs, bag_contain);
    final_price = bag_pro_1(objs, final_list, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = final_list.begin(); it != final_list.end(); it++) {
        cout << "N0." << *it<< " price " << objs[*it].price << endl;
    }
    final_price = bag_pro_2(objs, ans_list, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = ans_list.begin(); it != ans_list.end(); it++) {
        cout << "N0." << *it << " weight: " << objs[*it].weight << endl;
    }
    final_price = bag_pro_3(objs, ans_array, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = ans_array.begin(); it != ans_array.end(); it++) {
        cout << "N0." << *it<< " price_dencity " ;
        printf("%4.1lf\n",objs[*it].price_dencity );
    }
}
#endif /* BEIBAO_H */

