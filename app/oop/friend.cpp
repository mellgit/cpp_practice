#include <iostream>
using namespace std;

void friend_function();
void methods_out_class();

int main()
{
    // friend_function();
    methods_out_class();
    return 0;

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