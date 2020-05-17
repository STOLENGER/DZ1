#include <iostream>
#include "Application_1.h"
#include "Application_2.h"
#include "Application_3.h"
int main() {
   Application_1 a1;
   Application_2 a2;
   Application_3 a3;

   try{
       a1.run1();
       a2.run2();
       a3.run3();
   } catch (const std::exception&) {

   }
    return 0;
}
