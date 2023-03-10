#include <iostream>
#include <string>
using namespace std;

void delegating_constructors();
void virtual_method();
void multiple_inheritance();

int main()
{
    // delegating_constructors();
    // virtual_method();
    multiple_inheritance();
    return 0;
}

class Car
{
public:
    Car()
    {
        cout << "call constructor Car" << endl;
    }

    ~Car()
    {
        cout << "call destructor Car" << endl;
    }

    void drive()
    {
        cout<<"drive"<<endl;
    }

    void use()
    {
        cout<<"use Car"<<endl;
    }
};

class Airplane
{
public:
    Airplane()
    {
        cout << "call constructor Airplane" << endl;
    }

    ~Airplane()
    {
        cout << "call destructor Airplane" << endl;
    }
    void fly()
    {
        cout << "fly" << endl;
    }
    void use()
    {
        cout << "use Airplane" << endl;
    }
};

class FlyingCar : public Car, public Airplane
{
    /*
    множественное наследование
    настледуются все методы и поля
    наследовать можно сколь угодно классов
    */
   /*
   порядок вызова конструкторов так же может менятся, в зависимости 
   от того, в каком порядке было вызванно наследование в класса FlyingCar
   */
public:
    FlyingCar()
    {
        cout << "call constructor FlyingCar" << endl;
    }
    ~FlyingCar()
    {
        cout << "call destructor FlyingCar" << endl;
    }
};

void multiple_inheritance()
{
    /*
    вызов конструкторов и деструкторов сохранился
    первый вызван последний закрылся
    */
    FlyingCar fc;
    fc.drive();
    fc.fly();
    cout<<endl<<endl;

    /*
    приведение к типу
    два родятеля имеют два одинаковых метода use
    компилятор не знает какой именно необходимо использовать
    для этого нужно использовать приведение к типу 
    при помощи круглых скобок (())
    */
    ((Car)fc).use();
    ((Airplane)fc).use();
    
    cout<<endl<<endl;
}

class Msg
{
private:
    string msg;
public:
    Msg(string msg)
    {
        this->msg = msg;
    }

    virtual string get_msg()
    {
        return msg;
    }
};

class BraketsMsg : public Msg
{
public:
    BraketsMsg(string msg):Msg(msg)
    {

    }
    string get_msg() override
    {
        /*
        return "["+get_msg()+"]";
        таким образом вызявается дочерний метод get_msg
        те выполнение получается рекурсивный
        чтобы этого избежать необходимо использовать метода
        родителя через двойное двоиточие  
        */

        return "[" + ::Msg::get_msg() + "]";
    }
};

class Printer
{
public:
    void print(Msg *msg)
    {
        cout<<msg->get_msg()<<endl; 
    }
};

void virtual_method()
{
    // Msg m("hello");
    BraketsMsg m("hello");

    Printer p;
    p.print(&m);
}

class Human
{
public:
    string name;
    int age;
    int weight;

    Human(string name)
    {
        this->name = name;
        this->age = 0;
        this->weight = 0;
    }
    Human(string name, int age):Human(name)
    {
        this->age = age;   
    }
    Human(string name, int age, int weight):Human(name, age)
    {
        this->weight = weight;;
    }

    void print()
    {
        cout<<name<<" "<<age<<" "<<weight<<endl;
    }
};

void delegating_constructors()
{
    /*
    суть делегирующего конструктора заключается в наследовании конструктора
    в конструкторе 2, через двоеточие, можно использовать знычение полученное из 1-го конструктора
    данный подход позволят использовать меньше кода и правок становится меньше
    */
    Human human1("bob");
    Human human2("bob", 33);
    Human human3("bob", 33, 67);

    human1.print();
    human2.print();
    human3.print();
}