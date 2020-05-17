//
// Created by Egor Salkov on 16.05.2020.
//

#include "Decimal_2.h"
    void  Decimal::Plus(const Array *other,Array * result)
    {
        Array res(*this);
        if (res.GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 10) {
                    res[i] -= 10;
                    if (res[i + 1] == '\0') {
                        res.SizeIter();
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }

        } else {
            Array tmp;
            tmp = *other;
            other = result;
            *result = tmp;
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 10) {
                    res[i] -= 10;
                    if (res[i + 1] == '\0') {
                        res.SizeIter();
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }
        }
        *result=res;
    }


    void Decimal::Minus(const Array*other,Array *result)
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

    void Decimal::Multiply(const Array *other,Array *result)
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

            }
        }
        *result=*res;
    }
    void Decimal::Delen(const Array* other,Array *result)
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


