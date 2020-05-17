//
// Created by Egor Salkov on 16.05.2020.
//

#include "Application_2.h"

void Application_2::run2()
{
    int a;
    cout<<"1. Octal \n"
          "2. Decimal \n";
    cin>>a;
    Array *a1;
    Array *b;
    Array *res;

    if(a==1)
    {
        a1= new Octal;
        b = new Octal;
        res= new Octal;
        cout<<"1. Проверка +\n"
              "2. Проверка -\n"
              "3. Проверка *\n"
              "4. Проверка /\n";
        cin>>a;
        cout<<"Введите значение для A\n";
        cin>>a1;
        cout<<"Введите значение для B\n";
        cin>>b;
        switch (a) {
            case 1:
                a1->Plus(b, res);
                cout<<res;
            case 2:
                a1->Minus(b,res);
                cout<<res;
            case 3:
                a1->Multiply(b,res);
                cout<<res;
            case 4:
                a1->Delen(b,res);
                cout<<res;
        }
        if(*a1>*b)
            cout<<"A>B\n";
        if(*a1>=*b)
            cout<<"A>=B\n";
        if(*a1==*b)
            cout<<"A==B\n";
        if(*a1!=*b)
            cout<<"A!=B\n";
        if(*a1<*b)
            cout<<"A<B\n";
        if(*a1<=*b)
            cout<<"A<=B\n";


    } else
    {
        a1= new Decimal;
        b = new Decimal;
        res= new Decimal;

        cout<<"1. Проверка +\n"
              "2. Проверка -\n"
              "3. Проверка *\n"
              "4. Проверка /\n";
        cin>>a;
        cout<<"Введите значение для A\n";
        cin>>a1;
        cout<<"Введите значение для B\n";
        cin>>b;
        switch (a) {
            case 1:
                a1->Plus(b, res);
                cout<<res;
            case 2:
                a1->Minus(b,res);
                cout<<res;
            case 3:
                a1->Multiply(b,res);
                cout<<res;
            case 4:
                a1->Delen(b,res);
                cout<<res;
        }
        if(*a1>*b)
            cout<<"A>B\n";
        if(*a1>=*b)
            cout<<"A>=B\n";
        if(*a1==*b)
            cout<<"A==B\n";
        if(*a1!=*b)
            cout<<"A!=B\n";
        if(*a1<*b)
            cout<<"A<B\n";
        if(*a1<=*b)
            cout<<"A<=B\n";

    }
    delete a1;
    delete res;
    delete b;

}
