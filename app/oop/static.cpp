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
    static int count; // статическая переменная - для всех объектов класса одинаковая

public:

    

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
    string get_color()
    {
        return color;
    }

    static int get_count()
    {
        /*
        статический геттер метод, дабы защитить экземпляр count
        this указатель работать не может, тк это указатель для конкретного объекта класса
        а static относится сразу ко всем объектам
        */
        return count;
    }

    static void change_color(Apple &apple, string color)
    {
        /*
        чтобы статический метод работал с конкретным объектом класса
        в параметры статического метода необходимо передать, ссылку на объект
        */
        apple.color = color;
    }
    

};

int Apple::count = 0;

void static_method()
{
    Apple apple(123, "green");
    Apple apple2(123, "red");
    Apple apple3(123, "yellow");

    // вывод значения статического экземпляра класса
    // если counter был бы в public секции
    // cout<<"counter: "<<Apple::count<<endl;

    cout<<Apple::get_count()<<endl;
    cout<<"id"<<endl;
    cout << apple.get_id() << endl;
    cout << apple2.get_id() << endl;
    cout << apple3.get_id() << endl;

    cout << "befor change: " << apple.get_color() << endl;
    Apple::change_color(apple, "blue");
    cout << "after change: " << apple.get_color() << endl;
}