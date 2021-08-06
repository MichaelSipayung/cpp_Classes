#ifndef CLASSES_SALESCLASS_H
#define CLASSES_SALESCLASS_H
#include <iostream>
struct Sales_data {
    //adding constructor
    Sales_data()=default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string&s,unsigned  n,double p):
        bookNo(s),unit_solds(n),revenue(p*n){}
    Sales_data(std::istream&);
        //---constructor adding (4) ....
    std::string isbn()const{return bookNo;}
    Sales_data&combine(const Sales_data&);
    double avg_price()const;
    std::string bookNo;
    unsigned unit_solds=0;
    double revenue=0.0;
};
Sales_data add(const Sales_data&,const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream&,Sales_data&);
#endif //CLASSES_SALESCLASS_H
