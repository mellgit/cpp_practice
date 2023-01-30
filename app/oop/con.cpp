#include <iostream>
using namespace std;

void my_function();
void point_function();



int main()
{
    // my_function();    
    point_function();
    return 0;
}


class Point
{
private:
    int x;
    int y;
public:
    Point(int value_x, int value_y)
    {
        x = value_x;
        y = value_y;
    }

    bool operator ==(const Point & other)
    {
        /*
        Перегрузка оператора равенства == и не равно !=.
        если необходимо сравнить два объекта класса на равенство

        задача: сравнить координаты двух точек,
        если равны return true, иначе false
        */
        if (this->x == other.x && this->y == other.y)
        {
            return true;
        }
        else
        {
            return false;
        }

        // return this->x == other.x && this->y == other.y; // короткая запись
    }
    bool operator !=(const Point & other)
    {
        return !(this->x == other.x && this->y == other.y); // короткая запись
    }
    ~Point()
    {

    }
};


void point_function()
{
    Point a(3, 2);
    Point b(4, 2);

    bool result1 = a == b;
    bool result2 = a != b;
    cout << result1 << endl;
    cout << result2 << endl;
}


class My_class
{
private:
    int old_size;
public:
    int *data;

    My_class(int size)
    {
        this->old_size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
        
        cout << "constructor - " << this << endl;
        
    }

    My_class(const My_class &other)
    {
        /*
        конструктор копирования
        при передаче динамического объекта класса My_class в другой динамического объект класса My_class
        может возникнуть ошибка при копировании, тк указатели указывают на одну и туже ячейку памяти
        что бы этого избежать необходимо описать копирующий конструктор, в котором выделется 
        новая память под новый дин объект и в который перезапишутся данных из первого дин объекта
        таким образом два указателя на двух дин объектах будут указывать на разные ячейки памяти
        и ошибки с "двойным" удалением одной и той же ячейки памяти, можно избежать
        */
        this->old_size = other.old_size; 
        this->data = new int[other.old_size];
        cout << "call copy constructor - " << this << endl;

        for (int i = 0; i < other.old_size; i++)
        {
            this->data[i] = other.data[i];
        }

        /*
        result
        constructor - 0x16fb877f0
        call copy constructor - 0x16fb877e0
        destructor - 0x16fb877e0
        destructor - 0x16fb877f0
        */
    }

    My_class &  operator=(const My_class &other)
    {
        /*
        перегрузка оператора присваивания
        */
        cout << "call operator \'=\' - " << this << endl;
        this->old_size = other.old_size;
        if (this->data!=nullptr)
            delete[] this->data;

        for (int i = 0; i < other.old_size; i++)
        {
            this->data[i] = other.data[i];
        }
        return *this; 
    }
    ~My_class()
    {
        cout << "destructor - " << this << endl;
        delete[] data;
    }

};

void foo(My_class value)
{
    cout<<"call foo function"<<endl;
    
    
}

My_class foo2()
{
    cout<<"call foo2 function"<<endl;
    My_class temp(2);
    return temp;

}

void my_function()
{
    My_class a(5);
    My_class b(4);
    My_class c(3);
    c=a=b;
    // foo(a);
    // foo2();

}