#include "iostream"

using namespace std;
//нахожу количество больших и меньших элементов с помощью бинарного поиска
int *BiggerLesserRow(int *arr, int size, int num)
{
    int left = 0;
    int right = size - 1;
    int middle = abs(left - right) / 2;
    int bigger = 0;
    int lesser = 0;

    while (true)
    {

        if (num > arr[middle])
        {
            int temp = middle;
            left = middle;
            middle += abs(left - right) / 2;
            if(temp == middle)
                middle +=1;
        }
        if (num < arr[middle])
        {
            int temp = middle;
            right = middle;
            middle -= abs(left - right) / 2;
            if(temp == middle)
                middle -=1;
        }

        if (num == arr[middle])
        {
            lesser += middle;
            bigger += size - middle - 1;
            break;
        }
        if (right - left == 1)
        {
            if(middle < num)
            {
                size--;
                lesser++;

            }

            bigger += size;
            break;
        };


    }
    int *res = new int[2];
    res[0] = lesser;
    res[1] = bigger;
    return res;

}

int fun(int (&matrix)[4][4], int n, int m)
{
    int lesser = 0;
    int bigger = 0;
    int min = INT16_MAX;
    int the_most_suitable = -666;
    //пробегаюсь по массиву и ищу наиболее подходящий элемент
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int *temp;
            int element = matrix[i][j];
            //нахожу для каждой строчки больше меньше
            for (int k = 0; k < n; ++k)
            {
                temp= BiggerLesserRow(matrix[k], m, element);
                lesser += temp[0];
                bigger += temp[1];
            }
            //нахожу наиболее подходящий элемент
            if(abs(bigger - lesser) < min)
            {
                min = abs(bigger - lesser);
                the_most_suitable = element;
            }
            lesser = 0;
            bigger = 0;
        }

    }
    return the_most_suitable;
}

int main()
{
    int n = 4, m = 4;
    int mat[4][4] = {
            4,6,8,9,
            1,4,5,6,
            2,4,7,10,
            4,6,8,9
    };
    int res = fun(mat, n , m);
    cout<<res;



}
