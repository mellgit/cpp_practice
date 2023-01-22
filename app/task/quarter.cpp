
/*
Дан месяц как целое число от 1 до 12, вернитесь к тому, к какому кварталу года он принадлежит, 
как целое число.

Например: 2-й месяц (февраль) является частью первого квартала; 
6 месяц (июнь) входит во второй квартал; и месяц 11 (ноябрь) является частью четвертого квартала.

Ограничение: 1 <= month <= 12
*/

#include <iostream>
using namespace std;

int quarter_of(int month);

int main(){

    int month = 12;
    cout<<quarter_of(month)<<endl;
    return 0;
}

int quarter_of(int month)
{
    
    const int row = 4;
    const int col = 3;

    int arr[row][col] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (month==arr[i][j]){
                return i+1;
            }
        }
    }

    return 0;
}

/*
best solution

int quarter_of(int month)
{
    return (month + 2) / 3;
}
*/
