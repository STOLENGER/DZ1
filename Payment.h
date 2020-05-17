//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_PAYMENT_H
#define DZ_1_2_OOP_PAYMENT_H
#include "Money.h"

class Payment {

    char firstname[20];
    char name[20];
    char otchestvo[20];
    Money salary;
    int year;
    float proc;
    Money Nalog;
    int spentday;
    int workday;
    Money NaSum;
    Money HoldSum;
public:
    Payment( char *firstname,char *name,char *otchestvo,Money salary,int year,float proc,int spentday,int workday);
    int GetYear()  const;
    Money GetNaSum () const;
    Money GetHoldSum()  const;
    Money GetNalog()  const;
    Money GetMoney();
    friend std::ostream &operator<<(std::ostream &out, Payment &other) ;
};


#endif //DZ_1_2_OOP_PAYMENT_H
