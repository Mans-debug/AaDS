#include "iostream"

using namespace std;

long pathFinder(int lengthOfPath)
{
    long a = 0;
    long b = 1;
    long res = 0;
    for (int i = 0; i < lengthOfPath; ++i)
    {
        res = a + b;
        a = b;
        b = res;
    }
    return a;
}

int main()
{
    cout << pathFinder(60);
}