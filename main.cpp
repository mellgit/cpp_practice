#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int testFunction(int value){
    for (int i = 0; i < value; i++)
    {

        if (i % 2 == 0)
        {
            cout << i << " chetnoe" << endl;
        }
        else
            cout << i << " ne chetnoe" << endl;
    }
    return 0;
}

int testFunctionArray(){
    
    int array[5] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]); // определение длинны массива
    for (int i=0; i<size; i++){
        cout<<array[i]<<endl;
    }
    return 0;
}

int testFunctionString(string valueStr){

    int i = 0;
    int size = valueStr.size();
    cout<<"len string = "<<size<<endl;
    while (i<size)
    {
        for (int j=0; j<=i; j++){
            cout<< valueStr[j];
        }
        cout<<endl;
        i++;
    }
    return 0;
}


int test(int arr[]){
    
    cout<<arr<<endl;
    cout<<typeid(arr).name();
    // int *begin = begin(arr);
    // int *end = end(arr);

    // cout<<begin<<endl<<end;
    // cout<<size<<endl;
    // for (int i=0; i<=size; i++){
    //     cout<<arr[i]<<endl;
    // }

    return 0;
}
int main()
{

    // int arr[] = {1,2,3,4};
    // cout << typeid(arr).name()<<endl; // узнать тип данных
    // test(arr);

    // setlocale(LC_ALL,"Rus"); // данная ф-я нужна только для windows

    cout<<"привет мир"<<endl;
    // int nums1[] = {1, 2, 3, 4, 5};
    // int *begin = std::begin(nums1); // узнать длинну массива 
    // int *end = std::end(nums1);
    // cout<<*begin<<endl<<*end;

    // string valueStr;
    // cout << "enter string: ";
    // getline(cin, valueStr); // считывание всей вводимой строки, тк cin считывает только первое слово
    // testFunctionString(valueStr);



    // testFunctionArray();

    // cout << "for cicle\n";
    // int value;
    // cout << "enter value: ";cin >> value;
    // testFunction(value);



    // cout<<"while cicle\n";
    // int i = 0;
    // while (i<10){
    //     cout << i << " iteration" << endl;
    //     i++;
    // }

    // cout << "do while cicle\n";
    // int j = 0;
    // do
    // {
    //     cout << i << " iteration" << endl;
    // } while (j>10);
    
    
    return 0;
}
