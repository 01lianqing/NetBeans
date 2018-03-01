/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ErrorCatching.h
 * Author: 李
 *
 * Created on 2017年9月26日, 下午8:26
 */

#ifndef ERRORCATCHING_H
#define ERRORCATCHING_H
#include <string>
#include <iostream>

using namespace std;
class ErrorCatching {
public:
    ErrorCatching():message("There is an error !"){}
    ErrorCatching(const char* ptr){
        message=ptr;
    }
    ErrorCatching(const ErrorCatching& orig);
    virtual ~ErrorCatching();
    
    void output(){
        cout<<message<<endl;
    }
private:
    string message;
};

#endif /* ERRORCATCHING_H */

