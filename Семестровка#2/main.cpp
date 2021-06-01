#include <iostream>
#include "string"
#include "cmath"
#include <algorithm>
#include <cctype>
#include "ctime"
#include "fstream"

using namespace std;

// P - длина текста, n - длина подстроки,
// M - просто по сути рандомное число, чтобы не пошли отрицательные числа в хэше
/*int getHash(string n, int P)
{
    //6:43
    const int M = 10000000;
    long res = 0;
    for (int i = 0; i < n.size(); ++i)
    {
        res += ((int) n.at(i) * (int) pow(P, n.length() - i - 1)) % M;
    }
    return res;
}*/
int getHash(string n, int P)
{
    //6:43
    const int M = 10000000;
    long long res = 0;
    int T = 53;
    for (int i = 0; i < n.size(); ++i)
    {
        res += ((int) n.at(i) * (int) pow(P, n.length() - i - 1)) % M;
    }
    return res;
}

unsigned long changeHash(unsigned long oldHash, unsigned long P, int oldSymb, int newSymb, unsigned long n)
{
    int T = 53;
    const int M = 10000000;
    oldHash -= (oldSymb * (int) pow(P, n - 1)) % M;
    oldHash *= P;
    oldHash += newSymb;
    return oldHash;
}

long RBAlg(string str, string substring)
{

    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c) { return tolower(c); });
    transform(substring.begin(), substring.end(), substring.begin(),
              [](unsigned char c) { return tolower(c); });

    unsigned long hash = 0;
    unsigned long substrHash = getHash(substring, str.length());
    long iterCounter = 0;
    for (int i = 0, j = 0; i < str.length();)
    {

        if (i == 0)
        {
            hash = getHash(str.substr(0, substring.length()), str.length());
            i += substring.length();
        } else
        {
            hash = changeHash(hash, str.length(), (int) str.at(j), (int) str.at(i), substring.length());
            i++;
            j++;
        }
        if (hash == substrHash)
            cout << j << " " << i - 1 << endl;
        iterCounter++;
    }
    return iterCounter;
}

void write(string path, string text)
{
    string prefix = "C:\\Users\\mansu\\CLionProjects\\AaDS\\Семестровка#2\\Result\\";
    ofstream fout;
    fout.open(prefix + path, ofstream::app);
    fout << text << endl;
    fout.close();
}

string read(string path)
{
    string prefix = "C:\\Users\\mansu\\CLionProjects\\AaDS\\Семестровка#2\\SourceFiles\\";
    ifstream fin(prefix + path);
    string chars;
    getline(fin , chars);
    write("chars.txt", chars);
    string ret;
    getline(fin, ret);
    fin.close();
    return ret;
}

int main()
{
    for (int i = 1; i < 8; ++i)
    {
        string str = read(to_string(i)+".txt");
        string substring;
        cin>>substring;
        double start = clock();
        long x = RBAlg(str, substring);
        double end = clock();
        write("iterations.txt", to_string(x));
        write("time.txt", to_string(end - start));
    }
}