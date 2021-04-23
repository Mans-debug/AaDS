#include "iostream"
using namespace std;
int binarySearch(int *arr, int left, int right, int num)
{
    int middle = left + (right - left)/2;
    if(num == arr[middle])
        return middle;
    if(num > arr[middle])
        return binarySearch(arr, middle, right, num);
    if(num < arr[middle])
        return binarySearch(arr, left, middle, num);
}
string borders(int arr[21], int size, int num)
{
    int res[] = {0, 0};
    int begin = binarySearch(arr, 0 , size - 1, num);
    int temp = begin;
    while (true)
    {
        temp = binarySearch(arr, temp, size - 1, num);
        if(arr[temp + 1] != num)
            break;
    }
    res[1] = temp;
    temp = begin;
    while (true)
    {
        temp = binarySearch(arr, 0, temp, num);
        if(arr[temp - 1] != num)
            break;
    }
    res[0] = temp;
    string ret = to_string(res[0])+" " + to_string(res[1]);
    return ret;
}
int main()
{
    int arr[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3};
    string res = borders(arr, 21, 1);
    cout<<res;
}