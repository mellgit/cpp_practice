#include <iostream>
using namespace std;

void str_fun();
void ascii_fun();

int main(){
    // str_fun();
    ascii_fun();

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