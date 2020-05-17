//
// Created by Egor Salkov on 16.05.2020.
//

#include "Payment.h"


Payment::Payment( char *firstname,char *name,char *otchestvo,Money salary,int year,float proc,int spentday,int workday)
{
    strcpy(this->firstname,firstname);
    strcpy(this->name,name);
    strcpy(this->otchestvo,otchestvo);
    this->salary=salary;
    this->year=year;
    this->proc=proc;
    this->spentday=spentday;
    this->workday=workday;
    NaSum=salary*spentday/workday+salary*proc;
    HoldSum=NaSum-Nalog-NaSum*0.01;
    Nalog=NaSum*0.13;
}

int Payment::GetYear()  const
{
    return 2020-year;
}
Money Payment::GetNaSum () const
{
    return NaSum;
}
Money Payment::GetHoldSum()  const
{
    return HoldSum;
}
Money Payment::GetNalog()  const
{
    return Nalog ;
}
Money Payment::GetMoney()
{
    return NaSum-HoldSum;
}

std::ostream &operator<<(std::ostream &out, Payment &other) {
    out << "firstname " <<other.firstname<<"\nname "<<other.name<<"\notchestvo "
        <<other.otchestvo<<"\nyear "<<other.GetYear()<<"\nmomey "<<other.NaSum-other.HoldSum<<std::endl;
    return out;
}
