#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;


double fun(float a, int n)
{
	cout << "("<<(a * a)<<"+"<< n << "/";
	return n == 512 ? (a * a) : (a * a) + n / fun(a, n * 2);
}

int main()
{
	float a;
	double res;
	int n = 2;
	cout << " LAB 4.2 Tverdokhlib Angelina IPZ 12";
	cout << "\n 1/a^2+2/a+a^4...a^2+256/a^2" << endl;
	cout << ("\n input a\n");
	cin >> a;

	if (a == 0)
		cout << "A!=0" << endl;
	else
	{
		cout << "1/";
		res = 1 / fun(a, n);

		cout << (a*a) <<")))))))))=" << res << endl;
	}
}
