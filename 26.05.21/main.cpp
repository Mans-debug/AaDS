#include "iostream"

using namespace std;

int *changeCalculator(int money)
{
    int changeTypes[] = {1, 5, 10};
    int *res = new int[3];
    for (int i = 0; i < 3; ++i)
    {
        res[i] = 0;
    }
    while (money > 0)
    {
        for (int i = 2; i >= 0; i--)
        {
            if (money - changeTypes[i] >= 0)
            {
                res[i]++;
                money -= changeTypes[i];
                break;
            }
        }
    }
    return res;
}

int main()
{
    int x = 26;
    int *arr = changeCalculator(x);
    for (int i = 0; i < 3; ++i)
    {
        cout << arr[i] << ' ';
    }
}