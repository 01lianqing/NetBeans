

/* 
 * File:   currency.h
 * Author: 李
 *
 * Created on 2017年9月17日, 下午5:03
 */

#ifndef CURRENCY_H
#define CURRENCY_H
#include<cmath>
#include<iostream>
using namespace std;
enum  signType
{
	cplus,cminus
};//cplus=0,cminus=1;
class currency
{
friend ostream& operator <<(ostream&,const currency&);   
//<< three steps:friend << ;put something to out;give the out to ostream <<.
public:
	currency(signType theSign = cplus,
		     unsigned long theDollars=0,
		     unsigned int theCents=0);
                  currency(const currency& orig);
	~currency(){}

	void setValue(signType,unsigned long,unsigned int);
	void setValue(double);
	//get value
	signType getSign() const {return sign;}
	unsigned long getDollars() const { return dollars*pow(-1.0,sign);}
	unsigned int getCents() const { return cents*pow(-1.0,sign);}
	//change value
	currency add(const currency&) const;
	currency& increment(const currency&);
	double changeToDouble() const;
	//show the currency
	void output_0() const;
                  void output_1();
                  void output(ostream& out ) const;
	//operator 
	bool operator<(const currency&) const;
                  currency operator+(const currency& x) const;
                  currency operator+=(const currency& x);
private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
                  double amount;
                  //after add amount,there is no need to using changetodouble,it is fantastic!!
};

#endif /* CURRENCY_H */

