#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(12);

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

    long double a1 = ((ab * h) / 2.0L);

    long double a2 = ((theta * PI * (pow(r, 2.0))) / 360.0L);

    long double areaTotal = a1 + a2;

    // Ajuste manual para obter a precisão desejada
    areaTotal = round(areaTotal * 1e9) / 1e9;

    cout << areaTotal << endl;

    return 0;
}





