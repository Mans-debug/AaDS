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
    int x = recursion(4,4);
    cout<<x;
}
