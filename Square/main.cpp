#include <iostream>
#include "math.h"

using namespace std;


double *squareOfArr(double arr[])
{
    static double sq[3];
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] >= 0)
            sq[i] = sqrt(arr[i]);
        else
            sq[i] = arr[i];
    }
    return sq;
}

void printArr(double arr[])
{
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] >= 0)
            cout << arr[i] << endl;
        else
            cout << "There is no square root for " << arr[i]<<endl;
    }
}

int main()
{
    double arr[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> arr[i];
    }
    printArr(squareOfArr(arr));
    return 0;
}
