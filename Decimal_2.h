//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_DECIMAL_2_H
#define DZ_1_2_OOP_DECIMAL_2_H

#include <iostream>
using namespace std;
#include "Array.h"
class Decimal : public Array {

public:

    Decimal():Array()
    {}
    Decimal(int Size):Array(Size)
    {}
    void  Plus(const Array *other,Array * result) override;
    void Minus(const Array*other,Array *result) override;
    void Multiply(const Array *other,Array *result) override;
    void Delen(const Array* other,Array *result) override;
};


#endif //DZ_1_2_OOP_DECIMAL_2_H
