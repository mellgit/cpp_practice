#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void try_catch_function();

int main()
{
    try_catch_function();
}

void try_catch_function()
{
    ifstream fin;
    // string path = "data/try_catch.txt";

    // для вызова исключения 
    string path = "data/try_catch.xt"; 

    // обработка исключений для класса ifstream
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "try open file" << endl;
        fin.open(path);
        cout << "file is open" << endl;
    }
    // exception - базовый класс ошибок
    // catch(const std::exception& exp)

    // класс ошибок для ifstream
    catch (const ifstream::failure &exp)
    {
        cout<<"error"<<endl;
        cout << exp.what() << endl; // конкретика ошибки
        cout<<exp.code()<<endl; // код ошибки
    }
    

}