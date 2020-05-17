//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_BINARY_H
#define DZ_1_2_OOP_BINARY_H

#include "Integer.h"

class Binary : public Integer
{
public:
    void Print (const Integer &b) override;
    void Minus(const Integer*other,Integer *result) override;
    void  Plus( const Integer *other, Integer * result)  override ;
    void Multiply(const Integer *other,Integer *result) override;
    void Delen(const Integer* other,Integer *result) override;

};



#endif //DZ_1_2_OOP_BINARY_H
