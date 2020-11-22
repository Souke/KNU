// “вердохл≥б јнгел≥на ≤ѕ« 12 Ћаб 6.3

#include <iostream>
using namespace std;
//глобальн≥ зм≥нн≥
bool isShowResult;
bool isCreated = false;

int* a;  // массив а
int* b; // массив b
int* c; // массив, що м≥стить значенн€, €к≥ отримаЇмо
int ab, bmod, amod; // множенн€ массив≥в, модуль а та b
    
 
   
    int length = 10;
   

   
    void CreateL() { // створенн€ довжини
        int l;

        while (true)
        {
            cout << "Input length: ";
            if (scanf_s("%d", &l) != 1) {
                cout << "You must input only numbers" << endl;
                while (getchar() != '\n') {}
            }
            else if (l < 3 || l > 20) {
                cout << "Length must be > 2 and < 20" << endl;
                while (getchar() != '\n') {}
            }
            else {
                break;
            }
        }

        length = l;
        a = new int[l];
        b = new int[l];
        c = new int[l];
        
        
    }

    void  Vectora() // отриманн€ вектора а
    {

        for (int i = 0; i < length; i++)
        {
            int num;
            while (true)
            {
                cout << "Input number vector a : ";
                if (scanf_s("%d", &num) != 1)
                {
                    cout << "You must input only numbers" << endl;
                    while (getchar() != '\n') {}
                }
                else {
                    break;
                }
            }
            a[i] = num;
            cout << a[i] << endl;
            
        }
    }
    
    void Vectorb() // отриманн€ вектора b
    {
        for (int j = 0; j < length; j++)
        {
            int num2;
            while (true)
            {
                cout << "Input number vector b: ";
                if (scanf_s("%d", &num2) != 1) {
                    cout << "You must input only numbers" << endl;
                    while (getchar() != '\n') {}
                }
                else {
                    break;
                }
            }
            b[j] = num2;
            cout << b[j] << endl;
        }
        
    }
    void PrintArrayA()  // друк массива а
    {

        cout << "=====================================" << endl;
        cout << " Vector A:" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << a[i] << " ";
            
        }
        cout << endl;
        cout << "=====================================" << endl;
    }
    void PrintArrayB() // друк массива b
    {

        cout << "=====================================" << endl;
        cout << " Vector B:" << endl;
        for (int i = 0; i < length; i++)
        {
           
            cout << b[i] << " ";
        }
        cout << endl;
        cout << "=====================================" << endl;
    }
       void Sum() // сума координат вектор≥в
        {

           cout << "{";
    for (int k = 0, i=0, j=0; i < length; k++, i++, j++)
    {
                 c[k] = a[i] + b[j];
                 cout << a[i] << "+" << b[i] << "=";
                 cout << c[k] << " ;";
    }
                
           
           cout << "}"<< endl;
       }
       
void Diff() //р≥зниц€ координат вектора
{
    cout << "{";

    for (int k = 0, i = 0, j = 0; i < length; k++, i++, j++)
    {
                c[k] = a[i] - b[j];
                cout << a[i] << "-" << b[i]<< "=";
                cout << c[k] << " ;" ;
            
        
    }
    cout << "}";
    cout << endl;
}

void Kos() // косинус кута м≥ж двома векторами
{
    
    for (int i = 0, j = 0; i < length; i++, j++)
            {
                ab += (a[i] * b[j]);
                
                amod += sqrt(pow(a[i], 2));
                
                bmod += sqrt(pow(b[j], 2));
                
            }
        
    
    
    cout << ab << "/" << (amod * bmod) << endl;
}
   


void Skal() // скал€рний добуток двох вектор≥в
{
    cout << "ab=";
    for (int i = 0, j = 0; i < length;  i++, j++)
            {
                ab += (a[i] * b[j]);
                cout << a[i] << "*" << b[j] << "+";
            
        
            }
    cout << "=" <<ab  << endl;
}
   
    


void Vectorn() // векторний добуток двох вектор≥в
{

    int kos, sin, c;
    for (int k = 0, i = 0, j = 0; i < length; k++, i++, j++)
            {
                ab += (a[i] * b[j]);

                amod += sqrt(pow(a[i], 2));
                bmod += sqrt(pow(b[j], 2));
                
            }
        
    
    kos = ab / (amod * bmod);
    sin = sqrt(1 - pow(kos, 2));
    c = amod * bmod * sin;
    cout << "cos ab="<< ab << "/" << amod <<"*"<< bmod << "=" << kos << endl;
    cout << "sin ab=" << "sqrt" << "(1-" << kos << "^2)" << sin << endl;
    cout << "|a|*|b| * sin ab=" << amod <<"*"<< bmod <<"*"<< sin << "="<< c << endl;
}
void Menu() { // меню
    int menu; while (true)
    {
        cout << "0 - exit" << endl;
        cout << "1 - Sum" << endl;
        cout << "2 - Diff" << endl;
        cout << "3 - Cos a b" << endl;
        cout << "4 - Skal" << endl;
        cout << "5 - Vectorn" << endl;
        
        while (true)
        {
            cout << "CHOOSE -> ";
            if (scanf_s("%d", &menu) != 1) {
               cout << "You must input only numbers" << endl;
                while (getchar() != '\n') {}
            }
            else {
                break;
            }
        }

        switch (menu)
        {
        case 1: {
            system("cls");
            PrintArrayA();
            PrintArrayB();
            Sum();
            
            break;
        }
        case 2: {
            system("cls");
            PrintArrayA();
            PrintArrayB();
          Diff();
            
            break;
        }
        case 3: {
            system("cls");
            PrintArrayA();
            PrintArrayB();
            Kos();
            
            break;
        }
        case 0: {
            exit(0);
            break;
        }
        case 4: {
            system("cls");
            PrintArrayA();
            PrintArrayB();
            Skal();
           
          break;
        }
        case 5: {
            system("cls");
            PrintArrayA();
            PrintArrayB();
           Vectorn();
            
            break;
       

        }
        default: {
            cout << "Input is wrong. Try again!" << endl;
            
         break;
       }


        }

    }
}



int main() // головна функц≥€
{
    
    CreateL();
    PrintArrayA();
    PrintArrayB();
    Vectora();
    Vectorb();
    PrintArrayA();
    PrintArrayB();
    Menu();
}

    
