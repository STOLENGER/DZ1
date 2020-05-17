//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_MONEY_H
#define DZ_1_2_OOP_MONEY_H
#include <iostream>

class Money {
    long rub;
    unsigned char cop;

public:
    Money()
            :rub(0)
            , cop(00)
    {}
    Money(long rub,unsigned char cop);
    ~Money();
    int GetcallClass()  const;
    Money& operator+(const Money& other);
    Money& operator-(const Money& other);
    Money operator=(const Money &other);
    bool operator==(const Money &other);
    bool operator!=(const Money &other);
    bool operator>(const Money &other);
    bool operator>=(const Money &other);
    bool operator<=(const Money &other);
    bool operator<(const Money &other);
    Money operator*(double a);
    Money operator/(double a);
    friend std::ostream &operator<<(std::ostream &out, Money &other) ;
    friend  std::istream &operator>>(std::istream &in, Money &other);
};


#endif //DZ_1_2_OOP_MONEY_H
