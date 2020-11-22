// Твердохліб Ангеліна Сергіївна. ІПЗ 12-1. Лаб 5.1
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
//Рекурсія
double Function(int n, int i = 1)
{
    if (n == 1) {
        cout << "\nDepth of recursion= " << i << endl; //вказує глубину рекурсії.
        return 0;
    }
    else if (n == 2) {
        cout << "\nDepth of recursion= " << i << endl; //вказує глубину рекурсії.
        return 0;
    }
    else if
        (n == 3) {
        cout << "\nDepth of recursion= " << i << endl; //вказує глубину рекурсії.
        return 1;
    }
    else if
        (n % 2 == 0) return 2 * Function(n / 2, i + 1);
    else return
        Function(n / 2, i + 1) + Function(n / 2 + 1, i + 1);
}
//Цикл
double FunctionCicle(int n)
{
    int k = 0;
    while (n) {
        k++;
        if (n == 1 || n == 2) {
            cout << "\nNumber of iterations= " << k << endl; //вказує кількість інтерації.
            return 0;
        }
        else if (n == 3) {
            cout << "\nNumber of iterations= " << k << endl; //вказує кількість інтерації.
            return 1;
        }
        else if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = (n / 2) + 1;
        }
    }
}

//Головна функція
int main()
{
    char key = ' ';
    while (key != 'B') {
        int n;
        cout << "IPZ-12/1 Tverdokhlib Angelina. Laboratorna robota 5.1" << endl;
        cout << "Calculate the number of abilities" << endl;
        cout << "\nNumber of soldiers n: ";
        cin >> n;
        cout << "Result through recursion= " << Function(n) << endl; //результат рекурсії.

        if (n == 1 || n == 2)
            cout << "The result of the iterations " << 0 << endl; //результат інтерації.
        else if (n == 3) {
            cout << "The result of the iterations= " << 1 << endl; //результат інтерації.
        }
        else if (n % 2 == 0) {
            cout << "The result of the iterations= " << 2 * FunctionCicle(n / 2) << endl; //результат інтерації.
        }
        else {
            cout << "The result of the iterations= " << FunctionCicle(n / 2) + FunctionCicle(n / 2 + 1) << endl; //результат інтерації.
        }
        cout << "\nThe number of iterations works more efficiently `cause it is performed by 1 action less" << endl; //Інтерація більш єфективна, так як виконує меньше кількість дій чим рекурсія.
        cout << "Press B to exit or any key to continue program" << endl;
        key = _getch();
    }
}