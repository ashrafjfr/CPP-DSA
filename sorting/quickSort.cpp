#include <vector>

using std::vector;

vector<int> quickSort(vector<int>& arr, int start, int end) {
    if (end - start + 1 <= 1) {
        return arr;
    }

    int pivot = arr[end];
    int left = start;   // pointer for left side

    // partition: elements smaller than pivot on the left side
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            int temp = arr[left];
            arr[left] = arr[i];
            arr[i] = temp;
            left++;
        }
    }

    // move pivot in-between left and right sides
    arr[end] = arr[left];
    arr[left] = pivot;

    // quick sort left side
    quickSort(arr, start, left - 1);

    // quick sort right side
    quickSort(arr, left + 1, end);

    return arr;
}