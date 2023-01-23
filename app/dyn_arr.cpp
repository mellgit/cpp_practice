#include <iostream>
using namespace std;

void dynamic_array();
void double_dynamic_array();
void fill_array(int *const arr, const int size);
void show_array(const int *const arr, const int size);


int main(){

    // dynamic_array();

    // double_dynamic_array();

    /*
    копирование динамического массива
    чтобы скопировать один динамический массив в другой необходимо:
    - освободить память под выделенный первый массив (delete)
    - удалить указатель (nullptr)
    - циклов присвоить значения второго в первый

    примечание: если втупую присвоить один массив другому, то произойдет утечка памяти
    тк первый элемент первого массива будет указывать на первый элемент второго массива
    а элементы первого массива остануться весеть в памяти, что приводит к ошибке
    */
    const int size = 5;
    int *first_array = new int[size]; // выделение памяти для двух динамических массивов
    int *second_array = new int[size];
    fill_array(first_array, size); // заполнение массивов
    fill_array(second_array, size);

    cout<<"first array = \t";
    show_array(first_array, size); // вывод заполненных массивов
    cout<<"second array = \t";
    show_array(second_array, size);

    delete[] first_array; // очистка памяти от первого массива

    first_array = new int[size];
    for (int i=0; i<size; i++){
        first_array[i]=second_array[i]; // присваивание значения второго массива в новый массив
    }

    cout<<"========================"<<endl;

    cout << "first array = \t";
    show_array(first_array, size);
    cout << "second array = \t";
    show_array(second_array, size);

    delete[] first_array; // освобождение памяти
    delete[] second_array;

    return 0;
}

void fill_array(int* const arr, const int size){
    /*
    int* const arr - передача массива
    const int size - передача размера массива
    */

    for (int i=0; i<size; i++){
        arr[i]=rand()%20;
    }
}

void show_array(const int* const arr, const int size){
    
    for (int i = 0; i < size; i++){
        cout << arr[i] << "\t";
    }
    cout<<endl;
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