#include <iostream>
#include <string>
using namespace std; 

void my_class();
void point_function();
void point2_function();



int main()
{
    // my_class();    
    // point_function();
    point2_function();

    return 0;
}

class Point2
{
private:
    int x; 
public:
    Point2()
    {
        x = 0;
    }

    Point2(int value_x)
    {
        x = value_x;
    }
    void show_info()
    {
        cout << "x = " << x << endl;
    }
};

void point2_function()
{
    /* перезгузка конструторов
    тоже самое что и перегрузка функций
    */
    Point2 a;
    a.show_info();

    Point2 b(34);
    b.show_info();
}



class Point
{
    /*
    геттеры и сеттеры - взять и установить значения для private полей
    */
private:
    int x;

    bool check_value()
    {
        return true?x>0:false;
    }
public:

    Point(int value_x)
    {
        // конструктор может быть только в public секциипше 
        x = value_x;
    }

    void start()
    {
        /* вызов приватногоо метода на проверку значения
        при помощи тернарного оператора
        */
        // if (check_value())
        //     cout<<"x > 0"<<endl;
        // else
        //     cout<<"x < 0"<<endl;
        check_value() ? cout << "x > 0" << endl : cout << "x < 0" << endl;
    }

    int get_x()
    {
        return x;
    }
    void set_x(int value_x)
    {
        x = value_x;
    }
    void show_info()
    {
        cout << "x = " << x << endl;
    }
};

void point_function()
{
    // без конструктора
    // Point a;
    // a.set_x(123);
    // a.show_info();
    // cout << a.get_x() << endl;

    // cout<<"__________"<<endl;
    // a.start();

    // с конструктором
    Point a(34);
    a.show_info();
}

class Human
{
public:
    int age;
    string name;

    void show_info()
    {
        cout << name << " " << age << endl;
    }
    void show_private()
    {
        cout << "bank = " << bank_count << endl;
    }

    /* модификаторы доступа
    private - доступен только внутри класса
    public - доступен всем
    */
private:
    int bank_count = 20;
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

    first_human.show_private();
    second_human.show_private();
}