/*
Натан любит кататься на велосипеде.
Поскольку Натан знает, как важно избегать обезвоживания, он выпивает 0,5 литра воды за час езды на велосипеде.
Вам дается время в часах, и вам нужно вернуть количество литров, которые выпьет Натан, округленное до наименьшего значения.

time = 3 ----> litres = 1
time = 6.7---> litres = 3
time = 11.8--> litres = 5
*/

#include <iostream>
using namespace std;

int litres(double time)
{
    
    return time * 0.5;
}

int main()
{
    cout << litres(3) << endl;
    cout << litres(6.7) << endl;
    cout << litres(11.8) << endl;
    return 0;
}