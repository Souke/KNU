#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << " IPZ 12 Tverdokhlib Angelina Bilet 11 Task 1" << endl;
    cout << "Введите ряд символов" << endl;
    getline(cin, str);

    str.erase(
        remove_if(str.begin(), str.end(), [](char c) {
            string del = "AEIOUaeiou";
            return isalpha(c) && del.find(c) != string::npos;
            }), str.end()
                );

    cout << str << endl;

    int* arr=new int[100];
    int index = 0;
    string tmp = "";


    for (char c : str) {
        if (isdigit(c)) {
            tmp += c;
        }
        else if (tmp != "") {
            arr[index] = stoi(tmp);

            cout << " " << arr[index];

            tmp = "";
            index += 1;
        }
    }
    if (tmp != "") {
        arr[index] = stoi(tmp);

        cout << " " << arr[index];
    }
    return 0;
}