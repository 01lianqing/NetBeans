
#ifndef FILE_READ_H
#define FILE_READ_H

#include<iostream>
#include<fstream>
using namespace std;

void write_once(char file_in[], char file_out[]) {
    //出现意外标记，说明自己有地方写的无法理解，导致后面错乱如char[] file;
    ifstream in;
    in.open(file_in, ios::in);
    if (!in) {
        cerr << "Error opening input stream" << endl;
        return;
    }
    ofstream out;
    out.open(file_out, ios::out);
    if (!out) {
        cerr << "Error opening output stream" << endl;
        return;
    }
    char ch;
    char last_ch = '@';


    while (!in.eof()) {
        in.get(ch);
        if ((ch == '\n') || (ch == '\t') || (ch == ' ')) {
            while ((ch == '\n') || (ch == '\t') || (ch == ' ')) in.get(ch);
            if (ch != '/') {//空格后面直接出现/一定是注释
                out << ' ' << ch;
            } else {
                last_ch = '/';
                continue;
            }
        } else if(ch =='/'){
            //如果是注释的话跳过
            if (last_ch == '/') {
                while (ch != '\n') in.get(ch);
            } else {
                last_ch = '/';
                continue;
            }
        } else if (ch == '*') {
            if (last_ch == '/') {
                while (ch != '/') in.get(ch);
            }
        } else {
            out << ch;
             last_ch = ch;
        }
    }

    in.clear();in.close();
    out.clear();out.close();
}
#endif /* FILE_READ_H */

