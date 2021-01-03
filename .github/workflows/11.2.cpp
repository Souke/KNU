//Твердохліб Ангеліна ІПЗ 12-1 Лаб 11.2

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

// Налаштування
int countOfExams = 3;
int countOfSturcts = 10;
int CounterStrcuts = 0;


bool SaveInFile = true;
char File[20] = "data.txt";

struct University {
    char Faculty[20];
    int Course;
    char Group[20];
    int NumberOfStudents;
    char Students[30][15];
    int Marks[30][10];
};

University* arr;
int courses[6] = { 0,0,0,0,0,0 };



void AddData() { //додати студентів
    system("cls");
    char exit = ' ';

    while (tolower(exit) != 'e') {
        University univ;

        cout << "Input faculty name: ";
        cin >> univ.Faculty;

        cout << "Input course: ";
        cin >> univ.Course;

        cout << "Input group name: ";
        cin >> univ.Group;

        cout << "Input number of students in the group: ";
        cin >> univ.NumberOfStudents;

        for (int i = 0; i < univ.NumberOfStudents; i++) {
            cout << "Input student surname ";
            cin >> univ.Students[i];

            for (int j = 0; j < countOfExams; j++) {
                cout << "Input this student marks ";
                cin >> univ.Marks[i][j];
            }
        }
        arr[CounterStrcuts] = univ;
        CounterStrcuts++;
        cout << endl << "Press E to finish updating or any other key to continue" << endl;
        exit = _getch();
        if (CounterStrcuts >= countOfSturcts) {
            cout << "You can't add more structs than " << countOfSturcts << endl;
            break;
            system("pause");
        }
    }
    if (SaveInFile) {
        remove(File);
        fstream save(File, ios::binary | ios::out | ios::app);
        for (int i = 0; i < CounterStrcuts; i++)
            save.write(reinterpret_cast<char*>(&arr[i]), sizeof(University));

        save.close();
    }

}

void LoadFromFile() { //завантажити з файлу
    fstream input(File, ios::in | ios::binary | ios::ate);
    if (!input.is_open()) {
        cout << "File doesn'exist and can't be open" << endl;
        system("cls");
    }
    else {
        int size = input.tellg();
        University* u = new University[size];
        for (int i = 0; i < size / sizeof(University); i++) {
            input.seekg(i * sizeof(University));
            input.read(reinterpret_cast<char*>(&arr[i]), sizeof(University));
            CounterStrcuts = size / sizeof(University);

            cout << arr[i].NumberOfStudents << endl;
        }
    }
    input.close();
    cout << "Data was loaded" << endl;
    system("pause");
}

void PrintData() { //надрукувати інформацію
    cout << "=======================================================================" << endl;
    cout << setw(10) << "Faculty" << setw(10) << "Course" << setw(10) << "Group" << endl;

    for (int i = 0; i < CounterStrcuts; i++) {
        cout << "=======================================================================" << endl;
        cout << setw(10) << arr[i].Faculty << setw(10) << arr[i].Course << setw(10) << arr[i].Group << setw(10) << endl;
        for (int j = 0; j < arr[i].NumberOfStudents; j++) {
            cout << setw(5) << "Student: " << setw(10) << arr[i].Students[j];
            for (int k = 0; k < countOfExams; k++)
                if (int(arr[i].Marks[j][k]) > 0)
                    cout << setw(6) << int(arr[i].Marks[j][k]);
            cout << endl;
        }
        cout << "=======================================================================" << endl;
    }
}

void GetGoodFaculty() { //відмінники
    int* stud = new int[countOfSturcts];
    for (int i = 0; i < countOfSturcts; i++) {
        stud[i] = 0;
    }

    for (int i = 0; i < countOfSturcts; i++) {
        for (int j = 0; j < arr[i].NumberOfStudents; j++) {
            bool flag = true;
            for (int k = 0; k < countOfExams; k++) {
                if (arr[i].Marks[j][k] < 4 && arr[i].Marks > 0)
                    flag = false;
            }
            if (flag)
                stud[i] = stud[i] + 1;
        }
    }
    int maxInd = 0, max = stud[0];
    for (int i = 0; i < countOfSturcts; i++) {
        if (stud[i] > max) {
            maxInd = i;
            max = stud[i];
        }
    }

    cout << arr[maxInd].Faculty << " has the largest number of excellent students" << endl;
    system("pause");
}

void RemoveStudent(int fidx, int sidx) { //видаленні студенти
    for (int i = sidx; i < arr[fidx].NumberOfStudents - 1; i++) {
        for (int k = 0; k < countOfExams; k++)
            arr[fidx].Marks[i][k] = arr[fidx].Marks[i + 1][k];
        for (int k = 0; k < 15; k++)
            arr[fidx].Students[i][k] = arr[fidx].Students[i + 1][k];

    }
    arr[fidx].NumberOfStudents = arr[fidx].NumberOfStudents - 1;
    courses[arr[fidx].Course - 1] = courses[arr[fidx].Course - 1] + 1;
}


void RemovedStudents() { //який курс видаленно найбільше
    int maxInd = 0, max = courses[0];
    for (int i = 0; i < countOfSturcts; i++) {
        if (courses[i] > max) {
            maxInd = i;
            max = courses[i];
        }
    }

    cout << "The largest number of students (" << courses[maxInd] << ") was excluded from the course:  " << maxInd + 1 << endl;
}

void RemoveBadStudentFrom(const char* faculty) { //вилучені з ФІТу
    int flag = false;

    for (int i = 0; i < CounterStrcuts; i++) {
        if (strcmp(arr[i].Faculty, faculty) == 0) {
            flag = true;
            int countOfBadMarks = 0;
            for (int j = 0; j < arr[i].NumberOfStudents; j++) {
                countOfBadMarks = 0;
                for (int k = 0; k < countOfExams; k++) {
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
        cout << "FIT Faculty doesn't exist!!!" << endl;
    }
    system("pause");
}




int main() { //основна функція
    cout << "======= SETTINGS ===========" << endl;
    cout << "1. Count of exams < 10 : ";
    cin >> countOfExams;
    cout << endl;
    cout << "2. Count of structs: ";
    cin >> countOfSturcts;

    arr = new University[countOfSturcts];

    system("cls");

    while (true)
    {
        cout << "1. Add data." << endl;
        cout << "2. Remove bad students from FIT." << endl;
        cout << "3. Get Faculty." << endl;
        cout << "4. Removed Students." << endl;
        cout << "5. Print data." << endl;
        cout << "7. Save data in file." << endl;
        cout << "8. Remove data file." << endl;
        cout << "9. Load from file." << endl;
        cout << "0. Exit" << endl;

        int selector;
        cout << "Choose: ";
        cin >> selector;

        switch (selector)
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
            GetGoodFaculty();
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
        case 7: {
            remove(File);
            fstream save(File, ios::binary | ios::out | ios::app);
            for (int i = 0; i < CounterStrcuts; i++)
                save.write(reinterpret_cast<char*>(&arr[i]), sizeof(University));

            save.close();
            cout << "Saved" << endl;
            system("pause");
            system("cls");
        }
        case 8: {
            remove(File);
            cout << "File was removed!" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 9: {
            LoadFromFile();
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