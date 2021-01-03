// Твердохліб Ангеліна лаб 6 ІПЗ 12-1
#include <time.h> 
#include <iostream>
#include <iomanip>
using namespace std;

int row = 8;
int col = row;
//====================== Функція генерації розрідженої матриці ================
void autoArr(int** matr)
{
    srand((unsigned)time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matr[i][j] = rand() % 25;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] > 5)
            {
                matr[i][j] = 0;
            }
        }
    }
}

//======================= Функція виводу матрииці =======================
void outMatr(int** matr)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(4) << matr[i][j];
        }
        cout << endl;
    }
}

int x = 0;
int s = 100;
int* arrAN = new int[s];
//===================== Знаходження не нульових елементів матриці   (AN) =============== 
void values(int** matr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] != 0)
            {
                arrAN[x] = matr[i][j];
                x++;
            }
        }
    }
    cout << "AN: ";
    for (int i = 0; i < x; i++)
    {
        cout << arrAN[i] << "  ";
    }
}

//===================== Знаходження номерів стовпців ненульових елемнтів (JA)===================
void index(int** matr)
{
    int y = 0;
    int colon = 100;
    int* arrJA = new int[colon];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] != 0)
            {
                arrJA[y] = j;
                y++;
            }
        }
    }
    cout << "JA: ";
    for (int i = 0; i < y; i++)
    {
        cout << arrJA[i] << "  ";
    }
    delete[] arrJA;
}

//============================== Створення останього масива (IA) ==================
void poiter_index(int** matr)
{
    int z = 0;
    int row_index = 0;
    int I = 100;
    int* arrIA = new int[I];        //arrІА = кількість елементів кожної строки(нижче головної діагоналі) 
    for (int i = 0; i < row; i++)                                  //+ ті що вище 
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] != 0)
            {
                row_index++;
            }
        }
        arrIA[z] = row_index;
        z++;
    }
    cout << "\nIA: ";
    for (int i = 0; i < z; i++)
    {
        cout << arrIA[i] << "  ";
    }
    delete[] arrIA;
}

int t = 0;
double seconds;
//==================== Пошук максимального елемента матриці за алгоритмом =========
void max_algoritm()
{
    clock_t start = clock();      // Початок відрахунку часу для алгоритму пошуку
    int maxA = 0;
    int b = 0;
    int mas[50];
    for (int i = 0; i < x; i++)
    {
        t++;
        if (arrAN[i] > maxA)
        {
            maxA = arrAN[i];
        }
    }
    for (int i = 0; i < x; i++)
    {
        t++;
        if (arrAN[i] == maxA)
        {
            mas[b] = i;
            b++;
        }
    }
    cout << " MAX element by Algorutm : " << maxA << endl;
    clock_t end = clock();            // Кінець відрахунку часу алгоритму
    seconds = (double)(end - start) / CLOCKS_PER_SEC;    // Підрахунок секунд
}

double seconds1;
int T = 0;
//=================== Пошук максимаьного елемента матриці оригінальним способом =====
void max_orirginal(int** matr)
{
    clock_t start = clock();          // Початок відрахунку часу звичайного методу
    int max_index = 0;
    int max_jndex = 0;
    int mas[50][50];
    for (int i = 1; i < row; ++i)
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] > matr[max_index][max_jndex])
            {
                max_index = i;
                max_jndex = j;
            }
            T++;
        }
    }
    int ln = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; j++)
        {
            if (matr[i][j] == matr[max_index][max_jndex])
            {
                mas[ln][0] = i;
                mas[ln][1] = j;
                ln++;
            }
            T++;
        }
    }
    if (ln > 1)
    {
        T++;
        
        cout << " MAX element by original: " << matr[max_index][max_jndex] << " (" << max_index << "," << max_jndex << ")" << endl;
        for (int i = 0; i < ln; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << setw(3) << mas[i][j];
                T++;
            }
            cout << endl;
        }
        cout << "===============================" << endl;
    }
    else
    {
        T++;
        
        cout << "MAX element by original : " << matr[max_index][max_jndex] << " (" << max_index << "," << max_jndex << ")" << endl;
        cout << "================================" << endl;
    }
    clock_t end = clock();              // КІнець відрахнку часу звичайного матоду
    seconds1 = (double)(end - start) / CLOCKS_PER_SEC;// Підрахунок секунд
    seconds1 = seconds1 + 0.0001;
}

//============== Головна функція =============//
int main()
{
   
    system("cls");
    
    int** matr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        matr[i] = new int[col];
    }
    int key;
    cin >> key;
    if (key == 1);
    {autoArr(matr); }
    if (key == 2);
    {
        outMatr(matr);
        cout << "=================================" << endl;
        cout << endl;
    }

    if (key == 3);
    {
        values(matr);
        cout << endl;
        index(matr);
        poiter_index(matr);
        cout << "\n================================" << endl;
    }
    if (key == 4);
    {
        max_algoritm();
        max_orirginal(matr);
        cout << endl;
    }
    if (key == 5);
    {
        printf("Algorutm`s time: %f seconds\n", seconds);          // Час операції алгоритму
        cout << "Algorutm`s memory: " << t * 4 << " byte" << endl;    // Виділена паям'ять для агоритма
                    // ==========
        printf("Original`s time: %f seconds\n", seconds1);        // Час операції звичайного пошуку
        cout << "Original`s memory:" << T * 4 << " byte" << endl;
        cout << "===============================" << endl;
    }
    // Виділена пам'ямть
    for (int i = 0; i < row; i++)
    {
        delete matr[i];
    }
    delete[] arrAN;
}