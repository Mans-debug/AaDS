#include <iostream>

using namespace std;

int log(double x)
{
    int power = 1;
    for (int i = 0;; ++i)
    {
        if (power > x)
        {
            power = i - 1;
            break;
        }
        if (power == x)
        {
            power = i;
            break;
        }
        power *= 2;
    }
    return power;
}

int main()
{
    double x;
    while (true)
    {
        cin >> x;
        cout << log(x)<<endl;
    }

    return 0;
}
