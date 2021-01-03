// Твердохліб Ангеліна ІПЗ 12 - 1 Лаб 7.2
#include <iostream>
#include <time.h>
using namespace std;
int row;
int matrix[8][8];
// Функція після виводу матриці
void PrintMatr() {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++)
        {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }

}


// Повертає матрицу matrix без row - ой строки и col - того стовпчики, результат в newMatrix
void getMatrixWithoutRowAndCol(int** matrix, int size, int row, int col, int** newMatrix)
{
    int offsetRow = 0;      //зміщення індексу рядка в матриці
    int offsetCol = 0;      //зміщення індексу стовпчики в матриці
    for (int i = 0; i < size - 1; i++)
    {
        //Пропустити row-ий рядок
        if (i == row)
        {
            offsetRow = 1;   //Як тільки зустріли рядок, яку треба пропустити, робимо зміщення для вихідної матриці
        }

        offsetCol = 0; //Обнулити зміщення стовпчика
        for (int j = 0; j < size - 1; j++)
        {
            //Пропустити col - ий стовпець
            if (j == col)
            {
                offsetCol = 1; //Зустріли потрібний стовпець, пропускаем його зміщенням
            }

            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}




//Обчислення визначника матриці розкладання по першому рядку
int matrixDet(int** matrix, int size)
{
    int det = 0;
    int degree = 1; // (-1)^(1+j) з формули

    //вихід з рекурсії
    if (size == 1)
    {
        return matrix[0][0];
    }
    //вихід з рекурсії
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        //матриця без стовпчика та рядка
        int** newMatrix = new int* [size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            newMatrix[i] = new int[size - 1];
        }

        //Розкладаємо по 0 - му рядку, цикл біжить по стовпцях
        for (int j = 0; j < size; j++)
        {
            // Видалити з матриці i-й рядок і j-ий стовпець
            // Результат в newMatrix
            getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);

            // Рекурсивний виклик
            // За формулою: сума по j, (-1) ^ (1 + j) * matrix [0] [j] * minor_j (це і є сума з формули)
            // де minor_j - додатковий мінор елемента matrix [0] [j]
            // (нагадаю, що мінор це визначник матриці без 0-го рядка і j-го стовпця)
            det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
            // "Накручуємо" ступінь множника
            degree = -degree;
        }

        // Чистимо пам'ять на кожному кроці рекурсії (важливо!)
        for (int i = 0; i < size - 1; i++)
        {
            delete[] newMatrix[i];
        }
        delete[] newMatrix;
    }



    return det;
}

int colon;
// Основна функція
int main()
{
    char key;
    int** matrix;
    system("chcp 1251");
    system("cls");

    cout << "Rows:  ";  cin >> row;
    cout << "Colon: ";  cin >> colon;
    cout << endl;
    cout << "1. Авто заповнення матриц " << endl;
    cout << "2. Матриця вручну " << endl;
    int f, t;
    cin >> key;
    switch (key)
    {
    case '1':

        if (row == colon)
        {
            cout << "Ведите от какого числа: "; cin >> f;
            cout << "Ведите до какого числа: "; cin >> t;
            cout << "Auto matrix " << endl;
            cout << "Квадратна!" << endl;
            matrix = new int* [colon];
            srand((unsigned)time(0));
            for (int i = 0; i < row; ++i)
            {
                matrix[i] = new int[colon];
                for (int J = 0; J < row; ++J)
                {
                    matrix[i][J] = f + rand() % (t - f);
                }
            }
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colon; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            int d;

            d = matrixDet(matrix, row);
            cout << "Визначник: " << d << endl;

        }
        else
            cout << "НЕ Квадратна!" << endl;

        break;

    case '2':
        cout << "Matrix(row<10,colon<10)" << endl;
        cout << "Create " << endl;
        if (row == colon)
        {
            cout << "Auto matrix " << endl;
            cout << "Квадратна!" << endl;

            matrix = new int* [colon];
            for (int i = 0; i < row; ++i)
            {
                matrix[i] = new int[colon];
                for (int J = 0; J < row; ++J)
                {
                    cin >> matrix[i][J];
                }
                cout << endl;
            }
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colon; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            int d;

            d = matrixDet(matrix, row);
            cout << d << endl;

        }
        else
            cout << "НЕ Квадратна!" << endl;

        break;


    }

    cin.get(); cin.get();
    return 0;
}