#include <iostream>
#include <string>
using namespace std;

void str_fun();
void ascii_fun();
void pointer_to_string();
void len_string(char *str);
void pointer_to_function();


int main(){
    // str_fun();
    // ascii_fun();
    // pointer_to_string();

    // char *str = "hello world!";
    // len_string(str);

    pointer_to_function();


    return 0;
}

string data_db(){
    return "data from db";
}

string data_server()
{
    return "data from server";
}

void show_any_data(string (*any_function)()){
    /*
    в функцию show_any_data можно передать любую функцию типа строка и не имеющих параметров
    тк функций data_db и data_server мб много и бля них всех придется описывать функционал,
    а таким способом show_any_data играет роль шаблонизатора для всех функций
    */
    cout<<any_function()<<endl;
}

void pointer_to_function(){
    /*
    передача параметра в функцию в качестве указателя на функцию
    или в параметр функции передать другую функцию 
    */
    // int(*my_pointer)(int a); // тип возвращаемого значение (*имя указателя)(передаваемые параметры)

    show_any_data(data_db);
    show_any_data(data_server);
}

void len_string(char *str){
    /*
    подсчет количества символов с строке
    */

    cout << "strlen = " << strlen(str) << endl;

    int count = 0;
    while (str[count] != '\0'){
        count++;
    }
    
    cout<<"len = "<<count<<endl;
    
}

void pointer_to_string(){
    /*
    указатели на строчки
    */
    // char *my_str = "hello world"; // warning
    char my_str[] = "hello world";
    cout<<my_str<<endl; 

}

void ascii_fun(){
    /*
    преобразование типов
    в таблице ascii от 0 до 127 символы всегда одинаковые, после уже в разнобой для национальной кодировки
    */

    setlocale(LC_ALL, "ru");

    for (int i=0; i<250; i++){
        cout<<"code = "<<i<<"\t"<<"char = "<<(char)i<<endl;
    }
}

void str_fun(){

    char value = 'f'; // символы только в одинарных ковычках
    cout<<value<<endl;

    // массив символов только в двойных ковычках
    // размерность можно указывать и не указывать
    char my_str[13] = "hello world!"; // сколько символов, такой и размер символьного массива
    cout << my_str << endl;
    char my_str2[] = "hello world!"; 
    cout << my_str2 << endl;
    cout << my_str2[1] << endl; // строки также имеют индексы

    // char my_str3[] = {'h','e','l','l','o'}; // ошибка, тк нужен терминирующий ноль \0
    char my_str3[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // как то работает в обоих случаях
    cout << my_str3 << endl;

    // длинна каждого символьного массива
    cout << strlen(my_str) << endl;
    cout << strlen(my_str2) << endl;
    cout << strlen(my_str3) << endl;
}