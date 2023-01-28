#include <iostream>
#include <string>
using namespace std; 


class Human
{
public:
    int age;
    string name;

    void show_info(){
        cout<<name<<" "<<age<<endl;
    }
};

void my_class()
{
    /*создание объектов класса*/
    Human first_human;
    cout << "first human" << endl;
    first_human.age = 23;
    first_human.name = "bob";
    cout << first_human.age << endl;
    cout << first_human.name << endl;

    cout << "_________________" << endl;

    Human second_human;
    cout << "second human" << endl;
    second_human.age = 53;
    second_human.name = "alice";
    cout << second_human.age << endl;
    cout << second_human.name << endl;
    cout << "_________________" << endl;

    /*вызов методов класса*/
    first_human.show_info();
    second_human.show_info();
}

int main()
{
    my_class();    

    return 0;
}


