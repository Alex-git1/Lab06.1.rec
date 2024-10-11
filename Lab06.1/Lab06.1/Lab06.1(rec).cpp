#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* p, const int size, const int Low, const int High, int i)
{
    p[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(p, size, Low, High, i + 1);
}

void Print(int* p, const int size, int i)
{
    cout << setw(4) << p[i];
    if (i < size - 1)
        Print(p, size, i + 1);
    else
        cout << endl;
}

int CountElements(int* p, const int size, int i, int& count_element)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
        {
            count_element++;
        }
        return CountElements(p, size, i + 1, count_element);
    }
    return count_element;
}

int SumElements(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
        {
            return p[i] + SumElements(p, size, i + 1);
        }
        else
        {
            return SumElements(p, size, i + 1);
        }
    }
    return 0;
}

void ReplaceElements(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
        {
            p[i] = 0;
        }
        ReplaceElements(p, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 24;  
    int p[n];    
    int Low = -10; 
    int High = 14;    
    int count_element = 0;  

    Create(p, n, Low, High, 0);
    Print(p, n, 0);

    int sum = SumElements(p, n, 0);
    cout << "Sum of elements = " << sum << endl;

    CountElements(p, n, 0, count_element);
    cout << "Count of elements = " << count_element << endl;

    ReplaceElements(p, n, 0);

    Print(p, n, 0);

    return 0;
}
