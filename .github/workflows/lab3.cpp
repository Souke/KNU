// Твердохліб Ангеліна, ІПЗ 12, варіант 4, лаб.3
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




using namespace std;
float x; // параметр зовнш суми
float k = 0; // параметр внутр суми
float sum = 0; // сума ряду
float error; // точність розрахунків
float member; // елемент ряду



// розрахунок факторіалу числа

float factorial(int number) // number - число, факторіал якого шукають
{
    float fact = 1;
    if (number == 0) fact = 1;
    else
    {
        for (int i = 1; i <= number; i++)
            fact *= i;
    }
    return (float)fact;
}

// виведення поточних рохрахунків
void OutputSum()
{
    cout << setw(5) << x << setw(10) << k << setw(20) << member << setw(15) << sum << endl;
}

// обчислення елементу ряду та суми
void MemberAndSum()
{
    double Numerator; // чисельник елемента ряду
    double Denominator; // знаменник елемента ряду
    for (x = 1; x <= 5; x++)
    {
        k = 0;
        do
        {
            Numerator = (pow(x, (2 * k - 1)));
            if (k > 18)
            {
                cout << "overflow - break cycle with k" << endl;
                break;
            }
            else
            {
                Denominator = factorial(k + x) * factorial(k);
                member = (float)Numerator / Denominator;
                member *= (-1);
                sum += member;
                OutputSum();
                k++;
            }
        }

        while (fabs(member) < error); // поки не досягнуто заданної точності
    }
}


int main()
{
   

    {

        char key = ' ';

        while (key != 'e')

        {
            system("cls");

            cout << "To calculate the sum of row" << endl;

            cout << "5 endlessneess" << endl;
            cout << " sum (sum (((-1)^k)* (x)^(2k-1))/(k+x)!*k!))" << endl;
            cout << "x = 1 k=0" << endl;
            cout << "input error:";
            cin >> error;
            cout << "result:" << endl;
            cout << "  x           k            member           sum" << endl;
            MemberAndSum();
            cout << "sum=" << sum << endl;
            
            system("pause");
        }

        key = _getch();
        
        
    }

   
}
