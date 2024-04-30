/*
Есть предложение «3 по цене 2» (или «2+1» , если хотите) на манго.
Для данного количества и цены (за манго) рассчитайте общую стоимость манго.

mango(2, 3) ==> 6    # 2 mangoes for $3 per unit = $6; no mango for free
mango(3, 3) ==> 6    # 2 mangoes for $3 per unit = $6; +1 mango for free
mango(5, 3) ==> 12   # 4 mangoes for $3 per unit = $12; +1 mango for free
mango(9, 5) ==> 30   # 6 mangoes for $5 per unit = $30; +3 mangoes for free
*/

#include <iostream>
using namespace std;

int mango(int quantity, int price)
{
    int temp = quantity/3;
    return (quantity - temp) * price;
}

int main()
{
    cout << mango(2, 3)<< endl;
    cout << mango(3, 3)<< endl;
    cout << mango(5, 3)<< endl;
    cout <<  mango(9, 5)<< endl;
    return 0;

}