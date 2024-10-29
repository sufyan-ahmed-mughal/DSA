#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int counter = 1;

    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
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
    bubbleSort(arr, n);
    cout << "Sorted Array (Bubble): ";
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
