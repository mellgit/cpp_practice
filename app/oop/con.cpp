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
    Point()
    {
        x = 0;
        y = 0;
        // cout<<this<<" construstor"<<endl;
    }
    Point(int value_x, int value_y)
    {
        x = value_x;
        y = value_y;
    }
    
    ~Point()
    {

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

    Point & operator +(const Point & other)
    {
        Point temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        
        return temp;
    }
    

    Point & operator ++()
    {
        /*
        префикс
        */
        this->x++;
        this->y++;

        return *this;

    }

    Point &operator++(int value)
    {
        /*
        постфикс
        int value только для того, чтобы компилятор отличал от префикс
        нигде его передавать не нужно
        */
        Point temp(*this);
        this->x++;
        this->y++;

        return temp;
    }

    int get_x()
    {
        return this->x;
    }
    int get_y()
    {
        return this->y;
    }
};


void point_function()
{
    cout<<"============== BEGIN =============="<<endl;
    Point a(3, 2);
    Point b(4, 2);
    cout << "a: " <<a.get_x() << " " << a.get_y() << endl;
    cout << "b: " << b.get_x() << " " << b.get_y() << endl;

    bool result1 = a == b;
    bool result2 = a != b;
    cout << "result1.1: " << result1 << endl;
    cout << "result1.2: " << result2 << endl;

    Point result = a + b;
    cout<<"result2: "<<result.get_x()<<" "<<result.get_y()<<endl;


    Point c(1,1);
    cout << "c: " << c.get_x() << " " << c.get_y() << endl;
    Point d = ++c;
    cout << "result3.1: " << d.get_x() << " " << d.get_y() << endl;
    
    
    
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