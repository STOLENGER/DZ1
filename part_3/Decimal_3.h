//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_DECIMAL_3_H
#define DZ_1_2_OOP_DECIMAL_3_H
#include "Integer.h"
class Decimal : public Integer {

public:
    void Print (const Integer &b) override;
    void Minus(const Integer*other,Integer *result) override;
    void  Plus(const Integer *other, Integer * result)  override;
    void Multiply(const Integer *other,Integer *result) override;
    void Delen(const Integer* other,Integer *result) override;
};



#endif //DZ_1_2_OOP_DECIMAL_3_H
