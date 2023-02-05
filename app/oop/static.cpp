#include <iostream>
#include <string>
using namespace std;

void static_method();

int main()
{
    static_method();
    return 0;
}


class Apple
{
private:
    int weight;
    string color;
    int id;

public:

    static int count; // статическая переменная - для всех объектов класса одинаковая 

    Apple(int weight, string color)
    {
        this->color = color;
        this->weight = weight;
        count++;
        id = count;
    }

    int get_id()
    {
        return id;
    }
    

};

int Apple::count = 0;

void static_method()
{
    Apple apple(123, "green");
    Apple apple2(123, "red");
    Apple apple3(123, "yellow");
    

    cout<<"counter: "<<Apple::count<<endl; // вывод значения статического экземпляра класса

    cout<<"id"<<endl;
    cout << apple.get_id() << endl;
    cout << apple2.get_id() << endl;
    cout << apple3.get_id() << endl;
}