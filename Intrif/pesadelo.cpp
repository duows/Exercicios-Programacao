#include <iostream>
#include <math.h>
#include <tgmath.h>
#include <iomanip>

using namespace std;

// #define PI 3.1415926535897932384

// 452617


int main()
{

    long double PI = 3.14159265358979323846L;

    int r;
    cin >> r;

    if (r < 1 || r > 100)
    {
        return 0;
    }

    long double azinho = 36.869897645L;

    long double theta = 73.739795266608263933829256231553122024909673218277166042005784900L;

    long double alpha = (r / 2.0L);
    long double x = (r * 2.0L);
    long double y = (5.0L * alpha);
    long double z = (3.0L * alpha);

    long double ab = (pow(x, 2.0L) / y);

    long double h = sqrt((pow(r, 2.0L)) - ((pow(ab, 2.0L)) / 4.0L));

    /*

    55.051554320147
    55.051554320147

    */

    cout << fixed << setprecision(12);

    long double a1 = ((ab * h) / 2.0L);

    long double a2 = ((theta * PI * (pow(r, 2.0))) / 360.0L);

    long double areaTotal = a1 + a2;

    cout << areaTotal << endl;

    return 0;
}