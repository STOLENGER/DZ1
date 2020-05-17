//
// Created by Egor Salkov on 16.05.2020.
//

#include "Integer.h"

    Integer::Integer(int Size)
    {
        this->Size=Size;
        arr=new unsigned char[100];
        for (int i = 0; i <100 ; ++i) {
            arr[i]=0;
        }
    }
Integer:: ~Integer()
    {
        delete [] arr;
    }

    unsigned char & Integer::operator[](int i)
    {
        if (i > this->Size) {
            throw "Out of range exception";
        }
        return arr[i];
    }

    int Integer::GetSize() const
    {
        return Size;
    }
    bool Integer::operator>(Integer& other)
    {
        if(this->Size<other.Size)
            return false;
        if(this->Size>other.Size)
            return true;
        for (int i = other.Size; i >0 ; --i) {
            if (this->arr[i]<other[i])
                return false;
        }
        return true;
    }

    unsigned char &Integer::operator[](int i) const {
        if (i > this->Size) {
            throw "Out of range exception";
        }
        return arr[i];
    }

