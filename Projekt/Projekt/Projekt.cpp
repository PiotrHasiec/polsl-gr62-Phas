#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include "SLE.h"
int main()
{
    {
        Matrix a(3, 4);
        Matrix b(1, 3);
        Matrix c{ 1,3 };
        a[0][0] =5;
        a[0][1] =2;
        a[0][2] = 1;
        a[0][3] = 20;
        a[1][0] = 3;
        a[1][1] = -5;
        a[1][2] = 1;
        a[1][3] = -5;
        a[2][0] = 1;
        a[2][1] = -4;
        a[2][2] = 10;
        a[2][3] = 30;

        
        
        a.wypisz();
     
        Solver* A = new Solver_Seidl;
        Solver* B = new Solver_Gauss;
        Solver* C = new Solver_Residuum;

        A->solv(a);
        B->solv(a);
        C->solv(a);
        C->results().wypisz(7, 4);
        B->results().wypisz(7, 4);
        A->results().wypisz(7, 4);
        delete A;
        delete B; 
        delete C;
    }
   
    _CrtDumpMemoryLeaks();
  
}
 
