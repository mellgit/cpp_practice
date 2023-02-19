#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void try_catch_function();
void throw_function();


int main()
{
    // try_catch_function();
    throw_function();
    return 0; 
}

void foo(int value)
{
    if (value<0)
    {
        // throw "value < 0";

        // вместе exception необходимо использовать runtime_error
        throw runtime_error("value < 0");
    }

    cout<<"value = "<<value<<endl;
}

void throw_function()
{

    try
    {
        foo(55);
        foo(-55); // exception 
        
    }
    // catch(const char *exp) // исключение на строчку
    catch (const exception &exp)
    {
        /*
        что в throw бросают, то и ловит catch
        */
       cout<<exp.what()<<endl; 

        // исключение на строчку
        // cout << "throw " << exp << '\n';
    }
    

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