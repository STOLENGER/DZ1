//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_INTEGER_H
#define DZ_1_2_OOP_INTEGER_H

#include <iostream>
using namespace std;


class Integer
{
    unsigned char *arr;
public:
    int Size;
    virtual void Plus(const Integer *other,Integer * result)=0;
    virtual void Minus(const Integer *other,Integer * result)=0;
    virtual void Multiply(const Integer *other,Integer * result)=0;
    virtual void Delen(const Integer *other,Integer * result)=0;
    virtual void Print (const Integer &b)=0;

    Integer()
            :arr(nullptr),
             Size(0)
    {}
    Integer(int Size);

    ~Integer();
    unsigned char & operator[](int i);
    unsigned char & operator[](int i) const;
    int GetSize() const;
    bool operator>(Integer& other);
};


#endif //DZ_1_2_OOP_INTEGER_H
