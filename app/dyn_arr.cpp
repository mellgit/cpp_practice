#include <iostream>
using namespace std;

void dynamic_array();
void double_dynamic_array();
void fill_array(int *const arr, const int size);
void show_array(const int *const arr, const int size);
void push_back(int *&arr, int &size, const int value);
void pop_back(int *&arr, int &size);
void push_forward(int *&arr, int &size, const int value);
void pop_forward(int *&arr, int &size);
void hw();

int main(){

    // dynamic_array();

    // double_dynamic_array();



    /*
    копирование динамического массива
    чтобы скопировать один динамический массив в другой необходимо:
    - создать два дин массива
    - освободить память под выделенный первый дин массив (delete)
    - циклов присвоить значения второго в первый
    - освободить память под выделенные дин массивы (delete)
    - присвоить значение nullprt для указателей на дин массивы

    примечание: если втупую присвоить один массив другому, то произойдет утечка памяти
    тк первый элемент первого массива будет указывать на первый элемент второго массива
    а элементы первого массива остануться весеть в памяти, что приводит к ошибке
    */
    // const int size = 5;
    // int *first_array = new int[size]; // выделение памяти для двух динамических массивов
    // int *second_array = new int[size];
    // fill_array(first_array, size); // заполнение массивов
    // fill_array(second_array, size);

    // cout<<"first array = \t";
    // show_array(first_array, size); // вывод заполненных массивов
    // cout<<"second array = \t";
    // show_array(second_array, size);

    // // cout << *first_array << endl; // указатель на первый элемень в первом массиве
    // delete[] first_array; // очистка памяти от первого массива
    // // cout << *first_array << endl; // мусор
    // // first_array = new int[size]; // ноль
    // cout << *first_array << endl;
    // for (int i=0; i<size; i++){
    //     first_array[i]=second_array[i]; // присваивание значения второго массива в новый массив
    // }

    // cout<<"========================"<<endl;

    // cout << "first array = \t";
    // show_array(first_array, size);
    // cout << "second array = \t";
    // show_array(second_array, size);

    // delete[] first_array; // освобождение памяти вновь объявленного массива (first_array = new int[size];)
    // delete[] second_array;

    // cout << "==================================================" << endl;
    
    // cout << first_array << endl;
    // cout << second_array << endl;
    // cout << "clear pointer" << endl;
    // first_array = nullptr;
    // second_array = nullptr;
    // cout << first_array << endl;
    // cout << second_array << endl;

    /*
    result =>
    first array = 	7	9	13	18	10
    second array = 	12	4	18	3	9
    ========================
    first array = 	12	4	18	3	9
    second array = 	12	4	18	3	9
    */




   // изменение размера дин массива
    // int size = 5;
    // int *arr = new int[size]; // выделение памяти для двух динамических массивов
    // fill_array(arr, size);    // заполнение массивов
    // show_array(arr, size); // вывод заполненных массивов

    // push_back(arr, size, 111);

    // show_array(arr, size); // вывод заполненных массивов

    // pop_back(arr, size);

    // show_array(arr, size);

    // delete[] arr;



    // домашнее задание
    hw();



    return 0;
}


void hw(){
    /*
    удаление и добавление в начале дин массива
    */

    int size = 5; 
    int *arr = new int[size];
    fill_array(arr, size); // заполнение массивов
    show_array(arr, size); // вывод заполненных массивов
    push_forward(arr, size, 222); // добавление в начало дин массива
    show_array(arr, size);
    pop_forward(arr, size); // удаление первого элемента из дин массива
    show_array(arr, size);


}

void push_forward(int *&arr, int &size, const int value){

    int *new_array = new int[size + 1]; // новый дин массив будет на 1 элемент больше

    new_array[0] = value; // присвоить сразу первому элементу значение
    size++; // +1 элемент = размер +1

    for (int i=1; i<size; i++){
        // в первом дин массиве необходимо забирать с 0-го элемента
        // а в новый записывать с 1-го, тк в нем уже лежит значение на 0-ом индексе
        new_array[i] = arr[i - 1]; 
    }

    // освобождение памяти
    delete[]arr;
    arr = new_array;


}

void pop_forward(int *&arr, int &size){

    size--; // размер -1, тк дин массив становится на один элемент меньше
    int *new_array = new int[size];

    for (int i=1; i<size; i++){
        // в новый дин массив записываем с 0-го элемента
        // из старого берем с 1-го, тк 0-ой мы удаляем
        new_array[i-1] = arr[i];
    }

    // освобождение памяти
    delete[]arr;
    arr = new_array;
}

void push_back(int *&arr, int &size, const int value){
    /*
    добавление элемента в конец дин массива
    1 - создать второй дин массив
    2 - заполнить его значениями из первого дин массива
    3 - в последний элемент (new_array[size]) добавить новое значение
    4 - освободить память, выделенную для первого дин массива
    5 - тк указатель на первый элемент первого дин массива все еще указывает на перрвый дин массив
        необходимо его изменить на указатель новый второй дин массив (arr = new_array;)
        тк указатель передан по ссылке, мы его переприсвоить можем
    */
    int *new_array = new int[size+1];

    for (int i=0; i<size; i++){
        new_array[i] = arr[i];
    }
    new_array[size] = value;

    size++; // для второго дин массива, тк его размер больше первого на единицу

    delete[]arr;

    arr = new_array;

}

void pop_back(int *&arr, int &size){
    /*
    удаление элемента в конец дин массива
    1 - уменьшить размер нового второго дин массива
    1 - создать второй дин массив
    2 - заполнить его значениями из первого дин массива
    3 - освободить память, выделенную для первого дин массива
    4 - тк указатель на первый элемент первого дин массива все еще указывает на перрвый дин массив
        необходимо его изменить на указатель новый второй дин массив (arr = new_array;)
        тк указатель передан по ссылке, мы его переприсвоить можем
    */
    size--;   
    int *new_array = new int[size];

    for (int i = 0; i < size; i++)
    {
        new_array[i] = arr[i];
    }
    
    delete[] arr;

    arr = new_array;
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