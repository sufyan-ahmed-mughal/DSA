#include <iostream>
using namespace std;

// Function to search the element from the array using linear search
int linearSearch(int arr[], int size, int target)
{
    // Iterate through the array to search for the target
    for (int i = 0; i < size; i++)
    {
        // Checking the target match with Array or not
        if (target == arr[i])
        {
            // If the target is found return index
            return i;
        }
    }
    // If the target is not found return -1
    return -1;
}

int main()
{
    cout<<"******Linear Search*****"<<endl<<endl;
    // Declare variable to store size of the array
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    // Dynamically allocate memory for the array based on user input
    int *arr = new int[size];

    // Take input from the user to fill the array elements
    for (int i = 0; i < size; i++)
    {
        cout << endl
             << "Enter the array element at index: " << i << " ";
        cin >> arr[i];
    }

    // Take the input from user to search value
    int target;
    cout << "Enter the value to be Search: ";
    cin >> target;  

    // Call the linearSearch function
    int result = linearSearch(arr, size, target);

    // Check if the element was found or not
    if (result != -1)
    {
        cout << "Element " << target << " Found on Index: " << result << endl;
    }
    else
    {
        cout << "Element : " << target << " not Found" << endl;
    }
    system("pause");

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
