#include <iostream>
#include <iomanip>

#include <time.h>


using namespace std;

int* randomItems(int size) {
    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10 - 10;
        cout << setw(4) << arr[i];
    }

    cout << endl;
    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned)(time(NULL)));

    int size, min = 3000, min_index;
    cout << "IPZ 12 Tverdokhlib Angelina Bilet 11 Zav 2" << endl;
    cout << "Введите размер массивов" << endl;
    cin >> size;

    int* arr1 = randomItems(size);
    int* arr2 = randomItems(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr1[i] == arr2[j] && min > arr1[i]) {
                min = arr1[i];
                min_index = i;
            }
        }
    }

    cout << "Наименьший элемент: " << min << " Индекс: " << min_index;

    return 0;
}