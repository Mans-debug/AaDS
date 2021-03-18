//MAX HEAP
#include <iostream>
#include "math.h"
using namespace std;

struct MaxHeap
{
    int *array = 0;
    int size = 0;
    int maxSize = 0;


    void createNewArr(int maxSize)
    {
        int *res = new int[maxSize];
        if (maxSize > 1)
        {
            for (int i = 0; i < this->size; ++i)
            {
                int x = array[i];
                res[i] = array[i];
            }
        }

        delete[] array;
        array = res;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return i * 2 + 1;
    }

    int rightChild(int i)
    {
        return i * 2 + 2;
    }

    void siftUp(int i)
    {
        while ((i > 0) && (array[i] > array[parent(i)]))
        {
            int temp = array[i];
            array[i] = array[parent(i)];
            array[parent(i)] = temp;
            i = parent(i);
        }
    }

    void siftDown(int i)
    {
        int maxIndex = i;

        if (leftChild(i) < size && array[leftChild(i)] > array[i])
            maxIndex = leftChild(i);
        if (rightChild(i) < size && array[rightChild(i)] > array[maxIndex])
            maxIndex = rightChild(i);
        if (maxIndex != i)
        {
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
            siftDown(maxIndex);
        }
    }

    void insert(int value)
    {
        if (size < maxSize)
        {
            size++;
        } else
        {
            maxSize = maxSize * 2 + 1;
            createNewArr(maxSize);
            size++;
        }
        array[size - 1] = value;
        siftUp(size - 1);
    }

    int extractMax()
    {
        int res = array[0];
        array[0] = array[size - 1];
        size--;
        siftDown(0);
        return res;
    }

    int getMax()
    {
        return array[0];
    }

    static int *sort(int *array, int size)
    {
        MaxHeap heap;
        for (int i = 0; i < size; ++i)
        {
            heap.insert(array[i]);
        }
        int *res = new int[size];
        for (int i = size - 1; i > -1; --i)
        {
            res[i] = heap.extractMax();
        }
        delete [] array;
        return res;
    }

};

int *randArr(int size, int limit)
{
    int *arr;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % limit;
    }
    return arr;
}

int main()
{
    MaxHeap heap;
    int size = 21;
    int *array = new int[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = random()%1000;
    }
    array = MaxHeap::sort(array, size);
    for (int i = 0; i < size; ++i)
    {
        cout<<array[i]<<' ';
    }


    return 0;
}
