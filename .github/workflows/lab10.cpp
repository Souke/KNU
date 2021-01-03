//Твердохліб Ангеліна ІПЗ 12 - 1 Лаб 10.
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


int Exams = 3;
int Sturcts = 10;
int CounterStrcuts = 0;



struct University { //структура Університет
    char Faculty[20];
    int Course;
    char Group[20];
    int NumberOfStudents;
    char Students[30][15];
    int Marks[30][10];
};

University* arr;
int courses[6] = { 0,0,0,0,0,0 };



void AddData() { // добавити студентів
    system("cls");
    char exit = ' ';

    while (tolower(exit) != 'e') {
        University univ;

        cout << "Faculty name: ";
        cin >> univ.Faculty;

        cout << "Course: ";
        cin >> univ.Course;

        cout << "Group name: ";
        cin >> univ.Group;

        cout << "Number of students in the group: ";
        cin >> univ.NumberOfStudents;

        for (int i = 0; i < univ.NumberOfStudents; i++) {
            cout << "Student name ";
            cin >> univ.Students[i];

            for (int j = 0; j < Exams; j++) {
                cout << "This student marks ";
                cin >> univ.Marks[i][j];
            }
        }
        arr[CounterStrcuts] = univ;
        CounterStrcuts++;
        cout << endl << "Press E to exit add data or other key to continue" << endl;
        exit = _getch();
        if (CounterStrcuts >= Sturcts) {
            cout << "You can't add more structs than " << Sturcts << endl;
            break;
            system("pause");
        }
    }

}

void PrintData() { // показати інформацію
    cout << "_____________________________________________________________________________" << endl;
    cout << setw(10) << "Faculty" << setw(10) << "Course" << setw(10) << "Group" << endl;

    for (int l = 0; l < CounterStrcuts; l++) {
        cout << "_____________________________________________________________________________" << endl;
        cout << setw(10) << arr[l].Faculty << setw(10) << arr[l].Course << setw(10) << arr[l].Group << setw(10) << endl;
        for (int j = 0; j < arr[l].NumberOfStudents; j++) {
            cout << setw(5) << "Student: " << setw(10) << arr[l].Students[j];
            for (int k = 0; k < Exams; k++)
                if (int(arr[l].Marks[j][k]) > 0)
                    cout << setw(6) << int(arr[l].Marks[j][k]);
            cout << endl;
        }
        cout << "_____________________________________________________________________________" << endl;
    }
}

void Excellent() { //відмінники
    int* stud = new int[Sturcts];
    for (int i = 0; i < Sturcts; i++) {
        stud[i] = 0;
    }

    for (int i = 0; i < Sturcts; i++) {
        for (int j = 0; j < arr[i].NumberOfStudents; j++) {
            bool flag = true;
            for (int k = 0; k < Exams; k++) {
                if (arr[i].Marks[j][k] < 4 && arr[i].Marks > 0)
                    flag = false;
            }
            if (flag)
                stud[i] = stud[i] + 1;
        }
    }
    int maxInd = 0, max = stud[0];
    for (int i = 0; i < Sturcts; i++) {
        if (stud[i] > max) {
            maxInd = i;
            max = stud[i];
        }
    }

    cout << arr[maxInd].Faculty << " has the largest number of excellent students" << endl;
    system("pause");
}

void RemoveStudent(int fidx, int sidx) { //виддалені студенти
    for (int i = sidx; i < arr[fidx].NumberOfStudents - 1; i++) {
        for (int k = 0; k < Exams; k++)
            arr[fidx].Marks[i][k] = arr[fidx].Marks[i + 1][k];
        for (int k = 0; k < 15; k++)
            arr[fidx].Students[i][k] = arr[fidx].Students[i + 1][k];

    }
    arr[fidx].NumberOfStudents = arr[fidx].NumberOfStudents - 1;
    courses[arr[fidx].Course - 1] = courses[arr[fidx].Course - 1] + 1;
}


void RemovedStudents() { // з якого курса виключені
    int maxInd = 0, max = courses[0];
    for (int i = 0; i < Sturcts; i++) {
        if (courses[i] > max) {
            maxInd = i;
            max = courses[i];
        }
    }

    cout << "The largest number of students was excluded from the course:  " << maxInd + 1 << endl;
}

void RemoveBadStudentFrom(const char* faculty) { //видалити студентів з ФІТА
    int flag = false;

    for (int i = 0; i < CounterStrcuts; i++) {
        if (strcmp(arr[i].Faculty, faculty) == 0) {
            flag = true;
            int countOfBadMarks = 0;
            for (int j = 0; j < arr[i].NumberOfStudents; j++) {
                countOfBadMarks = 0;
                for (int k = 0; k < Exams; k++) {
                    if (arr[i].Marks[j][k] < 3 && arr[i].Marks[j][k] > 0)
                        countOfBadMarks++;
                }
                if (countOfBadMarks >= 2) {
                    cout << arr[i].Students[j] << " has " << countOfBadMarks << " bad marks and was removed!" << endl;
                    RemoveStudent(i, j);
                }
            }
        }
    }

    if (!flag) {
        cout << "FIT Faculty doesn't exist." << endl;
    }
    system("pause");
}




int main() { //головна функція
  
    cout << "Exams < 10 : ";
    cin >> Exams;
    cout << endl;
    cout << "Structs: ";
    cin >> Sturcts;

    arr = new University[Sturcts];

    system("cls");

    while (true)
    {
        cout << "[1] Add student." << endl;
        cout << "[2] Delete bad students from FIT." << endl;
        cout << "[3] Excellent course" << endl;
        cout << "[4] Deleted Students." << endl;
        cout << "[5] Get information." << endl;
        cout << "[0] Exit" << endl;

        int key;
        cout << "Choose: ";
        cin >> key;

        switch (key)
        {
        case 1: {
            AddData();
            system("cls");
            break;
        }
        case 2: {
            RemoveBadStudentFrom("FIT");
            system("cls");
            break;
        }
        case 3: {
            Excellent();
            system("cls");
            break;
        }
        case 4: {
            RemovedStudents();
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            PrintData();
            system("pause");
            system("cls");
            break;
        }
        
        case 0: {
            exit(0);
        }
        default:
            break;
        }

    }
}