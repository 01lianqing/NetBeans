/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Height.cpp
 * Author: 李
 * 
 * Created on 2017年9月7日, 下午8:57
 */

#include "Height.h"
#include <cmath>
Height::Height() {
         startTime=0.0;
         endTime=0.0;
         height=0.0;
         speed=0.0;
}

Height::Height(const Height& orig) {
}

Height::~Height() {
}

double Height::getHeight(double t1){
    return -0.12*pow(t1,4)+12*pow(t1,3)-380*pow(t1,2)+4100*t1+220;
}
double Height::getSpeed(double t){
    return (-0.48*pow(t,3)+36*t*t-760*t+4100)/3600.0;
}
