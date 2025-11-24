#include <iostream>
using namespace std;

void arr(int arr[], int i)
{
    cout << "enter array : " << endl;
    for (int t = 0; t < i; t++)
    {

        cin >> arr[t];
    }
}

void printArray(int arr[], int i)
{
    cout << "the array is: " << endl;
    for (int t = 0; t < i; t++)
    {

        cout << arr[t] << " ";
    }
    cout << endl;
}

void sum(int arr1[], int arr2[], int i)
{
    int arraySum[100];
    cout << "the sum of given arrays is: " << endl;
    for (int x = 0; x < i; x++)
    {
        arraySum[x] = arr1[x] + arr2[x];
        cout << arraySum[x] << " ";
    }
    cout << endl;
}

void sub(int arr1[], int arr2[], int i)
{
    int arraySub[100];
    cout << "the sub of given arrays is: " << endl;
    for (int x = 0; x < i; x++)
    {
        arraySub[x] = arr1[x] + arr2[x];
        cout << arraySub[x] << " ";
    }
    cout << endl;
}

int main()
{
    int i;
    cout << "enter no of elements: " << endl;
    cin >> i;
    int arr1[100];
    int arr2[100];
    arr(arr1, i);
    printArray(arr1, i);
    arr(arr2, i);
    printArray(arr2, i);
    sum(arr1, arr2, i);
    sub(arr1, arr2, i);
}