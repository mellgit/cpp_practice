#include <iostream>
#include <ctime>
using namespace std;


void unic_rand_value(){
    const int size = 10;
    int arr[]= {};
    bool temp;
    for (int i=0; i<size; ){

        temp = false;
        int new_random_value = rand()%15;

        for (int j=0; j<i; j++){

            if (arr[j] == new_random_value){
                temp = true;
                break;
            }
        }

        if (!temp){
            arr[i] = new_random_value;
            i++;
        }
    }

    for (int i=0; i<size; i++){
        cout<<arr[i]<<endl;
    }


    cout<<"===================="<<endl;

    int min_value = arr[0];
    for (int i=1; i<size; i++){

        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    int max_value = arr[0];
    for (int i = 1; i < size; i++)
    {

        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    cout << "min value " << min_value << endl;
    cout << "max value " << max_value << endl;
}



void rand_fun(){

    
    int value = rand(); // числа без диапозона
    cout << value << endl;

    int value1 = rand()%20; // от 0 до 20
    cout << value1 << endl;

    int value2 = rand() % 20 + 10; // от 10 до 30
    cout << value2 << endl;

    cout<<"create array"<<endl;
    const int size = 10;
    int arr[size];

    for (int i=0; i<size; i++){
        arr[i]=rand()%30;
        cout<<arr[i]<<", ";
    }

}

void arr_fun(){
    double arr[] = {1, 3};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "len(arr) = " << SIZE << endl;

    cout << "arr = ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i];
        if (i + 1 == SIZE)
        {
            cout << "" << endl;
        }

        else
            cout << ", ";
    }
    cout << endl;
}


void double_arr(){

    const int row = 3;
    const int col = 3;
    
    
    
    int arr[row][col]{};

    cout << __cplusplus<<endl;

        for (int i = 0; i < row; i++)
    {

        for (int j=0; j<col; j++){
            arr[i][j] = rand()%20;
        }
    }

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    srand(time(NULL)); // достаточно вызвать один раз в main
    // arr_fun();

    // rand_fun();

    // unic_rand_value();

    double_arr();

    return 0;
}