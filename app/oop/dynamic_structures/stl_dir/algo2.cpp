#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
    remove_fun();
    return 0;
}