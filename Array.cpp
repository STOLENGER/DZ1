//
// Created by Egor Salkov on 16.05.2020.
//

#include "Array.h"


    Array::Array(int Size)
    {
        this->Size=Size;
        arr=new unsigned char[100];
        for (int i = 0; i <100 ; ++i) {
            arr[i]=0;
        }
    }
    Array::~Array()
    {
        delete [] arr;
    }
    int Array::SizeIter()
    {
        return ++Size;
    }


    int Array::GetSize() const
    {
        return Size;
    }
    Array Array::operator=(const Array &other)
    {
        if (this==&other)
            return *this;
        this->Size=other.Size;
        for (int i = 0; i <other.Size ; ++i) {
            this->arr[i]=other.arr[i];
        }
        return *this;
    }
    Array Array::operator=(const int &other)
    {
        this->Size=other;
    }
    unsigned char & Array::operator[](int i)
    {
        if (i > this->Size) {
            throw "Out of range exception";
        }
        return arr[i];
    }
    unsigned char & Array::operator[](int i) const
    {
        if (i > this->Size) {
            throw "Out of range exception";
        }
        return arr[i];
    }
    bool Array::operator>(const Array& other)
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
    bool Array::operator<=(const Array& other)
    {
        return !operator>(other);
    }
    bool Array::operator<(const Array& other)
    {
        if(this->Size>other.Size)
            return false;
        if(this->Size<other.Size)
            return true;
        for (int i = other.Size; i >0 ; --i) {
            if (this->arr[i]>other[i])
                return false;
        }
        return true;
    }
    bool Array::operator>=(const Array& other)
    {
        return !operator<(other);
    }
    bool Array::operator==(const Array& other)
    {
        if(this->Size!=other.Size)
            return false;
        for (int i = 0; i <other.Size ; ++i) {
            if (this->arr[i]!=other[i])
                return false;
        }
        return true;
    }
    bool Array::operator!=(const Array& other)
    {
        return !operator==(other);
    }

     void Array::Plus(const Array *other,Array * result) {
        if (this->GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                result->operator[](i) = other->operator[](i) + this->operator[](i);
                if (result->operator[](i) >= 10) {
                    result->operator[](i) -= 10;
                    if (result->operator[](i + 1) == '\0') {
                        result->Size++;
                        result->operator[](i + 2) = '\0';
                    }
                    result->operator[](i + 2) += 1;
                }
            }

        } else {
            Array tmp;
            tmp = *other;
            other = result;
            *result = tmp;
            if (this->GetSize() >= other->GetSize()) {
                for (int i = 0; i < other->GetSize(); ++i) {
                    result->operator[](i) = other->operator[](i) + this->operator[](i);
                    if (result->operator[](i) >= 10) {
                        result->operator[](i) -= 10;
                        if (result->operator[](i + 1) == '\0') {
                            result->Size++;
                            result->operator[](i + 2) = '\0';
                        }
                        result->operator[](i + 2) += 1;
                    }
                }

            }

        }
    }
     void Array::Minus(const Array*other,Array *result)
    {
        Array *res(this);

        if (res>other)
        {
            for (int i = 0; i <other->GetSize() ; ++i) {
                if (other->operator[](i)>res->operator[](i))
                {
                    int j=i+1;
                    while (res->operator[](j)==0){
                        res->operator[](j)=9;
                    }
                    res->operator[](i)= res->operator[](i)+10-other->operator[](i);
                } else
                {
                    res->operator[](i)-=other->operator[](i);
                }

            }
        } else
        {
            throw "Мы не можем вычитать из значение которое меньше другого";
        }
        *result=*res;
    }

  void Array::Multiply(const Array *other,Array *result)
    {
        Array  *res(this);
        for (int j = 0; j <res->GetSize(); ++j) {
            res->operator[](j)=0;
        }
        for (int j = 0; j <other->GetSize(); ++j){
            for (int i = 0; i < this->GetSize(); ++i) {

                res->operator[](j+i) += this->operator[](i) * other->operator[](j)% 10;
                if ((   res->operator[](j+i+1)=='\0')&&(this->operator[](i) * other->operator[](j) / 10>0))
                {
                    res->operator[](j+i+2)='\0';
                    res->SizeIter();
                    res->operator[](j+i+1)=0;
                }
                res->operator[](j+i+1) +=this->operator[](i) * other->operator[](j) / 10;//нужно чтобы век по умол был 0
                //нужнв проверка на последний эл-т
            }
        }
        *result=*res;
    }
    void Array::Delen(const Array* other,Array *result)
    {

        int m = 1;
        int c = 0;
        for (int i = 0; i < this->GetSize(); i++)
        {
            c += m * (this->operator[](i) - '0');
            m *= 10;
        }
        int k = 0;
        m = 1;
        for (int i = 0; i < other->GetSize(); i++)
        {
            k += m * (other->operator[](i) - '0');
            m *= 10;
        }
        int sum = c / k;
        int sum1 = sum;
        int r = 0;
        while (sum != 0)
        {
            sum /= 10;
            r++;
        }
        *result = r;
        for (int i = 0; i < r; i++)
        {
            result->operator[](i) = (sum1 % 10) + '0';
            sum1 /= 10;
        }
    }


     std::ostream &operator<<(std::ostream &out,Array &other) {
        for (int i = other.Size; i >0 ; --i) {
            cout<<other[i];
        }

        return out;
    }
    std::istream &operator>>(std::istream &in, Array *other)
    {
        cout<<"Введите размер числа \n";
        cin>>other->Size;
        cout<<"Введите число\n";
        for (int i = other->Size; i >0 ; --i) {
            cin>>other->operator[](i);
        }
        return in;
    }