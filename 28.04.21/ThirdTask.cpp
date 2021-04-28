#include "iostream"
using namespace std;
//пздц крутая рекурсия, правда?

//хорошая рекурсия, но слишком медленная
//базовая версия задания, работает на небольших массивах (до ~ 15X15) за небольшое время
//не расходуя память
int recursion(long l, long k)
{
    if(l == 0 || k == 0)
        return 1;

    return recursion(l - 1, k) + recursion(l, k - 1);
}

// newRecursion и wrapper вместе работают за умеренное время, но алгоритм требует много памяти
//начало модификации
const long m = 100;
const long n = 100;
long long matrix[m][n];
int newRecursion(long l, long k)
{
    if(l == 0 || k == 0)
        return 1;
    if(matrix[l][k] != 0)
        return matrix[l][k];
    matrix[l][k] = newRecursion(l - 1, k) + newRecursion(l, k - 1);
    return matrix[l][k];
}
int wrapper()
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = 0;
        }
    }
    return newRecursion(m, n);
}
//конец модификации
int main()
{
    //WARNING: массив n = 3 X m = 3 считать как n = 3 - 1 X m = 3 - 1
    long long x = wrapper();
    cout<<x<<endl;
    cout<<recursion(5,5);

}
