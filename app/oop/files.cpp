#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void of_file();
void if_file();

int main()
{
    // fstream - общая либа
    // ifstream - чтение файла
    // ofstrem - запись в файл

    // of_file();
    if_file();

    return 0;
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