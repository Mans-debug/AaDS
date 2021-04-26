#include <list>
#include <set>
#include "iostream"
#include "vector"
#include "math.h"
#include "bits/stdc++.h"
using namespace std;
int fact(unsigned int n)
{
    int ret = 1;
    for (int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}
//страшно думать о том, какая алгоритмическая сложность о_О

//топорно? колхозно? ДА.
//зато работает :)
vector<int> getAllCombinations(int x)
{
    srand (time(NULL));
    int quantOfNumb = to_string(x).length();
    int arrOfNumb[quantOfNumb];
    set<int> combinations;
    vector<int> res;
    //добавляю все цифры из числа
    for (int i = 0; i < quantOfNumb; ++i)
    {
        arrOfNumb[i] = x % 10;
        x /= 10;
    }
    //ищу все комбинации числа
    for (int i = 0; i <fact(quantOfNumb); ++i)
    {
        //каждую итерацию заполняю вектор из которого потом
        //буду "вычеркивать" использованное число
        vector<int> tempVector;
        for(int k = 0; k < quantOfNumb;k++)
        tempVector.push_back(arrOfNumb[k]);

        int comb = 0;
        for (int j = quantOfNumb - 1; j >= 0 ; j--)
        {
            int random = rand()%tempVector.size();
            comb += tempVector.at(random) * pow(10 , j);
            tempVector.erase(tempVector.begin() + random);
        }

        //чет лень было думать над другим способом
        //составления комбинаций
        //сет нам нужен, чтобы удостовериться, что такого числа не было
        //таким образом цикл так и будет крутить пока воля рандома
        //не даст ему уникальную комбинацию
        int setSize = combinations.size();
        combinations.insert(comb);
        if(combinations.size() - setSize == 0)
        {
            i--;
            continue;
        }

        res.push_back(comb);
    }
    return res;
}
bool everyDayImShuffling(int a, int b, int c)
{
    vector<int> aCombs = getAllCombinations(a);
    vector<int> bCombs = getAllCombinations(b);
    //крч я пишу цикл, основываясь на том, что числа одинаковой длины
    //если надо будет, то можно переписать, это не так хард
    for (int i = 0; i < aCombs.size(); ++i)
    {
        for (int j = 0; j < bCombs.size(); ++j)
        {
            int sum = aCombs.at(i) + bCombs.at(j);
            if(sum == c)
                return true;
        }
    }
    return false;
}
int main()
{
    int a = 312;
    int b = 523;
    int c = 844;
    bool res = everyDayImShuffling(12,31,25);
    cout<<res;
}