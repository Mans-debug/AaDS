#include <iostream>
#include "cstdlib"

using namespace std;

void randArr(int *arr, int size)
{
    int rand();
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
    }

}

int sum(int *arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; ++i)
    {
        res += arr[i];
    }
    return res;
}

int *merge(int *a, int *b, int size1, int size2)
{
    int *res = new int[size1 + size2];
    for (int i = 0; i < size1 + size2; ++i)
    {
        if (i < size1)
        {
            res[i] = a[i];
        } else
        {
            res[i] = b[i - size1];
        }
    }

    delete a;
    delete b;

    return res;
}

void print(int *a, int size1)
{

    for (int i = 0; i < size1; ++i)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}

void sort(int *  arr, int size)
{
    for (int i = 0; i < size ; ++i)
    {
        for (int j = 0; j < size ; ++j)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1]  = temp;
                i = j;

            }
        }
    }
}

int main()
{
    //sum()
    int x;
    cin>>x;

    int arr[x];
    randArr(arr, x);

    cout<<"Sum of the array " << sum(arr,x)<<endl;
    //merge()
    int size1, size2;
    cin >> size1 >> size2;
    cout<<size1<<" "<< size2<<endl;
    int *a = new int [size1];
    int *b = new int [size2];

    randArr(a, size1);
    randArr(b, size2);

    cout << "The first array "<<endl;
    print(a, size1);

    cout<< "The second array "<<endl;
    print(b, size2);


    int * res = merge(a, b, size1, size2);
    cout<<"Merged array "<<endl;
    print(res , size1 + size2);

    //sort()
    cout<<"Sorted array "<<endl;
    sort(res, size1 + size2);
    print(res, size1 + size2);
    delete res;


    return 0;
}
