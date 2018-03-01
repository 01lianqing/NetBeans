
/* 
 * File:   errorAndexcepction.h
 * Author: 李
 *
 * Created on 2017年9月17日, 下午8:16
 */

#ifndef ERRORANDEXCEPCTION_H
#define ERRORANDEXCEPCTION_H
#include<string>
#include<iostream>
using namespace std;
class errorAndexcepction {
public:
    errorAndexcepction():message("one error had beed found"){}
    errorAndexcepction(const char* theMessage){
        //say again, to pay attention to theKeyWord const_char*
        message=theMessage;
    }
    errorAndexcepction(const errorAndexcepction& orig);
    virtual ~errorAndexcepction();
    void output_message(){
        cout<<message<<endl;
    }
private:
    string message;
};

#endif /* ERRORANDEXCEPCTION_H */

