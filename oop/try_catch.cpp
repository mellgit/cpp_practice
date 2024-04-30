#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void try_catch_function();
void throw_function();
void more_try();
void custom_exception_class();

int main()
{
    // try_catch_function();
    // throw_function();
    // more_try();
    custom_exception_class();
    return 0; 
}

class MyException : public exception
{
private:
    int data_state;
public:
    MyException(char *msg, int data_state) 
    {
        this->data_state = data_state;
    }
    int get_data_state()
    {
        return data_state;
    }
};


void foo_3(int value)
{
    if (value < 0)
    {
        throw runtime_error("value < 0");
    }
    if (value == 1)
    {
        throw MyException("value == 1", value);
    }


    cout << "value = " << value << endl;
}


void custom_exception_class()
{
    try
    {
        foo_3(55);
        // foo_3(-55); // exception
        foo_3(1); // exception
    }
    catch (MyException &exp)
    {
        /*
        всегда сначала отлавливают конкретные исключения (MyException)
        а уже потом общие (exception)
        */
        cout << "throw: " << exp.what() << endl; 
        cout<<"state: "<<exp.get_data_state()<<endl;
        
    }
}



void foo_2(int value)
{
    // несколько исключений
    if (value < 0)
    {
        throw "value < 0";
    }
    if (value==0)
    {
        throw runtime_error("value == 0");
    }
    if (value==1)
    {
        throw 1;
    }
    
    cout << "value = " << value << endl;
}

void more_try()
{
    try
    {
        foo_2(55);
        // foo_2 (-55); // exception
        // foo_2(0);  // exception
        foo_2(1); // exception
    }
    /*
    отработка нескольких блоков catch, тк ошибка мб разной
    данным способом можно отловить как можно больше исключений
    */
    catch (const char *exp)
    {
        cout <<"first catch: "<<exp << endl;
    }
    catch (const exception &exp)
    {
        cout << "second catch: " << exp.what() << endl;
    }
    catch (...)
    {
        /*
        таким способом можно отловить любое исключение
        но без понимания того, что в нем
        такое исключение должно быть в самом конце
        тк оно перехватывает все исключения и на то(catch), что находится ниже ее
        реагировать не будет и выпадет ошибка
        */
        cout<<"something wrong"<<endl;
    }
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