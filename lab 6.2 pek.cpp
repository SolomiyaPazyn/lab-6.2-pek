#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <climits>
#include <iomanip>  
using namespace std;

void Init(int b[], const int size, int i = 0)
{
    if (i < size)
    {
        b[i] = -10 + rand() % 21;
        Init(b, size, i + 1);
    }
}

void Print(const int* const b, const int size, int i = 0)
{
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << b[i];
        if (i != size - 1)
            cout << ", ";
        else
            cout << "}" << endl;
        Print(b, size, i + 1);
    }
}

void FindMinMax(const int b[], const int size, int& min, int& max, int i = 0)
{
    if (i < size)
    {
        if (b[i] < min)
            min = b[i];
        if (b[i] > max)
            max = b[i];
        FindMinMax(b, size, min, max, i + 1);
    }
}

double AverageMinMax(const int b[], const int size)
{
    if (size == 0)
        return 0.0;
    int min = INT_MAX;
    int max = INT_MIN;
    FindMinMax(b, size, min, max);
    return (min + max) / 2.0;
}

int main()
{
    srand(time(0));
    int n;
    cout << "n = "; cin >> n;
    int* b = new int[n];
    Init(b, n);
    Print(b, n);
    double avg = AverageMinMax(b, n);
    cout << fixed << setprecision(1);  
    cout << "Arithmetic average min. and max. elements: " << avg << endl;
    
    delete[] b;
    b = nullptr;

    return 0;
}