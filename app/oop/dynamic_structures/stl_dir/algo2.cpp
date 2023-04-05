#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric> // для accumulate
using namespace std;


class Person
{
public:
    string name;
    int score;

    Person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    bool operator()(const Person &p)
    {
        return p.score >180;
    }
};

class Point
{
public:
    int x; 
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

void equal_predicate()
{

    vector<Point> arr = {
        Point(1,4),
        Point(13,42),
        Point(41,54),
    };

    vector<Point> arr2 = {
        Point(1,4),
        Point(13,42),
        Point(41,54),
    };

    bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2), [](const Point &p1, const Point &p2)
    {
        /*
        предикат вместо перегрузки оператора сравнения
        если наборы будут одинаковые, но последовательноть разная, необходимо сначала отсортировать наборы
        */
        bool result = p1.x == p2.x && p1.y == p2.y;

        return result;
    });

    cout<<result<<endl;

}

void equal_mismatch()
{
    /*
    equal и mismatch - cравнение массивов
    
    equal - равенство наборов, возвращает bool
    equal(begin(первого_набора), end(первого_набора), begin(второго_набора), end(второго_набора));
    сравнивать можно разные наборы(list сравнить c vector и тп)
    сравнивает по индексам каждого набора(arr[0] == arr2[0] => True)

    mismatch - указывает на различие между наборами
    */
    cout<<" === max arr === "<<endl;
    const int size = 7;
    int arr[size] = {4,325,726,2,-995,2338,-5};
    int arr2[size] = {4,325,726,2,-995,2338,-5};

    auto result = equal(begin(arr), end(arr), begin(arr2), end(arr2));

    cout<<result<<endl;


}



void accumulate_fun()
{
    /*
    accumulate - сумма всех элементов набора
    accumulate(начало_набора, конец_набора, к_чему_начать_прибавлять);

    вместо v.begin(), v.end() можно использовать глобальные ф-и begin(v), end(v)
    
    next() - переключает на следующий элемент набора
    */
    cout<<" === sum vector === "<<endl;
    vector<int> v = {1,2,3,4};

    auto result = accumulate(begin(v), end(v), 0);

    cout<<result<<endl;

    cout<<" === mul vector === "<<endl;
    vector<int> v2 = {1,2,3,4};

    auto result2 = accumulate(begin(v2), end(v2), 1, [](int a, int b)
    {
        return a*b;
    });

    cout<<result2<<endl;
}


void min_elem_fun()
{
    /*
    min_element - поиск минимального элемента
    minmax_element - поиск минимального и максимального элемента, возвращается набор (first-min, second-max)
    */
    cout<<" === max vector === "<<endl;
    vector<int> v = {34,5,76,234,45,98,5};

    auto result = min_element(v.begin(), v.end());
    auto result1 = minmax_element(v.begin(), v.end());
    cout<<"minmax: "<<*result1.first<<"\t"<<*result1.second<<endl;

    cout<<*result<<endl;

    cout<<" === max list === "<<endl;
    list<int> lst = {4,325,726,2,-45,938,-5};

    auto result2 = min_element(lst.begin(), lst.end());

    cout<<*result2<<endl;

    cout<<" === max arr === "<<endl;
    const int size = 7;
    int arr[size] = {4,325,726,2,-995,2338,-5};

    auto result3 = min_element(arr, arr+size);

    cout<<*result3<<endl;
}


void max_elem_fun()
{
    /*
    max_element - поиск максимального элемента
    */
    cout<<" === max vector === "<<endl;
    vector<int> v = {34,5,76,234,45,98,5};

    auto result = max_element(v.begin(), v.end());

    cout<<*result<<endl;

    cout<<" === max list === "<<endl;
    list<int> lst = {4,325,726,2,-45,938,-5};

    auto result2 = max_element(lst.begin(), lst.end());

    cout<<*result2<<endl;

    cout<<" === max arr === "<<endl;
    const int size = 7;
    int arr[size] = {4,325,726,2,-45,2338,-5};

    auto result3 = max_element(arr, arr+size);

    cout<<*result3<<endl;
}

void remove_fun()
{
    /*
    remove, remove_if 
    remove не удаляет элемент набора, а просто переносит его в конец набора, 
    а все что не удалилось, остается в начале набора
    между ними появляется итератор, играет роль разделителя
    после разделителя, из набора необходимо удалиться срез
    начиная от полученного итератора, до конца набора
    */

    vector<int> v = {34,5,76,234,45,98,5};


    cout<<" === remove === "<<endl;
    auto result = remove(v.begin(), v.end(),5);
    v.erase(result, v.end());

    for (auto elem : v)
    {
        cout<<elem<<endl;
    }



    vector<Person> person{
        Person("bob", 232),
        Person("alice", 32),
        Person("john", 22),
        Person("bob", 126),
        Person("mike", 172),
    };
    cout<<" === remove_if === "<<endl;

    auto result2 = remove_if(person.begin(), person.end(),[](const Person &p)
    {
        // удалить всех персон, у которых счет меньше 150
        return p.score < 150;
    });
    person.erase(result2, person.end());

    for (auto elem : person)
    {
        cout<<"name: "<<elem.name<<"\tscore: "<<elem.score<<endl;
    }

    
}

int main()
{
    // remove_fun();
    // max_elem_fun();
    // min_elem_fun();
    // accumulate_fun();
    // equal_mismatch();
    equal_predicate();
    return 0;
}