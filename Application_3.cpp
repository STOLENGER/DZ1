//
// Created by Egor Salkov on 16.05.2020.
//

#include "Application_3.h"


void Application_3::run3() {
    int a;
    cout<<"1. Binary \n"
          "2. Decimal \n";
    cin>>a;
    Integer *a1(0);
    Integer *b(0);
    Integer *res;



    if(a==1)
    {
        a1=new Decimal;
        b=new Decimal;
        res=new Decimal;

        cout<<"1. Проверка +\n"
              "2. Проверка -\n"
              "3. Проверка *\n"
              "4. Проверка /\n";
        cin>>a;


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


    } else
    {
        a1=new Binary;
        b=new Binary;
       res=new Binary;
        cout<<"1. Проверка +\n"
              "2. Проверка -\n"
              "3. Проверка *\n"
              "4. Проверка /\n";
        cin>>a;
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

    }
    delete a1;
    delete res;
    delete b;


}
