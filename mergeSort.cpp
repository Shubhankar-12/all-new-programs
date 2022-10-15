#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[si + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = si;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int st, int end)
{
    if (st >= end)
        return;
    int mid = (st + end) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

void mergeSort(int arr[], int len)
{
    int st = 0, en = len + 1;
    mergeSort(arr, st, en);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
