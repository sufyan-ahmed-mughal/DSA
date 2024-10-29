#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currentVal = arr[i];
        int previousVal = i - 1;

        // Shift elements greater than currentVal one position ahead
        while (previousVal >= 0 && currentVal < arr[previousVal])
        {
            arr[previousVal + 1] = arr[previousVal];
            previousVal--;
        }
        arr[previousVal + 1] = currentVal;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortAndDisplay(int arr[], int n)
{
    cout << "Original Array: ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "Sorted Array (Insertion): ";
    display(arr, n);
}

int main()
{
    int nearlySortedArray[] = {1, 2, 3, 5, 4}; // Nearly sorted
    int unsortedArray[] = {9, 7, 5, 3, 1};     // Completely unsorted
    int randomArray[] = {4, 2, 9, 1, 5, 6, 3}; // Random array

    int n1 = sizeof(nearlySortedArray) / sizeof(nearlySortedArray[0]);
    int n2 = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
    int n3 = sizeof(randomArray) / sizeof(randomArray[0]);

    cout << "Testing with a nearly sorted array:" << endl;
    sortAndDisplay(nearlySortedArray, n1);

    cout << "Testing with a completely unsorted array:" << endl;
    sortAndDisplay(unsortedArray, n2);

    cout << "Testing with a random array:" << endl;
    sortAndDisplay(randomArray, n3);

    system("pause");
    return 0;
}
