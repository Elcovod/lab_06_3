#include <iostream>
#include <iomanip>
#include <climits>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void print(int* arr, int SIZE, int i)
{
    if (i < SIZE)
    {
        cout << arr[i] << ' ';
        print(arr, SIZE, ++i);
    }
}

int FindMin(int* arr, const int SIZE, int i, int curMin)
{
    if (i == SIZE)
    {
        return curMin;
    }
    if (arr[i] % 2 != 0)
    {
        if (arr[i] < curMin)
        {
            curMin = arr[i];
        }
    }
    return FindMin(arr, SIZE, i + 1, curMin);
}


template <typename T>
void SecondCreate(T* arr, int SIZE, T MIN, T MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        SecondCreate(arr, SIZE, MIN, MAX, ++i);
    }
}

template <typename T>
void SecondPrint(T* arr, int SIZE, int i)
{
    if (i < SIZE)
    {
        cout << arr[i] << ' ';
        SecondPrint(arr, SIZE, ++i);
    }
}

template <typename T>
T SecondFindMin(T* arr, const int SIZE, int i, T curMin)
{
    if (i == SIZE)
    {
        return curMin;
    }
    if (arr[i] % 2 != 0)
    {
        if (arr[i] < curMin)
        {
            curMin = arr[i];
        }
    }
    return SecondFindMin(arr, SIZE, i + 1, curMin);
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
    create(arr, SIZE, MIN, MAX, 0);

    cout << "«генерований масив: ";
    print(arr, SIZE, 0);
    cout << endl;

    int min = FindMin(arr, SIZE, 0, INT_MAX);

    if (min == INT_MAX)
        cerr << "ЌемаЇ елемент≥в, що задов≥льн€ють умову" << endl;
    else
        cout << "Min = " << min << endl;

    delete[] arr;


    cout << "ѕерев≥рка шаблонних функц≥й" << endl;
    long* arrT = new long[SIZE];
    SecondCreate<long>(arrT, SIZE, (long)MIN, (long)MAX, 0);

    cout << "«генерований масив: ";
    SecondPrint<long>(arrT, SIZE, 0);
    cout << endl;
    long minT = SecondFindMin(arrT, SIZE, 0, LONG_MAX);

    if (minT == LONG_MAX)
        cerr << "ЌемаЇ елемент≥в, що задов≥льн€ють умову" << endl;
    else
        cout << "Min = " << minT << endl;

    delete[] arrT;
    return 0;
}