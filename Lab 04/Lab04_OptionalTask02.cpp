#include <iostream>
using namespace std;

// Recursive function for binary search
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    // Base case: if the search space is valid (left index is <= right index)
    if (left <= right) {
        // Calculate the mid-point of the current array or subarray
        int mid = left + (right - left) / 2;

        // If the target is found at the middle index, return the index
        if (arr[mid] == target)
            return mid;

        // If the target is smaller than the mid element, it can only be in the left subarray
        if (arr[mid] > target)
            return recursiveBinarySearch(arr, left, mid - 1, target);

        // If the target is larger, search in the right subarray
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }

    // If the target is not found in the array, return -1
    return -1;
}

int main() {
    cout << "******Recursive Binary Search*****" << endl << endl;

    int size;
    // Get the size of the array from the user
    cout << "Enter the size of array: ";
    cin >> size;

    // Dynamically allocate memory for the array based on the input size
    int *arr = new int[size];

    // Input the array elements from the user (the array must be sorted for binary search)
    cout << "Enter the values in sorted form (e.g., 1, 2, 3, 4, ...):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the array element at index " << i << ": ";
        cin >> arr[i];
    }

    int target;
    // Get the value the user wants to search for in the array
    cout << "Enter the value to be searched: ";
    cin >> target;

    // Call the recursiveBinarySearch function and store the result
    // The initial search space is from index 0 to size - 1
    int result = recursiveBinarySearch(arr, 0, size - 1, target);

    // Check if the target was found and print the appropriate message
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }

    // Free the dynamically allocated memory for the array
    delete[] arr;

    // Optional system pause (used mostly for Windows systems)
    system("pause");
    
    return 0;
}
