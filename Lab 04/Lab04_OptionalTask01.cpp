#include <iostream>
using namespace std;

// Function to perform rotated binary search on a rotated sorted array
int rotatedBinarySearch(int arr[], int size, int target) {
    int low = 0;           // Initialize low to the first index
    int high = size - 1;    // Initialize high to the last index

    // Continue searching as long as low index is less than or equal to high index
    while (low <= high) {
        // Calculate the mid-point to avoid overflow in large index values
        int mid = low + (high - low) / 2;

        // If the target is found at mid index return mid
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if the target is within the sorted left half
            if (target >= arr[low] && target <= arr[mid]) {
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;   // Search in the right half
            }
        }
        // If the right half is sorted
        else {
            // Check if the target is within the sorted right half
            if (target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;   // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    cout << "******Rotated Binary Search*****" << endl << endl;

    int size;
    // Get the size of the array from user
    cout << "Enter the size of array: ";
    cin >> size;

    // Dynamically allocate memory for the array based on the input size
    int *arr = new int[size];

    // Input the array elements from the user
    for (int i = 0; i < size; i++) {
        cout << "Enter the array element at index " << i << ": ";
        cin >> arr[i];
    }

    int target;
    // Get the value that user wants to search
    cout << "Enter the value to be searched: ";
    cin >> target;

    // Call the rotatedBinarySearch function and store the result 'result'
    int result = rotatedBinarySearch(arr, size , target);

    // Check if the target was found or not
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }

    // Free the dynamically allocated memory for the array
    delete[] arr;
    system("pause");
    return 0;
}
