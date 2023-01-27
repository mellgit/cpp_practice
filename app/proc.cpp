#include <iostream>
#define PI 3.14
// #define begin {
// #define end }
#define sum(x,y) (x*y)

using namespace std;


void prepoccesing();


int main(){

    prepoccesing();
    return 0;
}

void prepoccesing(){
    /*
    директива препроцессинга #define - константа
    при помощи этой директивы можно переназначить значение
    но это вещь опасная, если взять функцию begin() и дать имя define begin, 
    то компилятор еще до сборки заменит функцию на define, что может плачевно закончится
    */

    cout<<PI<<endl;
    // begin and end вместо фигурных скобок
    // for (int i = 0; i < 6; i++)
    // begin
    //     cout<<i<<endl;
    // end

    /*
    в макрос можно довабить функцию
    функция принимает параметры и сразу возвращает результат
    похожа на lambda в python
    */
    cout<<sum(4,5)<<endl;

}