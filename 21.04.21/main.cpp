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
int* borders(int *arr, int size, int num)
{
    int *res;
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
    return res;
}