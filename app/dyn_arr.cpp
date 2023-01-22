#include <iostream>
using namespace std;

void dynamic_array();
void double_dynamic_array();


int main(){

    // dynamic_array();

    double_dynamic_array();


    return 0;
}

void double_dynamic_array(){
    /*
    понятия двумерных массивов нет в с++
    по факту создается одномерный массив, каждый элемент указывает на другой одномерный массив
    те двумерный массив это одномерный массив одномерных массивов
    */


    // создание и выделения памяти массива
    int row; cout<<"enter row: ";cin>>row; 
    int col; cout<<"enter col: ";cin>>col; 

    int **arr = new int* [row]; // создание массива указателей

    for (int i=0; i<row; i++){
        // создание массивоа для каждого указателя основного массива
        arr[i] = new int[col];
    }

    // заполнение двумерного массива
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            arr[i][j] = rand()%20;
        }
    }
    // вывод двумерного массива
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout<<endl;
    }

    // удаление и очистка массива
    for (int i=0; i<row; i++){
        // удаление каждого массива, по указателю из основного массива
        delete [] arr[i]; 
        arr[i] = nullptr;
    }

    delete [] arr; // удаление основного массива, в котором хранятся указатели на другие массивы
    arr = nullptr;
}


void dynamic_array(){
    /*
    работа с динамическами массивами
    компилятор не следить за выделенной памятью, в таких случаях необходимо быть осторожнее
    */

    int size;
    cout<<"enter size array: ";cin>>size;

    int *arr = new int[size];

    for (int i=0; i<size; i++){
        arr[i]=rand()%20;
    }

    for (int i = 0; i < size; i++){
        cout << i+1 << ") " << arr[i] << endl;
        // cout << i + 1 << ") " << *(arr+i) << endl; // результат одинаковый, тк используется арифметика указателей
    }

    delete [] arr;

    cout << arr << endl; // 0x600001154040 - указатель на выделенную память еще существует, его необходимо удалить

    arr = nullptr; // удаление указателя

    cout << arr << endl; // 0x0 - результат удаления указателя
}