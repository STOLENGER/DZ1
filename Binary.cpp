//
// Created by Egor Salkov on 16.05.2020.
//

#include "Binary.h"
 void Binary:: Print (const Integer &b)
    {
        for (int i = b.GetSize(); i >0 ; ++i) {
            std::cout<<b.operator[](i);
        }

    }

    void Binary::Minus(const Integer*other,Integer *result)
    {
        Integer *res(this);

        if (res>other)
        {
            for (int i = 0; i <other->GetSize() ; ++i) {
                if (other->operator[](i)>res->operator[](i))
                {
                    int j=i+1;
                    while (res->operator[](j)==0){
                        res->operator[](j)=1;
                    }
                    res->operator[](i)= res->operator[](i)+2-other->operator[](i);
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
    void  Binary::Plus( const Integer *other, Integer * result) {
        if (this->GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                result->operator[](i) = other->operator[](i) + this->operator[](i);
                if (result->operator[](i) >= 2) {
                    result->operator[](i) -= 2;
                    if (result->operator[](i + 1) == '\0') {
                        result->Size++;
                        result->operator[](i + 2) = '\0';
                    }
                    result->operator[](i + 2) += 1;
                }
            }

        } else {
            Integer *tmp;
            *tmp = *other;
            other = result;
            result = tmp;
            if (this->GetSize() >= other->GetSize()) {
                for (int i = 0; i < other->GetSize(); ++i) {
                    result->operator[](i) = other->operator[](i) + this->operator[](i);
                    if (result->operator[](i) >= 2) {
                        result->operator[](i) -= 2;
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
    void Binary::Multiply(const Integer *other,Integer *result)
    {
        Integer  *res(this);
        for (int j = 0; j <res->GetSize(); ++j) {
            res->operator[](j)=0;
        }
        for (int j = 0; j <other->GetSize(); ++j){
            for (int i = 0; i < this->GetSize(); ++i) {

                res->operator[](j+i) += this->operator[](i) * other->operator[](j)% 10;
                if ((   res->operator[](j+i+1)=='\0')&&(this->operator[](i) * other->operator[](j) / 2>0))
                {
                    res->operator[](j+i+2)='\0';
                    res->Size++;
                    res->operator[](j+i+1)=0;
                }
                res->operator[](j+i+1) +=this->operator[](i) * other->operator[](j) / 2;//нужно чтобы век по умол был 0

            }
        }
        *result=*res;
    }
    void Binary::Delen(const Integer* other,Integer *result)
    {

        int m = 1;
        int c = 0;
        for (int i = 0; i < this->Size; i++)
        {
            c += m * (this->operator[](i) - '0');
            m *= 2;
        }
        int k = 0;
        m = 1;
        for (int i = 0; i < other->GetSize(); i++)
        {
            k += m * (other->operator[](i) - '0');
            m *= 2;
        }
        int sum = c / k;
        int sum1 = sum;
        int r = 0;
        while (sum != 0)
        {
            sum /= 2;
            r++;
        }
        result->Size = r;
        for (int i = 0; i < r; i++)
        {
            result->operator[](i) = (sum1 % 2) + '0';
            sum1 /=2;
        }
    }


