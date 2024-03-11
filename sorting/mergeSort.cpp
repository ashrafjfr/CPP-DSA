#include <vector>

using std::vector;

void merge(vector<int>& arr, int start, int middle, int end) {
    // Copy sorted left and right halfs to temp arrays
    vector<int> left = {arr.begin() + start, arr.begin() + middle + 1};
    vector<int> right = {arr.begin() + middle + 1, arr.begin() + end + 1};

    int i = 0;  // index for left
    int j = 0;  // index for right
    int k = start;  // index for merged array

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }
        k++;
    }

    // one of the halfs will have elements remaining
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

vector<int> mergeSort(vector<int>& arr, int start, int end) {
    if (end - start + 1 <= 1) {
        return arr;
    }

    // the middle index of the array
    int middle = (start + end) / 2;

    // sort the left half
    mergeSort(arr, start, middle);

    // sort the right half
    mergeSort(arr, middle + 1, end);

    // merge sorted halfs
    merge(arr, start, middle, end);

    return arr;
}