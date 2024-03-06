#include <iostream>

using namespace std;

// Inserting n into array at the next open position
// Length is the number of 'real' values in the array and capacity
// is the size (memory) allocated for the fixed size array
void insert(int arr[], int n, int length, int capacity) {
    if (length < capacity) {
        arr[length] = n;
    }
}

// Remove from the last position in the array if the array
// is not empty (length is non-zero)
void remove(int arr[], int length) {
    if (length > 0) {
        arr[length - 1] = 0;
    }
}

// Insert n into index i after shifting elements to the right
// Assuming i is a valid index and array is not full
void insertMiddle(int arr[], int i, int n, int length) {
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }
    arr[i] = n;
}

// Remove values at index i before shifting elements to the left
// Assuming i is a valid index
void removeMiddle(int arr[], int i, int length) {
    for (int index = i + 1; index < length; index++) {
        arr[index - 1] = arr[index];
    }
}

void printArr(int arr[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}