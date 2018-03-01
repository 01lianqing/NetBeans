/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Height.h
 * Author: 李
 *
 * Created on 2017年9月7日, 下午8:57
 */

#ifndef HEIGHT_H
#define HEIGHT_H

class Height {
public:
    Height();
    Height(const Height& orig);
    virtual ~Height();
    
    double getHeight(double t1);
    double getSpeed(double t);
private:
    double startTime,endTime;
    double height;
    double speed;

};

#endif /* HEIGHT_H */

