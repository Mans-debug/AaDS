#include "iostream"
using namespace std;
//пздц крутая рекурсия, правда?
int recursion(int m, int n)
{
    if(m == 0 || n == 0)
        return 1;

    return recursion(m-1, n) + recursion(m, n-1);
}
int main()
{
    //WARNING: массив n = 3 X m = 3 считать как n = 3 - 1 X m = 3 - 1
    int x = recursion(4,3);
    cout<<x;
}
