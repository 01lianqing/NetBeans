

#ifndef BEIBAO_H
#define BEIBAO_H
//背包问题的动态规划:集中在放还是不放得到的价值最大
//背包容量为j,有i件物品可以选择，则最大价值s(i,j)=max(s[i-1,j],s[i,j-wi]+pi)
#include<fstream>
#include<iostream>
using namespace std;

double beibao_pro(int w[], double p[], int bag_contain, int N) {
    double s[N][bag_contain+1];
    for(int i=0;i<=bag_contain;i++)
        s[0][i]=0.0;
//    for(int i=0;i<N;i++)
//        s[1][w[i]]=p[i];
    int t=bag_contain;
    for (int i = 1; i <= N; i++) {
        int index=i-1;
        for(int t=0;t<=bag_contain&& t-w[index]>0;t++)
        s[i][t] =( s[i-1][t]>s[i][t-w[index]]+p[index]) ? s[i-1][t]:(s[i][t-w[index]]+p[index]);
    }
    return s[N-1][bag_contain];
}
void beibao_init(char file[], int w[], double p[], int bag_contain, int N) {
    ifstream in;
    in.open(file, ios::in);
    if (!in) {
        cerr << "Error opening input stream" << endl;
        return;
    }
    in >> bag_contain>>N;
    for (int i = 0; i < N; i++) {
        in >> w[i];
    }
    for (int i = 0; i < N; i++) {
        in >> p[i];
    }
    in.close();
    double final=beibao_pro(w,p,bag_contain,N);
    cout<<"final price is : "<<final<<endl;
    return;
}


#endif /* BEIBAO_H */

