#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int cnt = 0;
void swap(int &x, int &y)
{
    cnt++;
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
    display(arr, n);
}

int getGap(int n)
{
    int g = (n * 10) / 13;

    return g <= 0 ? 1 : g;
}

void comb(int arr[], int n)
{
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped)
    {
        gap = getGap(gap);
        swapped = false;
        for (int i = 0; i + gap < n; i++)
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
    }
    display(arr, n);
}

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int elem = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > elem; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = elem;
    }
    display(arr, n);
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j, elem = arr[i];
            for (j = i; j >= gap && arr[j - gap] > elem; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = elem;
        }
    }
    display(arr, n);
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[low], i = low, j = high;

    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    } while (i < j);

    swap(arr[j], arr[low]);

    return j;
}

void quick(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);

        quick(arr, l, j);
        quick(arr, j + 1, h);
    }
}

int main()
{

    int arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, INT_MAX};

    int n = sizeof(arr) / sizeof(arr[0]);

    // shellSort(arr, n - 1);
    // quick(arr, 0, n - 1);
    // cnt = 0;
    // bubbleSort(arr, n);
    // cout << "Count after bubble => " << cnt << endl;

    // int arr2[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, INT_MAX};
    // cnt = 0;
    // comb(arr2, n - 1);
    // cout << "Count after comb => " << cnt << endl;

    // cnt = 0;
    // int arr3[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, INT_MAX};
    // shellSort(arr3, n - 1);
    // cout << "Count after shell => " << cnt << endl;
    insertion(arr, n - 1);
    // cout << endl;
    return 0;
}
