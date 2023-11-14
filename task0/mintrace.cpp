#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mintrace(int x1, int y1, int x2, int y2)
{
    double r1 = hypot(x1, y1);
    double r2 = hypot(x2, y2);
    double a1 = atan2(y1, x1);
    double a2 = atan2(y2, x2);

    double angle = a1 - a2;
    if (angle < -M_PI)
        angle += 2 * M_PI;
    else if (angle > M_PI)
        angle -= 2 * M_PI;

    return min(abs(r1 - r2) + min(r1, r2) * abs(angle), r1 + r2);
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double min;

    if (x1 == 0 && y1 == 0)
        min = hypot(x2, y2);
    else if (x2 == 0 && y2 == 0)
        min = hypot(x1, y1);
    else
        min = mintrace(x1, y1, x2, y2);

    cout << fixed << setprecision(10) << min;

    return 0;
}
