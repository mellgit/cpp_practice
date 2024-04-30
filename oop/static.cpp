#include <iostream>
#include <string>
using namespace std;

void static_method();
void inner_class();
void class_array_obj();
void aggregation_and_composition();


int main()
{
    // static_method();
    // inner_class();
    // class_array_obj();
    aggregation_and_composition();
    return 0;
}


class Cap
{
    /*
    агрегация - когда один класс используется в другом, но используются по разному
    и данный класс является независимым
    класс Cap можно использовать и в других классах
    а класс Brain только в классе Human
    */
private:
    string color = "red";
public:
    string get_color()
    {
        return color;
    }
};


class Human
{
    /*
    пример композиции - когда один объект жестко привязан к другому
    Brain привязан к Human
    */
private:

    class Brain
    {
    public:
        void think()
        {
            /*
            данный метод называется делегированным
            тк think вызывает think
            */
            cout<<"I think"<<endl;
        }
    };
    Brain brain;
    Cap cap; 

public:
    void think()
    {
        brain.think();
    }

    void inspect_cap()
    {
        cout<<"color cap: "<<cap.get_color()<<endl;
    }
};

void aggregation_and_composition()
{
    Human human;
    human.think();
    human.inspect_cap();
    

}




class Pixel
{
private:
    int r;
    int g;
    int b;

public:

    // конструктор по умолчанию
    Pixel()
    {
        r = g = b = 0;
    }
    Pixel(int r, int g, int b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    string get_info()
    {
        return "Pixe: r=" + to_string(r) + " g=" + to_string(g) + " b=" + to_string(b);
    }
};


void class_array_obj()
{

    const int len = 5;
    // массив типа Pixel
    Pixel arr[len];
    cout << arr[0].get_info() << endl; // Pixe: r=0 g=0 b=0

    arr[0] = Pixel(43,54,2);
    cout << arr[0].get_info() << endl; // Pixe: r=43 g=54 b=2

    // заполненный статический массив типа Pixel
    Pixel arr2[len] = {
        Pixel(0, 4, 5),
        Pixel(6, 45, 34),
        Pixel(70, 54, 45),
        Pixel(20, 45, 5),
        Pixel(50, 64, 75)
    };
    cout << "from static array" << endl;
    for (int i = 0; i < len; i++)
    {
        cout<<arr2[i].get_info()<<endl;
    }

    cout << "from dynamic array" << endl;
    // динамический массив типа Pixel
    Pixel *arr3 = new Pixel[len];
    cout << arr3[0].get_info() << endl; // Pixe: r=0 g=0 b=0

    arr3[0] = Pixel(433, 544, 52);
    cout << arr3[0].get_info() << endl; // Pixe: r=433 g=544 b=52

    delete [] arr3;
    arr3 = nullptr;
    
}






class Image
{
private:
    class Pixel
    {
        /*
        внутренний класс
        его так же можно использовать в public секции
        для определенных задач
        */
    private:
        int r;
        int g;
        int b;
    public:
        Pixel(int r, int g, int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        string get_info()
        {
            return "Pixe: r="+to_string(r)+" g="+to_string(g)+" b="+to_string(b);
        }
    };

    static const int len = 5;
    Pixel pixels[len] = {
        Pixel(0, 4, 5),
        Pixel(6, 45, 34),
        Pixel(70, 54, 45),
        Pixel(20, 45, 5),
        Pixel(50, 64, 75)};

public:
    void get_image_info()
    {
        for (int i = 0; i < len; i++)
        {
            cout << i << " - " << pixels[i].get_info() << endl;
        }
        
    }
};


void inner_class()
{
    Image img;
    img.get_image_info();
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