#include "iostream"
#include "main.cpp"
using namespace std;
//binomial heap lets you to sort a number of arrays
int main()
{
    BinomialHeap *heap = new BinomialHeap();
    int size = 54;
    int arr1[size];
    int arr2[size];
    int arr3[size];
    int res[size * 3];
    for (int i = 0; i < size; ++i)
    {
        arr1[i] = rand()%1000;
        arr2[i] = rand()%1000;
        arr3[i] = rand()%1000;

        heap->insert(new Node(arr1[i]));
        heap->insert(new Node(arr2[i]));
        heap->insert(new Node(arr3[i]));
    }
    int counter = 0;
    for (int i = 0; i < size*3; ++i)
    {
        res[i] = heap->extractMin();
        cout<< res[i]<< " ";
        counter++;
    }
    cout<<endl<<counter;

}