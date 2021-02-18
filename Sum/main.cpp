#include <iostream>
using namespace std;

int sum(int size, int arr[])
{
    int sum = 0;
    for (int j = 0; j < size; ++j)
    {
        sum += arr[j];
    }
    return sum;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        cin>>arr[i];
    }
    cout<<sum(size, arr);
}