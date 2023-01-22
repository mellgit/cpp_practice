#include <iostream>
using namespace std; 

void pointer();
void arr_pointer();
void args_pointer(int *pa);
void more_args_pointer(int *pa, int *pb, int *pc);
void hw(int *pa, int *pb);



int main(){

    // pointer();
    //arr_pointer();

    // int a = 5;
    // cout << a << endl;
    // args_pointer(&a);
    // cout << a << endl;


    // int a = 0, b=1, c=0;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout<<"call function"<<endl;
    // more_args_pointer(&a, &b, &c);
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;

    int a = 5, b = 6;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    hw(&a, &b);
    cout<<"call function"<<endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}


void hw(int *pa, int *pb){
    /*
    поменять значения переменнойо местами
    */
   int temp = (*pa);
   (*pa) = *pb;
   (*pb) = temp;

    
}

void more_args_pointer(int *pa, int *pb, int *pc){
    /* 
    изменение нескольких параметров при использовании указателей 
    */
    (*pa) = 44;
    (*pb)++;
    (*pc) = -87;
}

void args_pointer(int *pa){
    /*
    передача параметров по указателю
    не возвращая значений удалось изменить самое значение переменной а
    тк обращения было по указателю
    */

   (*pa)++; // соблюдая приоритет: сначала разименовать, потом прибавить 
}

void arr_pointer(){
    /*
    арифметика указателей
    опасность в том, что можно попасть через указатели в другую область памяти
    что может привести к проблеме, поэтому необходимо самостоятельно следить за этим
    */

    // имея массива это указатель на его первый элемент
    const int size = 5; 
    int arr[size]{2,6,5,8,3};

    for (int i=0; i<size; i++){
        cout<<arr[i]<<endl;
    }

    cout<<"================================"<<endl;
    int *pArr = arr;

    // идентично первому циклу
    for (int i = 0; i < size; i++)
    {
        // cout << pArr[i] << endl;
        cout << *(pArr+i) << endl; // тоже самое что и строчкой выше

        // если не разименовывать, то будут адреса памяти + 4 байта, тк массив целочисленный
        cout << (pArr + i) << endl;
    }
}



void pointer(){

    /*
    - типы указателей должны быть ровны
    */
    int a = 5;
    cout << a << endl; // 5 - значеине

    int *pa = &a;
    int *pa2 = pa; // указатель на указатель

    cout << pa << endl; // 0x16d13f7ec - адрес в памяти
    cout << *pa << endl; // 5 - значеине (разименование)
    cout << &a << endl; // 0x16d13f7ec - адрес в памяти
    
    // если изменить значеине разименованного указателя (не важно первого или второго в данном случае)
    // то значение переменной а изменится на указанное ниже (99)
    // тк по указанному адресу памяти изменили значение
    *pa2 = 99;
    cout<<a<<endl;

}