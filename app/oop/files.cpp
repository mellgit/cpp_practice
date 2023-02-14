#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void of_file();
void if_file();
void write_obj_to_file();

int main()
{
    // fstream - общая либа
    // ifstream - чтение файла
    // ofstrem - запись в файл

    // of_file();
    // if_file();
    write_obj_to_file();

    return 0;
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