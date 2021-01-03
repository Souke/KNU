//Твердохліб Ангеліна ІПЗ 12-1 Лаб 7.1

#include <time.h>
#include <iomanip>
#include <iostream>
using namespace std;

int row, colon;              // рядки / стовп
int a[9][9];

void autoMatr() //генерування матриці
{
    cout << "Rows:  ";  cin >> row;
    cout << "Colon: ";  cin >> colon;
    cout << endl;
    if ((row < 10) && (colon < 10))
    {
        srand((unsigned)time(NULL));

        for (int i = 0; i < row; ++i)
        {
            for (int J = 0; J < colon; ++J)
            {
                a[i][J] = rand() % 9 + 1;
                if (i > 0 && i == J)
                {
                    a[i][J] = 0;
                }
            }
        }
    }
    else cout << " ";
}

void create() //створення матриці
{
    cout << "Rows:  ";  cin >> row;
    cout << "Colon: ";  cin >> colon;
    cout << endl;
    if ((row < 10) && (colon < 10))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colon; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    else cout << " Please, enter [3;9]" << endl;
}

void Output() // друк
{
    if ((row < 10) && (colon < 10))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colon; j++)
            {
                cout << setw(3) << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    else cout << " Please, enter matrix" << endl;
}


void Perestanovka() // перестановка рядків і стовпчиків
{
    setlocale(LC_ALL, "ru");
    int mi = 0;
    int ro;
    int p, g;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            ro = row - j;
            if (a[i][j] == 0 && i == j)
            {
                i == mi;
                for (int i = 0; i < row; i++)
                {
                    p = a[i][mi];
                    a[i][mi] = a[i][ro];
                    a[i][ro] = p;

                }
            }
        }
    }

    int e = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (a[i][j] == 0 && i == j)
            {
                for (int i = 0; i < row; i++)
                {
                    g = a[i][e];
                    a[i][e] = a[i][1];
                    a[i][1] = g;

                }
                e++;
            }
        }
    }

    if (row < 7)
    {
        for (int i = 0; i < row; i++)
        {
            g = a[i][2];
            a[i][2] = a[i][0];
            a[i][0] = g;
        }
    }
    if (row >= 7 && row < 9)
    {
        for (int i = 0; i < row; i++)
        {
            g = a[i][3];
            a[i][3] = a[i][row - 1];
            a[i][row - 1] = g;
        }
    }
    if (row == 9)
    {
        for (int i = 0; i < row; i++)
        {
            g = a[i][4];
            a[i][4] = a[i][row - 2];
            a[i][row - 2] = g;
        }
    }
  
}






int mas[10][2];
int max_Index() //максимальний елемент
{
    int I = 0;
    int J = 0;
    int max_index = 0;
    int max_jndex = 0;
    for (int i = 1; i < row; ++i)
    {
        for (int j = 0;j < colon;j++)
        {
            if (a[i][j] > a[max_index][max_jndex])
            {
                max_index = i;
                max_jndex = j;

            }
        }
    }
    cout << "\nmax = " << a[max_index][max_jndex] << "(" << max_index << "," << max_jndex << ")" << endl << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colon; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = a[max_index][max_jndex];
            }
        }
    }

    Output();
    return 0;
}

int main() // головна функція
{
    bool flag = true;
    char key;
    do
    {
        setlocale(LC_ALL, "ru");
        cout << "1. Авто заповнення матриц " << endl;
        cout << "2. Матриця вручну "<< endl;
        

        cin >> key;
        switch (key)
        {
        case '1':
            cout << "Matrix(row<10,colon<10)" << endl;
            cout << "Auto matrix " << endl;
            autoMatr();
            Output();
            Perestanovka();
            max_Index();
           
            
            break;
        case '2':
            cout << "Matrix(row<10,colon<10)" << endl;
            cout << "Create " << endl;
            create();
            Output();
            Perestanovka();
            max_Index();
            
            Output();
            
            break;
        }
    } while (flag == true);
}