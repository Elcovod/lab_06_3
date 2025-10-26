#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <climits>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

void print(int* arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int FindMin(int* arr, const int SIZE)
{
    int min = INT_MAX;
    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] % 2 != 0)
        {
            if (!found)
            {
                min = arr[i];
                found = true;
            }
            else if (arr[i] < min)
            {
                min = arr[i];
            }

        } 
    }
    return min;
}

template <typename T>
void SecondCreate(T* arr, int SIZE, T MIN, T MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

template <typename T>
void SecondPrint(T* arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T SecondFindMin(T *arr, int SIZE)
{
    T min = INT_MAX;
    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] % 2 != 0)
        {
            if (!found)
            {
                min = arr[i];
                found = true;
            }
            else if (arr[i] < min)
            {
                min = arr[i];
            }

        }
    }
    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int MIN, MAX, SIZE;

    cout << "¬вед≥ть розм≥р масиву (SIZE): "; cin >> SIZE;
    cout << "¬вед≥ть д≥апазон елемент≥в масиву (MIN): "; cin >> MIN;
    cout << "¬вед≥ть д≥апазон елемент≥в масиву (MAX): "; cin >> MAX;
    cout << endl;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    cout << "«генерований масив: ";
    print(arr, SIZE);

    int minResult = FindMin(arr, SIZE);

    if (minResult == INT_MAX)
    {
        cout << "¬ масив≥ немаЇ непарних елемент≥в, що задов≥льн€ють умову";
    }
    else
    {
        cout << "Minimal = " << minResult << endl;
    }

    delete[] arr;

    cout << "ѕерев≥рка шаблонних функц≥й" << endl;
    long* arrT = new long[SIZE];
    SecondCreate<long>(arrT, SIZE, (long)MIN, (long)MAX);

    cout << "«генерований масив: ";
    SecondPrint<long>(arrT, SIZE);


    long minResultT = SecondFindMin<long>(arrT, SIZE);
    if (minResultT == INT_MAX)
    {
        cout << "¬ масив≥ немаЇ непарних елемент≥в, що задов≥льн€ють умову";
    }
    else
    {
        cout << "Minimal = " << minResultT << endl;
    }

    delete[] arrT;
    return 0;
}