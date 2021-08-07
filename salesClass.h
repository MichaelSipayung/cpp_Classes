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
//redefining sales_data class
class Sales_data_1{
    //friendship declaration for nonmembers sales_data1 operation added
    friend Sales_data_1 add(const Sales_data_1&,const Sales_data_1&);
    friend std::istream &read(std::istream&,Sales_data_1&);
    friend std::ostream &print(std::iostream&,const Sales_data_1&);
public:
    Sales_data_1()=default;
    Sales_data_1(const std::string&s):bookNo(s){}
    Sales_data_1(std::istream&);
    Sales_data_1(const std::string &s,unsigned  n, double  p):bookNo(s),unit_solds(n),revenue(p*n){}
private:
    double avg_price()const{
        return unit_solds?revenue/unit_solds:0;}
    std::string bookNo;
    unsigned  unit_solds=0;
    double revenue=0.0;
};
//declaration for nonmember parts of the salesData1 interface
Sales_data_1 add(const Sales_data_1&,const Sales_data_1&);
std::istream &read(std::istream&,Sales_data_1&);
std::ostream &print(std::ostream&,const Sales_data_1&);
//additional class features
class Screen{
public:
    typedef std::string::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
    char get()const{ //implicitly inline
        return contents[cursor];
    }
    //mutable data member
    void someMember()const;
    inline char get(pos ht,pos wd)const; //explicitly inline
    Screen &move(pos r , pos c);//can be made inline later
private:
    mutable  size_t access_ctr=0;
    pos cursor=0;
    pos height =0,width=0;
    std::string contents;
};
#endif //CLASSES_SALESCLASS_H
