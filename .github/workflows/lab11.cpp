//Твердохліб Ангеліна ІПЗ 12-1 ЛАБ 11
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <fstream>
#include < sstream >
using namespace std;

char str[256];
ofstream fout;
char new_namefile[] = "_new.txt";
int number_string = 0;
int smallerWordLength = 0;
int kilkist = 0;
  
void minMaxLengthWords(string str) { //коротше слово 
    
    int StrLength = str.length();
    int startIndex = 0, endIndex = 0;
    
    int minLength = StrLength, maxLength = 0, currentLength;
    string smallest;
    while (endIndex <= StrLength) {
        if (str[endIndex] != '\0' && str[endIndex] != ' ')
            endIndex++;
        else {
            currentLength = endIndex - startIndex;
            if (currentLength < minLength) {
                smallest = str.substr(startIndex, currentLength);
                minLength = currentLength;
            }
            kilkist++;
            endIndex++;
            startIndex = endIndex;
        }
    }
    cout << "Smallest Word from the string is " << smallest << "\n";
    cout << " Number of word is " << kilkist << "\n";
}

ofstream out;
int T;
void create_file(char* namefile) //створення файлу
{
    char answer;
    fout.open(namefile, ios::out);
    out.open(new_namefile, ios::out);
    cout << "String input: ";
    T = 0;
    do
    {
        getc(stdin);
        gets_s(str, 256);
        minMaxLengthWords(str);
        fout << str << endl;
        fout << kilkist << endl;
        
        out << smallerWordLength << str << endl;

        cout << "Continute? y/n" << endl;
        cin >> answer;
        T++;
    } while ((answer != 'n') && (answer != 'N'));

    out.close();
    fout.close();
}



int main() //основна функція
{
    char namefile[10];
    cout << "Enter a name of file: ";
    cin >> namefile;
    create_file(namefile);
    return 0;
}

