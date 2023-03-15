#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;


void forward_list_fun()
{
    forward_list<int> f1 = {23,43};

    f1.push_front(3);
    f1.push_front(34);

    /*
    метода push_back нет, тк forward_list это односвязный список, 
    которых хранит в себе только указатель на сладующий элемент

    для решения этого необходим итератор и метод insert_after()

    */

    for (auto elem : f1)
    {
        cout<<elem<<endl;
    }
    
}

int main()
{
    forward_list_fun();
    return 0;
}