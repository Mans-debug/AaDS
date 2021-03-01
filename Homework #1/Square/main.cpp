#include <iostream>
#include "math.h"

using namespace std;

void solve(double *arr)
{
    double D = -1;
    D = pow(arr[1], 2) - 4 * arr[0] * arr[2];
    if (D < 0)
        return ;
    else
    {
        double x1 = (-arr[1] + sqrt(D)) / 2 / arr[0];
        double x2 = (-arr[1] + sqrt(D)) / 2 / arr[0];

        cout<<x1<<" "<<x2;
    }
}
int main()
{
double arr[3];
for (int i = 0;i < 3; ++i)
{
cin >> arr[i];
}
solve(arr);
return 0;
}
