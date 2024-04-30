#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void of_file();
void if_file();
void write_obj_to_file();
void fstream_file();
void stream_io();

int main()
{
    // fstream - общая либа
    // ifstream - чтение файла
    // ofstrem - запись в файл

    // of_file();
    // if_file();
    // write_obj_to_file();
    // fstream_file();
    stream_io();

    return 0;
}


class PointNew
{
// private:
//     int x;
//     int y;
//     int z;

public:

    int x;
    int y;
    int z;

    PointNew()
    {
        x=y=z=0;
    }
    PointNew(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    
    
};


ostream& operator<<(ostream& os, const PointNew& point)
{
    /*
    перезгрузка оператора <<
    перегружать необходимо вне класса, тк ostream не пренадлежит нашему классу PointNew
    данная перегрузка позволяет выводить объект класса как в файл, так и в консоль
    */

    os << point.x<<" "<<point.y<<" "<<point.z<<endl;
    return os;
}

// istream& operator>>(istream& is, const PointNew& point)
// {
//     /*
//     перезгрузка оператора >>
    
//     */

//     is >> point.x >>point.y>>point.z;
//     return is;

// }

void stream_io()
{
    string path = "data/io_file.txt";
    fstream fs;

    PointNew point_new(1,343,62);

    // cout<<point_new;

    fs.open(path, fstream::in | fstream::out | fstream::app); // чтение и запись

    if (!fs.is_open())
        cout << "error open file" << endl;
    else
    {
        cout << "file open" << endl;
        // fs<<point_new<<endl; // запись объекта в файл

        /*
        снова ошибка при чтение из файла
        отсутствует оператор ">>", соответствующий этим операндамC/C++
        error: invalid operands to binary expression ('std::istream' (aka 'basic_istream<char>') and 'const int')
        возможно дело в архитектуре процессора, тк не хватает определенных библиотек        
        */
        // PointNew p;
        // fs>>p;

        
    }

}





void fstream_file()
{
    string path = "data/new_file.txt";
    fstream fs;

    // fstream::in параметр открытия файла на чтение
    // | - побитовое или
    // fstream::out - параметр открытия файла на запись
    // fstream::app - для добавляния в файл 
    fs.open(path, fstream::in | fstream::out | fstream::app); // чтение и запись

    if (!fs.is_open())
        cout << "error open file" << endl;
    else
    {
        cout << "file open" << endl;
        
        int value;
        string msg;

        cout << "enter 1 write file" << endl;
        cout << "enter 2 read file" << endl;
        cin>>value;

        if (value==1)
        {
            cout<<"enter msg: ";
            cin>>msg;
            fs<<msg<<"\n";

        }
        if (value==2)
        {
            cout<<"read file"<<endl;            

            // чтение из файла не работает
            // while (!fs.eof())
            // {
            //     msg = "";
            //     fs>>msg;
            //     cout<<msg<<endl;
            // }
            /*
            Стоит отметить, что при компиляции через g++ следует использовать флаг -static,
            если программа работает со файлами и использует типы из заголовочного файла fstream:
            g++ app.cpp -o app -static

            так же имеется ошибка с испоьзованием библиотек
            library not found for -lcrt0.o
            на других unix таких траблов нет

            */
        }
        
        
    }

    fs.close();
}



class Point
{
public:
    int x;
    int y;
    int z;

    Point()
    {
        x=y=z=0;

    }

    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print()
    {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
};


void write_obj_to_file()
{

    Point point(14,23,46);
    point.print();

    string path = "data/obj.txt";
    ofstream fout;
    fout.open(path, ofstream::app);

    if (!fout.is_open())
        cout<<"error open file"<<endl;
    else
    {
        cout<<"file open"<<endl;

        /*
        запись объекта в файл
        (char*)*point - преобразование к типу char, через ссылку на объект
        sizeof(Point) - сколько памяти будет занимать 
        */
        fout.write((char*)&point, sizeof(Point));
    }

    fout.close();


    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
        cout<<"error open file"<<endl;
    else
    {
        cout<<"file open"<<endl;
        Point pnt;
        while (fin.read((char *)&pnt, sizeof(Point))) // bool value
        {
            pnt.print();
        }
        
        
    }

    fin.close();


}


void if_file()
{
    string path_to_file = "data/my_file.txt";

    ifstream fin;
    fin.open(path_to_file);

    if (!fin.is_open())
        cout<<"error open file"<<endl;
    else
        cout<<"--- file is open ---"<<endl;
    

    
    // char ch;
    // fin.get(ch) - посимвольной считывание
    // если считать получилось - return true -> else return false
    // поэтому данный метод можно положить в цикл while
    // while (fin.get(ch))
    // {
    //     cout<<ch;
    // }

    
    string str;
    // fin.eof() - чтение до конца файла
    while (!fin.eof())
    {
        // fin >> str; // c getline работать удобнее
        getline(fin, str); // построчная запись
        cout<<str<<endl;
    }

    cout<<endl;
    fin.close(); 
}


 
void of_file()
{
    string path_to_file = "data/my_file.txt";

    ofstream fout; // объект класс fstream

    // fout.open(path_to_file); // открытие файла и перезапись всего лежащего в нем
    fout.open(path_to_file, ofstream::app); // открытие файла для добавление к существующему

    if (!fout.is_open()) // если файл не удалось открыть
        cout<<"error open file"<<endl;
    else
        // fout << "\nthis our new data"; // запись данных в файл

        // запись значения в файл из консоли
        cout<<"enter value: ";
        string value;
        getline(cin, value);
        fout<<endl<<value;

    fout.close(); //закрытие файла
}