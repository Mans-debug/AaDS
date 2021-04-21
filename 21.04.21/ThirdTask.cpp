#include "iostream"
using namespace std;

int fun(int num)
{
    int middle;
    int left = 0;
    int right = num/2;
    while (true)
    {
        if (num > middle*middle)
        {
            left = middle;
            middle += (right - left) / 2;
        }
        if (num < middle*middle)
        {
            right = middle;
            middle -= (right - left) / 2;
        }
        if (num == middle*middle)
            return middle;
        if(right - left == 1)
        {
            if(abs(num - right*right) > abs(num - left*left))
                return left;
            return right;
        }
    }

}
int main()
{
    cout<<fun(5);
}