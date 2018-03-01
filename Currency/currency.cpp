
/* 
 * File:   currency.cpp
 * Author: 李
 * 
 * Created on 2017年9月17日, 下午5:03
 */

#include "currency.h"
#include "errorAndexcepction.h"
//#include <iostream>
//
//using namespace std;

currency::currency(signType theSign ,unsigned long theDollars,unsigned int theCents) {
    setValue(theSign,theDollars,theCents);
}
currency::currency(const currency& orig) {}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    if(theCents>99) throw errorAndexcepction("the cents should be < 100 .");
    
//    if(theCents>99){
//        cout<<"the cents should be < 100"<<endl;
//        return ;
//    }
    sign=theSign;
    dollars=theDollars;
    cents= theCents;
    amount=(theDollars+theCents/100.0)*pow(-1.0,sign);
}
void currency::setValue(double theAmount)
{
	if(theAmount < 0){//change sign,and get abs()
		sign=cminus;theAmount=-theAmount;
	}
	else sign=cplus;
	dollars =(unsigned long ) theAmount;
	cents = (unsigned int)((theAmount - dollars+0.001)*100);
                  amount=theAmount;
}
currency currency::add(const currency& x) const
{
	currency result;
	double s1,s2;
	s1=this->changeToDouble();
	s2=x.changeToDouble();
        //or result.setValue(x.amount+this->amount);
	result.setValue(s1+s2);   
	return result;
}
bool currency::operator<(const currency& x) const
{
    if(this->changeToDouble()<x.changeToDouble())
        return true;
    else
        return false;
}
double currency::changeToDouble() const{
    double result=0.0;
    result=(double)dollars+(double)cents/100.0;//!!jingdu
    if(this->sign==cminus) result=-result;
    return result;
    //or return amount;
}
currency& currency::increment(const currency& s)
{
        *this= this->add(s);
        return *this;
}
void currency::output_0() const
{
    	 if(sign==cminus) cout<<'-';
	 cout<<dollars<<'.';
	 if(cents<10) cout<<'0';
	 cout<<cents<<'$'<<endl;
}
void currency::output_1(){
         cout<<this->changeToDouble()<<'$'<<endl;
}
void currency::output(ostream& out ) const
{
//     out<<this->changeToDouble()<<" $ ";
    out<<this->changeToDouble()<<'$';
}
ostream& operator<<(ostream& out, const currency& x)
{ //<< is osteam's object and do not belong to user's ,so he is our friend. 
    x.output(out);return out;
}
currency currency::operator+(const currency& x) const
{
    currency result;
    double sum=(this->changeToDouble())+x.changeToDouble();
    result.setValue(sum);
    return result;
}
currency currency::operator+=(const currency& x)
{
	*this=*this+x;
	return *this;
}