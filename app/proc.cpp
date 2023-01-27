#include <iostream>
#define PI 3.14
// #define begin {
// #define end }
#define sum(x,y) (x*y)
// #define DEBUG
#define VALUE 6

using namespace std;


void prepoccesing();
void conditional_compilation();

int main(){

    // prepoccesing();
    conditional_compilation();
    return 0;
}

void conditional_compilation(){
    /*
    условная компиляция - если директива define определена,
    то код внутри ifdef и endif будет выполнятся, иначе нет
    можно использовать в отладке, те при подключенной define DEBUG 
    будет выводиться отладочная информация, а без ее подключения 
    отладочной информации не будет 

    #else - если директива определена, то работает ifdef, 
    иначе отработает #else

    #if, #elif, #else - работают точно так же как и if, elif, else
    только на уровне препроцессинга
    */
#ifdef DEBUG
    cout<<"begin cicle"<<endl;
#else
    cout<<"DEBUG off"<<endl;
#endif

    for (int i = 0; i < 4; i++)
    {
        cout<<i<<endl;
    }
    
#ifdef DEBUG
    cout << "end cicle" << endl;
#endif

#if VALUE == 1
    cout<<"value > 1"<<endl;
#elif VALUE == 5
    cout << "value > 5" << endl;
#else
    cout<<"idk what the value"<<endl;
#endif
}


void prepoccesing(){
    /*
    директива препроцессинга #define - константа
    при помощи этой директивы можно переназначить значение
    но это вещь опасная, если взять функцию begin() и дать имя define begin, 
    то компилятор еще до сборки заменит функцию на define, что может плачевно закончится
    */

    cout<<PI<<endl;
    // begin и end вместо фигурных скобок
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