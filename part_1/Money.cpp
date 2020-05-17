//
// Created by Egor Salkov on 16.05.2020.
//

#include "Money.h"


Money::Money(long rub,unsigned char cop)
{
    this->rub=rub;
    this->cop=cop;

}
Money::~Money()
{

}
int Money::GetcallClass()  const
{
    return GetcallClass();
}
Money& Money::operator+(const Money& other)
{
    Money res(*this);
    res.rub+=other.rub;
    res.cop+=other.cop;
    if(res.cop>=100)
    {
        res.rub++;
        res.cop-=100;
    }
    return res;
}


Money& Money::operator-(const Money& other)
{
    Money res(*this);
    res.rub-=other.rub;
    if(other.cop>res.cop)
    {
        res.rub--;
        res.cop+=100-other.cop;
    } else
    {
        res.cop-=other.cop;
    }
    return (res);
}
Money Money::operator=(const Money &other)
{
    if (this==&other)
        return *this;
    this->rub=other.rub;
    this->cop=other.cop;
    return *this;

}
bool Money::operator==(const Money &other)
{
    return (this->rub == other.rub) && (this->cop == other.cop);
}
bool Money::operator!=(const Money &other)
{
    return !((this->rub == other.rub) && (this->cop == other.cop));
}
bool Money::operator>(const Money &other)
{
    if(this->rub>other.rub)
        return true;
    else
    if(this->rub==other.rub)
    {
        return this->cop > other.cop;
    }
}
bool Money::operator>=(const Money &other)
{
    return !operator<(other);
}
bool Money::operator<=(const Money &other)
{
    return !operator>(other);
}
bool Money::operator<(const Money &other)
{
    if(this->rub<other.rub)
        return true;
    else
    if(this->rub==other.rub)
    {
        return this->cop < other.cop;
    }
}

Money Money::operator*(double a)
{
    this->rub*=a;
    int d= this->cop*a;
    this->rub+=d/100;
    this->cop+=d%100;
    return *this;
}
Money Money::operator/(double a)
{
    this->rub= this->rub/a;
    this->cop= this->cop/a;
    return *this;
}
std::ostream &operator<<(std::ostream &out, Money &other) {
    out << other.rub <<','<<other.cop<<std::endl;
    return out;
}
std::istream &operator>>(std::istream &in, Money &other)
{
    in >>other.rub;
    in >>other.cop;
    return in;
}

