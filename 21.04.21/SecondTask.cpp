#include "iostream"

using namespace std;

int binarySearch(int *arr, int left, int right, int num)
{
    int middle = left + (right - left) / 2;
    if (num == arr[middle])
        return middle;
    if (right - left == 1)
        return -1;
    if (num > arr[middle])
        return binarySearch(arr, middle, right, num);
    if (num < arr[middle])
        return binarySearch(arr, left, middle, num);
}

bool fun(int (&matrix)[4][4], int n, int m, int num)
{
    int middle;
    int left = 0;
    int right = n - 1;
    while (true)
    {
        if (num > matrix[middle][m - 1])
        {
            left = middle;
            middle += (right - left) / 2;
        }
        if (num < matrix[middle][m - 1])
        {
            right = middle;
            middle -= (right - left) / 2;
        }
        if (num == matrix[middle][m - 1])
            return true;
        if (right - left == 1)
            break;
    }
    bool res1 = binarySearch(matrix[left], 0, m - 1, num) == -1 ? false : true;
    bool res2 = binarySearch(matrix[right], 0, m - 1, num) == -1 ? false : true;
    return res1 || res2;
}

int main()
{
    int n = 4, m = 4;
    int mat[4][4] = {
            4, 6, 8, 9,
            5, 10, 12, 14,
            7, 13, 17, 23,
            10, 18, 19, 30
    };
    bool res = fun(mat, n, m,17);
    cout << res;
}