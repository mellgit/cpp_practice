#include <iostream>
#include <string>
using namespace std;

void friend_function();
void methods_out_class();
void friend_methods_class();
void friend_class();


int main()
{
    // friend_function();
    // methods_out_class();
    // friend_methods_class();
    friend_class();
    return 0;

}

class Apple2;
class Human2;


class Human2
{
public:
    void take_apple(Apple2 &apple);
};

class Apple2
{
private:
    int weight;
    string color;

public:
    Apple2(int weight, string color)
    {
        this->color = color;
        this->weight = weight;
    }

    friend Human2; // дружественный класс - нарушает принцип инкапсудяции (быть аккуратнее)


};

void Human2::take_apple(Apple2 &apple)
{
    /*
    дружественный метод класса
    тоже самое что и дружественные функции, только реализованные из класса
    */
    cout << "take apple " << apple.weight << " " << apple.color << endl;
}
void friend_class()
{
    Apple2 apple(123, "green");
    Human2 human;
    human.take_apple(apple);
}

class Apple;
class Human;


class Human
{
public:
    void take_apple(Apple &apple);
    
};


class Apple
{
private:
    int weight;
    string color;
public:
    Apple(int weight, string color)
    {
        this->color = color;
        this->weight = weight;
    }

    friend void Human::take_apple(Apple &apple);
};

void Human::take_apple(Apple &apple)
{
    /*
    дружественный метод класса
    тоже самое что и дружественные функции, только реализованные из класса
    */
    cout << "take apple " << apple.weight << " " << apple.color << endl;

}
void friend_methods_class()
{
    Apple apple(123, "green");
    Human human;
    human.take_apple(apple);
    

}


class My_class
{
private:
    /* data */
public:

    void print();
};


void My_class::print()
{
    /*
    орпеделение методов вне класс
    */
    cout<<"hello"<<endl;
}

void methods_out_class()
{
    My_class a;
    a.print();

}


class Point
{
private:
    int x;
    int y;
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout<<"constructor "<<this<<endl;
    }
    ~Point()
    {

    }

    void print()
    {
        
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    friend void change_y(Point &value);

};

void change_y(Point &value)
{
    /*
    дружественная фу-я - ф-я вне класса
    имеет доступ в private (а также protected) полям, тк класс ей дает доступ
    указатель this в ней не работает, можно работать только через передаваемый объект класса
    она также может быть дружественной для нескольких классов

    */
    value.y *=(-1);
}

void friend_function()
{
    Point a(1,3);
    a.print();
    change_y(a);
    cout<<"call change y"<<endl;
    a.print();
}