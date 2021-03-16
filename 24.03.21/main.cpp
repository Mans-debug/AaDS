//MAX HEAP
#include <iostream>

using namespace std;

struct MaxHeap
{
    int *array;
    int size = 0;
    int maxSize = 0;


    void createNewArr()
    {
        int res[maxSize];
        for (int i = 0; i < size; ++i)
        {
            res[i] = array[0];
        }
        array = res;//как удалить предыдущий массив?
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
        while ((i > 1) && (array[i] > array[parent(i)]))
        {
            int temp = array[i];
            array[i] = array[parent(i)];
            array[i] = temp;
            i = parent(i);
        }
    }

    void siftDown(int i)
    {
        int maxIndex = i;
        while (i < size - 2)
        {
            if ((array[i] > rightChild(i)) && (array[i] > leftChild(i)))
            {
                return;
            } else
            {
                if (rightChild(i) > leftChild(i))
                    maxIndex = rightChild(i);
                else
                    maxIndex = leftChild(i);
            }
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
            i = maxIndex;
        }
    }

    void insert(int value)
    {
        if (size < maxSize)
        {
            size++;
        }
        else
        {
            if(maxSize == 0)
                maxSize++;
            maxSize *= 2;
            createNewArr();
            size++;
        }
        array[size - 1] = value;
        siftUp(size - 1);
    }

    int extractMax()
    {
        int res = array[0];
        array[0] = array[size - 1];
        array[size - 1] = res;
        if (size - 1 <= maxSize / 2)
        {
            maxSize /= 2;
            size--;
        } else
            size--;
        siftDown(0);
        return res;
    }

    int getMax()
    {
        return array[0];
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

    return 0;
}
