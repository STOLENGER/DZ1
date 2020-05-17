//
// Created by Egor Salkov on 16.05.2020.
//

#include "Application_1.h"
void Application_1::Arif() {
    int a;
    cout<<"1. Проверка +\n"
          "2. Проверка -\n"
          "3. Проверка *\n"
          "4. Проверка /\n";
    cin>>a;
    cout<<"Введите значения для A";
    Money A,B;
    callMoney+=2;
    cin>>A;
    switch (a) {
        case 1:
            cout<<"Введите значения для B\n";
            cin>>B;
            cout<<A+B;
            break;
        case 2:
            cout<<"Введите значения для B\n";
            cin>>B;
            cout<<A-B;
            break;
        case 3:
            double b;
            A=A*b;
            cout<<A;
            break;
        case 4:
            double b1;
            A=A/b1;
            cout<<A;
            break;
    }
}
void Application_1::Srav()
{
    Money A1,B1;
    callMoney+=2;
    cout<<"Введите значения для A\n";
    cin>>A1;
    cout<<"Введите значения для B\n";
    cin>>B1;
    if(A1>B1)
        cout<<"A1>B1\n";
    if(A1>=B1)
        cout<<"A1>=B1\n";
    if(A1==B1)
        cout<<"A1==B1\n";
    if(A1<B1)
        cout<<"A1<B1\n";
    if(A1<=B1)
        cout<<"A1<=B1\n";
}

void Application_1::run1()
{
    int a;
    cout<<"1. Проверка class Money\n"
          "2. Проверка class Paymenet \n";
    cin>>a;
    if(a==1)
    {
        cout<<"1. Арфметические операции\n"
              "2. Операции сравнения\n";
        cin>>a;
        switch (a) {
            case 1:
                Arif();
            case 2:
                Srav();
        }
    } else
    {
        char firstname[20]={"salkov"};
        char name[20]={"egor"};
        char otchestvo[20]={"dmitrievich"};
        Money salary(10000,00);
        callMoney++;
        callPayment++;
        Payment  paymenet(firstname,name,otchestvo,salary,1990,3,22,30);
        cout<<paymenet;
    }
}