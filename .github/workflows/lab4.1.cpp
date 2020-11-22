#include <math.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

float y, st, x, xn, xk, xs, err, t;
bool flag = true;



double f_sq(double var)
{
    var -= 1;
    double q = 1, sum = 1;
    for (int n = 1; n <= 100; n++) {
        q *= (-1.0) * (2 * n - 1) * 2 * n * var / (n * n * 4);
        sum += q / (1.0 - 2 * n);
    }
    return sum;
}

int main(void)
{


    puts("lab 4:calculation exponention funtion");
    
    printf("\n input xmin xmax delta \n");
    cin >> xn >> xk >> xs;
    if (xn <= 1)
        cout << "Input number >1";
    else
    {
        printf("\n input t \n");
        cin >> t;


        printf("      x                 y         standart      error\n");
        for (x = xn; x <= xk; x += xs)
        {
            bool flag = true;
            if (-2 < x && x <= 0)
            {
                double y1, y2;
                y1 = f_sq(x - 1);
                y2 = f_sq(x + 1);
                if (y1 == 0 || y2 == 0)
                {
                    continue;
                }
                y = f_sq(x - 1) + f_sq(x + 1);
                st = sqrt(x - 1) + sqrt(x + 1);
                err = fabs(st - y);
            }
            else
                if (0 < x && x < 2)
                {
                    double nec;
                    nec = sqrt(pow(x, 2) - 1);
                    if (nec == 0) {
                        continue;
                    }
                    y = 1.0 / f_sq(pow(x, 2) - 1);
                    st = 1.0 / nec;
                    err = fabs(st - y);
                }
                else flag = false;

            if (flag == true) {
                printf("%f          %f        %f           %f \n", x, st, st, err);
            }
            else printf("  %f      not define    \n", x);
        }
    }
}