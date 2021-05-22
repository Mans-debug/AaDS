#include <vector>
#include "iostream"
#include "algorithm"
//p.s. ненавижу плюсы
using namespace std;
bool comparator(vector<int> a, vector<int> b)
{
    return !(a[0] < b[0]);
}
void printSortedVector(vector<vector<int>> tasks)
{
    for (int i = 0; i < tasks.size(); ++i)
    {
        tasks[i][2] = i + 1;
    }
    sort(tasks.begin(), tasks.end(), comparator);
    for (int i = 0; i < tasks.size(); ++i)
    {
        cout<<tasks[i][2]<<" "<< tasks[i][0]<<" "<<tasks[i][1]<<endl;
    }
    cout<<endl;
}

void scheduler(int k, vector<vector<int>> tasks)
{
    for (int i = 0; i < tasks.size(); ++i)
    {
        tasks[i][2] = i + 1;
    }
    sort(tasks.begin(), tasks.end(), comparator);//сортируем по убыванию
    vector<int> days(5, -1);
    for (int i = 0; i < k; ++i)
    {
        while (tasks[i][1] >=1 && days[tasks[i][1] - 1] != -1)
            tasks[i][1]--;
        if(tasks[i][1] == 0)
            continue;
        days[tasks[i][1] - 1] = tasks[i][2];
    }

    for (int i = 0; i < days.size(); ++i)
    {
        cout<<days[i]<<" ";
    }

}

int main()
{
    vector<vector<int>> testInput =
            {
                    {4,  5},//1
                    {10, 5},//2
                    {12, 1},//3
                    {8,  4},//4
                    {1,  5},//5
            };
    printSortedVector(testInput);
    scheduler(5,testInput);
}
