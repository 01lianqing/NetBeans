#ifndef WORD_H
#define WORD_H
#include<string>
#include<iostream>
#include<fstream>
#include<set>
using namespace std;

void word_init(char file_in[], char file_out[]) {
    cout << "word init begining " << endl;
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

    while (!in.eof()) {

        if (ch == '/') {
            in.get(ch);
            if (ch == '/')
                while (ch != '\n') in.get(ch);
            else if (ch == '*')
                while (ch != '/') in.get(ch);
            else {
                in.putback(ch);
            }
        } else if ((ch == '\n') || (ch == '\t') || (ch == ' ')) {
                while ((ch == '\n') || (ch == '\t') || (ch == ' ') )
                {
                    in.get(ch);
                }
                out << ' ';
                in.putback(ch);
        } else {
            out << ch;
        }
        in.get(ch);
    }
    cout << "word init successful " << endl;
    out.close();
    out.clear();
    in.close();
    in.clear();
    return;
}
typedef struct word
{
    string word_str;
    int code;
    word(string str,int c)
    {
        word_str=str;
        code=c;
    }

    bool
    operator<(const word& __y) const
    {
        return this->code < __y.code;
    }
} WORD;
const WORD list[] =
{
    {"#", 0},
    {"main", 1},
    {"if", 2},
    {"then", 3},
    {"while", 4},
    {"do", 5},
    {"static", 6},
    {"int", 7},
    {"double", 8},
    {"struct", 9},
    {"break", 10},
    {"else", 11},
    {"long", 12},
    {"switch", 13},
    {"case", 14},
    {"typedef", 15},
    {"char", 16},
    {"return", 17},
    {"const", 18},
    {"float", 19},
    {"short", 20},
    {"continue", 21},
    {"for", 22},
    {"void", 23},
    {"sizeof", 24},
    {"ID", 25},
    {"NUM", 26},
    {"+", 27},
    {"-", 28},
    {"*", 29},
    {"/", 30},
    {"**", 31},
    {"==", 32},
    {"<", 33},
    {"!=", 34},
    {"<=", 35},
    {">", 36},
    {">=", 37},
    {"=", 38},
    {"[", 39},
    {"]", 40},
    {";", 41},
    {"(", 42},
    {")", 43},
    {"}", 44},
    {"{", 45},
    {"&", 46},
    {"%", 47}
};

void digitFun(char &char1,set<string> & set_demo,ifstream& in,ofstream &out)
{
    string ans="";
    while((char1>='0'&&char1<='9')||char1=='.')
    {
        ans.push_back(char1);
        in.get(char1);
    }
    in.putback(char1);

    int code =set_demo.size();
    // set_demo.insert(word(ans,code));
    set_demo.insert(ans);
    out<<"("<<ans<<','<<code<<") ";
}

bool search_keyword(string& ans,ofstream &out)
{
    bool find =false;

    for ( int it=0 ; it <=47; it++ )
    {
        if(list[it].word_str==ans)
        {
            find=true;
            out<<"("<<list[it].word_str<<","<<it<<") ";
            break;
        }
    }
    return find;
}

void word_str(char &char1,set<string> & set_demo,ifstream& in,ofstream &out)
{
    string ans="";
    while((char1>='A'&&char1<='Z')||(char1>='a'&&char1<='z')||(char1 == '_'))
    {
        ans.push_back(char1);
        in.get(char1);
    }
    in.putback(char1);
    if(!search_keyword(ans,out))
    {
        int code =set_demo.size();
        // set_demo.insert(word(ans,code));
        set_demo.insert(ans);
        out<<"("<<ans<<','<<code<<") ";
    }
    return;
}
void process_word(char file_in[], char file_out[])
{
    cout << "begin process" << endl;

    ifstream in;
    in.open(file_in, ios::in);
    if (!in)
    {
        cerr << "Error opening input stream" << endl;
        return;
    }
    ofstream out;
    out.open(file_out, ios::out);
    if (!out)
    {
        cerr << "Error opening output stream" << endl;
        return;
    }

    char char1;
    string ans ="";
    set<string> set_demo;//_for user and numbers
    in.get(char1);
    while(char1 == ' ') in.get(char1);
    while(!in.eof())
    {

        if(char1>='0'&&char1<='9')
        {
            digitFun(char1,set_demo,in,out);
        }
        else if((char1>='A'&&char1<='Z')||(char1>='a'&&char1<='z')||(char1 == '_'))
        {
            word_str(char1,set_demo,in,out);
        }
        else if(char1 == '#')
        {
            out<<"('#', 0) ";
        }
        else if(char1 == '{')
        {
            out<<"('{', 45) ";
        }
        else if(char1 == '}')
        {
            out<<"('}', 44) ";
        }
        else if(char1 == '(')
        {
            out<<"('(', 42) ";
        }
        else if(char1 == ')')
        {
            out<<"(')', 43) ";
        }
        else if(char1 == ';')
        {
            out<<"(';', 41) ";
        }
        else if(char1 == '<')
        {
            out<<"('<', 33) ";
            in.get(char1);
            if(char1 == '=')
            {
                out<<"('<=', 35) ";
            }
            else
            {
                in.putback(char1);
            }
        }
        else if(char1 == '=')
        {
            out<<"('=', 38) ";
            in.get(char1);
            if(char1 == '=')
            {
                out<<"('==', 32) ";
            }
            else
            {
                in.putback(char1);
            }
        }
        else if(char1 == '>')
        {
            out<<"('>', 36) ";
            in.get(char1);
            if(char1 == '=')
            {
                out<<"('>=', 37) ";
            }
            else
            {
                in.putback(char1);
            }
        }
        else
        {
            out<<endl;
            out<<" -ERROR- "<<endl;
        }
        in.get(char1);
        while(char1 == ' ') in.get(char1);

    }

  //  set<string>::iterator it;
  //  for ( it=set_demo.begin() ; it != set_demo.end(); it++ )
  //      cout << " " << *it;

  //  cout << endl;

    out.close();
    out.clear();
    in.close();
    in.clear();
    cout << "process successful" << endl;
    return;
}

#endif /* WORD_H */
