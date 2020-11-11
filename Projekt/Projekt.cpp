#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <iomanip>
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

        
        
        a.print(0,5);
     
        Solver* A = new Solver_Seidl;
        Solver* B = new Solver_Gauss;
        Solver* C = new Solver_Residuum;
       
        ((Solver_i*)A)->set_precision(0.1);//A musi być typu solver_i (dziedziczyć po solver_i) bo inaczej nastąpi próba dostępu do składowej która nie istnieje w Solver
        //((Solver_i*)B)->set_precision(0.1); <- dostęp do składowej której solver gauss nie posiada
        A->solv(a);
        C->solv(a);
        std::cout << std::endl;
        C->results().print(2, 4);
        std::cout << std::endl;
       
        std::cout << std::endl;
        A->results().print(3);

        //{ a *= 0.1; }
        a= (a * 2);
         (2*a).print();
        a.print();
        B->solv(a);
        std::cout << std::endl;
        B->results().print(35);
        delete A;
        delete B; 
        delete C;
        a.add_d_x(3);
        a.add_d_y(20);
        a.set_d(4, 4);
        a[2][3] = 12.000001;
        for (int i =0;i<a.size_x();i++) a[3][i] = i *( i+1);
        std::cout << std::endl;
        std::cout << a[2][3]<<a.size_x()<<a.size_y();
        std::cout << std::endl;
     
        a.print(4);
        a = a * a;
        a.print(4);
    }
   
    _CrtDumpMemoryLeaks();
  
}
 
