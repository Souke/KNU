//Твердохліб Ангеліна Сергіівна. ІПЗ 12-1. Лаб 5.2
#include<iostream>
#include <conio.h>
using namespace std;


int printDigit(int d) { //функція, що розділяє числа.
    int rem = d % 10; //ділить число на 20, та вертає остачу.
    if (d == 0) { //якщо число = 0, рекурсія закінчується.
        return -1;
    }
    else {
        printDigit(d / 10); 
    }
    cout << rem; 
    cout << " ";
    return -1;
}


int main() { // головна функція.
    char key = ' ';
    while (key != 'B')
    {


        cout << "IPZ 12/1 Tverdokhlib Angelina. Lab 5.2" << endl;
        cout << "enter your number: " << endl;
        int n;
        cin >> n;

        printDigit(n); // друкує числа.
        cout << " " << endl;
        
    }
    key = _getch();
}