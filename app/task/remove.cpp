/*
Напишите функцию RemoveExclamationMarks, которая удаляет все восклицательные знаки из заданной строки.
*/

#include <iostream>
#include <string>
using namespace std;



string removeExclamationMarks(string str)
{

    char count = '\0';
    int i = 0;
    char new_str[30]={};
    cout<<str<<endl;
    while (str[i]!=count)
    {
        if (str[i]!='!'){
            cout<<str[i]<<endl;
            new_str[i] = str[i];
        }
        cout<<str[i]<<endl;
        
        i++;
    }

    int size = strlen(new_str);
    for (int i = 0; i < size; i++)
    {
        cout<<new_str[i];
    }
    cout<<endl;
    
    
    
    

    return str;
}


int main()
{
    string my_str = "Hello! World!";
    
    removeExclamationMarks(my_str);

    return 0;

}