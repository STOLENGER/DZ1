//
// Created by Egor Salkov on 16.05.2020.
//

#ifndef DZ_1_2_OOP_ARRAY_H
#define DZ_1_2_OOP_ARRAY_H


#include <iostream>
using namespace std;

class Array
{
    unsigned char *arr;
    int Size;
public:

    Array()
            :arr(nullptr),
             Size(0)
    {}
    Array(int Size);
    ~Array();
    int SizeIter();
    int GetSize() const;
    Array operator=(const Array &other);
    Array operator=(const int &other);
    unsigned char & operator[](int i);
    unsigned char & operator[](int i) const;
    bool operator>(const Array& other);
    bool operator<=(const Array& other);
    bool operator<(const Array& other);
    bool operator>=(const Array& other);
    bool operator==(const Array& other);
    bool operator!=(const Array& other);
    virtual void  Plus(const Array *other,Array * result);
    virtual void Minus(const Array*other,Array *result);
    virtual void Multiply(const Array *other,Array *result);
    virtual void Delen(const Array* other,Array *result);
    friend std::ostream &operator<<(std::ostream &out,Array &other);
    friend  std::istream &operator>>(std::istream &in, Array *other);

};


#endif //DZ_1_2_OOP_ARRAY_H
