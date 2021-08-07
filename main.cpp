#include "salesClass.h"
int main() {
    Sales_data nextSales("cal-9Ed",12,4.0),firstSales("math-0x");//use your constructor
    std::cout<<"First sales \t: " <<firstSales.bookNo<<std::endl;
    std::cout<<"Sales name\t"<<nextSales.bookNo<<"\n"<<"Unit sold\t:"<<nextSales.unit_solds<<"\n"<<"reveneu\t:"<<nextSales.revenue<<std::endl;
    std::cout<<"test default constructor \n";
    Sales_data defaulConst;
    std::cout<<"Sales name\t"<<defaulConst.bookNo<<"\n"<<"Unit sold\t:"<<defaulConst.unit_solds<<"\n"<<"reveneu\t:"<<defaulConst.revenue<<std::endl;
    std::cout<<"use your combine ..."<<std::endl;
    Sales_data letsCombine("Discrete-3Ed",13,89.09);
    std::cout<<"Combine first sales dat to the second sales "<<std::endl;
    letsCombine.combine(nextSales);
    std::cout<<"After combine \t:"<<std::endl;
    std::cout<<"Sales name\t"<<letsCombine.bookNo<<"\n"<<"Unit sold\t:"<<letsCombine.unit_solds<<"\n"<<"reveneu\t:"<<letsCombine.revenue<<std::endl;
    std::cout<<"Evaluate it ..."<<std::endl;
    if(nextSales.isbn()==letsCombine.isbn()){
        std::cout<<"it's equal ...\n combine the total revenue and total sold ..."<<std::endl;
        letsCombine.combine(nextSales);
    }
    else{
        std::cout<<"different isbn number ....\n";
        std::cout<<"1.isbn \t: " << nextSales.bookNo<<std::endl;
        std::cout<<"2.isbn \t: " << letsCombine.bookNo<<std::endl;
    }
    std::cout<<"How it copied .... ?"<<std::endl;
    nextSales=letsCombine;
    std::cout<<"After copied ..."<<std::endl;
    std::cout<<"Sales name\t"<<nextSales.bookNo<<"\n"<<"Unit sold\t:"<<nextSales.unit_solds<<"\n"<<"reveneu\t:"<<nextSales.revenue<<std::endl;
    //test overloading
    //use screen class
    Screen myScreen;
    char ch=myScreen.get();
    std::cout<<"1.test overloading\t: "<<ch<<std::endl;
    ch = myScreen.get(0,11);
    std::cout<<"2.test overloading\t: "<<ch<<std::endl;
    myScreen.someMember();
    return 0;
}
double Sales_data::avg_price()const{
    if(unit_solds){
        return (revenue/unit_solds);
    }
    else{
        return 0;
    }
}
Sales_data&Sales_data::combine(const Sales_data &rhs) {
    unit_solds+=rhs.unit_solds;
    revenue+=rhs.revenue;
    return *this;
}
std::istream &read(std::istream&is,Sales_data&item){
    double price=0;
    is>>item.bookNo>>item.unit_solds>>price;
    item.revenue=price *item.unit_solds;
    return is;
}
std::ostream &print(std::ostream&os,const Sales_data&item){
    os<<item.isbn()<<" "<<item.unit_solds<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}
Sales_data add(const Sales_data&lhs,const Sales_data&rhs){
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
Sales_data::Sales_data(std::istream &is) {
    read(is,*this);
}
//making member inline
inline
Screen &Screen::move(pos r, pos c) {
    pos row=r*width;
    cursor=row+c;
    return *this;
}
char Screen::get(pos r,pos c) const {
    pos row=r*width;
    return  contents[row+c];
}
//...another test for different parameter
void Screen::someMember() const {
    ++access_ctr;
    std::cout<<"How much the class called\t: "<<access_ctr<<std::endl;
    std::cout<<"this function intended for apply mutable data member"<<std::endl;
}