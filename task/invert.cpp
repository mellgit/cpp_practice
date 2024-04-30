/*
изменить знак всех значений массива
*/


#include <iostream>
using namespace std;


void invert(int* arr, int size)
{
    int temp_arr[5] = {-1,2,3,-4,-5};

    for (int i = 0; i < size; i++)
    {
        arr[i] = temp_arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }


    for (int i = 0; i < size; i++)
    {
        arr[i] = (-1) * arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int size = 5;
    int *arr = new int[size];

    invert(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}