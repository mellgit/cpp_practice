#include <iostream>
#include <vector>
using namespace std;

void vec_fun()
{
    // vector<int> my_vector = {23,43,65,87}; // так тоже можно инициализировать вектор
    // vector<int> my_vector(20); // инициализированный вектор из 20 нулей
    // vector<int> my_vector(10, 5); // инициализированный вектор из 10 пятерок
    vector<int> my_vector;
    my_vector.push_back(4);
    my_vector.push_back(43);
    my_vector.push_back(42);

    /*
    my_vector[10] = 300; //! НЕ гарантированния ошибка
    my_vector.at(6) = 4545; // гарантированния ошибка

    at - следит за тем, чтобы не уйти в другую область памяти
    в отличии от []
    но [] быстрее чем at, выбирается от задачи
    */

    for (int i = 0; i < my_vector.size(); i++)
    {
        cout<<my_vector[i]<<endl;
    }

    cout<<"vector size: "<<my_vector.size()<<endl; // размер вектора

    // my_vector.clear(); // чиста вектора
    // my_vector.pop_back(); // удаляет последний элемент вектора

    // my_vector.capacity(); // сколько элементов может поместиться в векторе (дополнительная память)
    // чтобы не перезаписывать вектор, тк под него выделяется больше памяти
    cout << "call capacity(): " << my_vector.capacity() << endl;

    my_vector.reserve(100); // сразу задать размер дополнительной памяти (размер capacity)
    cout << "call reserve(100)+capacity(): " << my_vector.capacity() << endl;

    my_vector.shrink_to_fit(); // удаляет неиспользуемую память (из capacity)
    cout << "call shrink_to_fit()+capacity(): " << my_vector.capacity() << endl; 

    my_vector.empty(); // проверка не пустой ли вектор: true - путсой false - заполнен
    cout << "call empty(): " << my_vector.empty() << endl;

    
}

int main()
{
    vec_fun();
    return 0;
}