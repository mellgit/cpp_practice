#include <iostream>
#include <string>
using namespace std; 

void pointer();
void arr_pointer();
void args_pointer(int *pa);
void more_args_pointer(int *pa, int *pb, int *pc);
void hw(int *pa, int *pb);
void reference();
void args_reference(int &a);
void more_args_reference(int &a, int &b, int &c);
template <typename T>
void hw2(T &a, T &b);
void new_delete();

int main()
{

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

    // int a = 5, b = 6;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // hw(&a, &b);
    // cout<<"call function"<<endl;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;


    // reference();
    // int a = 5;
    // cout << a << endl;
    // args_reference(a);
    // cout << a << endl;
    // int a=5, b=40, c=1;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout<<"call function"<<endl;
    // more_args_reference(a, b, c);
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;

    // int a=5, b=6;
    // double a = 5.6, b = 6.88;
    // string a="hello", b="world";
    // cout << a << endl;
    // cout << b << endl;
    // cout<<"call function"<<endl;
    // hw2(a, b);
    // cout << a << endl;
    // cout << b << endl;


    new_delete();

    return 0;
}


void new_delete(){
    /*
    работа с динамической памятью. new и delete
    new - выделяет память
    delete - освобождает эту память 
    в с++ не сборщика мусора, так что необходимо всегда убирать за собой
    */

    int *pa = new int; // выделение памяти
    *pa = 4;
    cout<<*pa<<endl; // использование выделенной памяти
    delete pa; // очистка памяти, но указатель на область памяти еще сещуствует
    pa = nullptr; // удаление указателя

    /*
    после очистки памяти необходимо избавиться от указателя, для этого используют NULL и nullptr
    что сделать:
    - освободить выделенную память (delete)
    - убрать указатель на выделенную область памяти (nullptr)
        есть еще NULL, но лучше использовать nullptr, тк это отдельный тип данных
        и компелятор никогда его не перепутает, тк NULL это целочисленный тип равный нулю
    
    ПРЕДУПРЕЖДЕНИЕ: если сначала убрать указатель, а потом освободить память, то произойдет утечка памяти
    выше показан правильный пример использования динамической памяти
    */
}

template <typename T>
void hw2(T &a, T &b){
    /*
    поменять местами переменные при помощи ссылок
    при объявлении шаблонной функции, шаблон так же необходимо передавать в прототип функции
    те сначала шаблон и ниже сама функция
    */
    T temp = a; // шаблонная переменная
    a = b; 
    b = temp;
}


void more_args_reference(int &a, int &b, int &c){
    /*
    возвращение нескольких значеинй при помощи ссылок
    схожи с указателями, только не нужно разименовывать 
    */
    a *= 5;
    b-=100;
    c++;
}

void args_reference(int &a){
    /*
    в таком случае удобнее работать с ссылками, тк нет необходимости в постоянном разименовании
    как например в указателях
    */
    a++;

}

void reference(){
    /*
    ссылки и указатели похожи, но есть разница: 
     - ссылки не нужно разименовывать  
     - инициализировать указать можно, ссылку нельзя, она всегда должна указывать на адресс переменной
       а указатель может оставаться пустым
     - указатель хранит -> NULL, 0, nullptr, сслыка не может хранить в себе эти типы

    */

    int a = 5;
    int *pa = &a; 
    int &aref = a;
    cout << a << endl; // 5
    cout << *pa << endl; // 5
    cout << pa << endl;    // 0x16d4237ec
    cout << &aref << endl; // 0x16d4237ec
    cout << aref << endl; // 5
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