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


void iter_vec()
{
    vector<int> my_vector = {34,65,2,4,45};

    vector<int>::iterator it; // перегрузка итератора
    // vector<int>::const_iterator it; // константный итератор, дабы не изменить эл-ты вектора (кортеж)

    it = my_vector.begin(); // итератор дает доступ к первому эл-ту вектора

    cout<<*it<<endl; // 34

    *it = 200; // изменить первый элемент вектора(только с *) 
    cout << *it << endl; // 200

    it++; // итерация по вектору
    cout << *it << endl; // 65

    it+=2;
    cout << *it << endl; // 4

    cout<<"cycle for"<<endl;
    for (vector<int>::iterator i  = my_vector.begin(); i!=my_vector.end(); i++)
    {
        // реализация с константными итераторами
        // for (vector<int>::const_iterator i  = my_vector.cbegin(); i!=my_vector.cend(); i++)

        /*
        my_vector.end() - указывает на пустоту, после последнего эле-та вектора

        vector<int>::iterator i  = my_vector.begin() - с чего начать
        i!=my_vector.end() - чем закончить
        i++ - как идти
        */
        cout<<*i<<endl;
    }

    // идти с конца вектора в начало
    cout << "reversecycle for" << endl;
    for (vector<int>::reverse_iterator i = my_vector.rbegin(); i != my_vector.rend(); i++)
    {
        cout << *i << endl;
    }
    

    // cout<<*(it+3)<<endl; // так работает не всегда, для этого используют advance()
    advance(it, 1); // чтобы перейти в конкретному элементу
    cout << "advance(it, 1): " << *it << endl;




    cout << "======= insert and erase =======" << endl;

    vector<int> my_vector2 = {64, 656, 342, 54, 5};
    for (vector<int>::iterator i = my_vector2.begin(); i != my_vector2.end(); i++)
    {
        cout << *i << endl;
    }
    cout<<"insert"<<endl;
    vector<int>::iterator it2 = my_vector2.begin(); // вставиться под нулей индекс
    advance(it2, 3); // вставиться под третий индекс
    my_vector2.insert(it2, 777);

    for (vector<int>::iterator i = my_vector2.begin(); i != my_vector2.end(); i++)
    {
        cout << *i << endl;
    }

    cout << "erase" << endl;
    vector<int>::iterator it_erase = my_vector2.begin(); // удаляет нулевой эл-т вектора
    // advance(it_erase, 2); // удаляет второй индекс
    my_vector2.erase(it_erase);
    my_vector2.erase(it_erase, it_erase + 3); // удалить диапозон элементов

    for (vector<int>::iterator i = my_vector2.begin(); i != my_vector2.end(); i++)
    {
        cout << *i << endl;
    }
}

int main()
{
    // vec_fun();
    iter_vec();
    return 0;
}