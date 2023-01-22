#include <iostream>
using namespace std;

void dynamic_array();



int main(){

    dynamic_array();


    return 0;
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