/*
Напишите функцию RemoveExclamationMarks, которая удаляет все восклицательные знаки из заданной строки.
*/

#include <iostream>
#include <string>
using namespace std;



string removeExclamationMarks(string str)
{
    /*
    идиома erase-remove
    обьяснение: remove смещает элементы не равные '!' в начало строки 
    в том же порядке в каком они были изначально, 
    потом возвращает итератор на первый элемент равный '!' 
    (эти элементы лежат в хвосте строки), 
    и затем erase затирает ненужные элементы от начала этого итератора и до конца
    */

    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    return str;
}


int main()
{
    string my_str = "Hello! World!!";
    
    cout<<removeExclamationMarks(my_str)<<endl;

    return 0;

}