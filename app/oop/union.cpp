#include <iostream>
#include <string>
using namespace std;

union MyUnion
{
    short int a;
    int b;
    float c;
};

void union_fun()
{
    /*
    union - объединение
    позволяет хранить несколько переменных в одной области памяти
    если записать новые данные в область памяти для union, 
    то предыдущие данные будут утеренны

    объем выделяемой памяти для union равен самому большому значению в union (в MyUnion float)

    пример:
    */

    MyUnion u;

    u.a = 4; // a = 4 , b and c trash
    u.b = 45555; // b = 4555, a and c trash
    u.c = 466.11; // c = 466.11, a and b trash
    
}

int main()
{
    union_fun();
    return 0;
}