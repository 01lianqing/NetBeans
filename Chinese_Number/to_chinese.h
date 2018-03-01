

#ifndef TO_CHINESE_H
#define TO_CHINESE_H
#include<string>
#include<iostream>
using namespace std;

const char *chnNumberChar[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
const char *chnUnitSection[] = {"", "万", "亿", "万亿"};
const char *chnUnitChar[] = {"", "十", "百", "千"};

void SectionToChinese(unsigned int section, string & ansStr) {
    string strTemp;
    int unitPos = 0;
    bool zero = true;

    while (section > 0) {
        int v = section % 10;
        if (v == 0) {
            if (section == 0 || (!zero)) {
                zero = true;
                ansStr.insert(0, chnNumberChar[v]);
            }
        } else {
            zero = false;
            strTemp = chnNumberChar[v];
            strTemp += chnUnitChar[unitPos];
            ansStr.insert(0, strTemp);
        }
        unitPos++;
        section /= 10;
    }
}

void NumberToChinese(unsigned int num, string &ansStr) {
    int unitPos = 0;
    string strTemp;
    bool needZero = false;

    while (num > 0) {
        unsigned int section = num % 10000;
        if (needZero) {
            ansStr.insert(0, chnNumberChar[0]);
        }
        SectionToChinese(section, strTemp);
        strTemp += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];
        ansStr.insert(0, strTemp);
        strTemp = "";//注意到要把临时变量清空
        needZero = (section < 1000) && (section > 0);
        num /= 10000;
        unitPos++;
    }
}

void test() {
    unsigned  int s = 4009060200;
    string ans;
    NumberToChinese(s, ans);
    cout << s << " is " << ans << endl;
}

#endif /* TO_CHINESE_H */

