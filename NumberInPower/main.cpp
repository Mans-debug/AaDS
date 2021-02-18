#include <iostream>
using namespace std;
int power(int x, int p)
{
    int res = 1;
    for (int i = 0; i < p; ++i)
    {
        res*=x;
    }
    return res;
}
int main()
{
    int x;
    int p;
    while (true)
    {
        cin>>x>>p;
        cout<<power(x,p)<<endl;
    }
    return 0;
}
