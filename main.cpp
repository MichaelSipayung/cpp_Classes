#include "salesClass.h"
int main() {

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
