#include <vector>

using std::vector;

vector<int> insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        while (j >= 0 && arr[j + 1] < arr[j]) {
            int temp = arr[j+ 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    return arr;
}