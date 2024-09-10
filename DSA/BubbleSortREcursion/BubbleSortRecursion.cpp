#include <iostream>
using namespace std;

void sortArray(int *arr, int size) {
    // Base case 
    if (size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    sortArray(arr, size - 1);
}

int main() {
    int size = 5;
    int arr[5]; // Use a constant value here

    for (int i = 0; i < size; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }

    // Print original array
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    sortArray(arr, size);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
