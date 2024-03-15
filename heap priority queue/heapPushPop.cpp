#include <vector>

using std::vector;


// Min Heap
class Heap {
public:
    vector<int> heap_;

    Heap() {
        heap_.push_back(0);
    }

    void push(int val) {
        heap_.push_back(val);
        int i = heap_.size() - 1;

        // Percolate up
        while (i > 1 && heap_[i] < heap_ [i / 2]) {
            int temp = heap_[i];
            heap_[i] = heap_[i / 2];
            heap_[i / 2] = temp;
            i = i / 2;
        }
    }

    int pop() {
        if (heap_.size() == 1) {
            return -1; // or throw an exception if heap is empty
        }

        if (heap_.size() == 2) {
            int res = heap_[heap_.size() - 1];
            heap_.pop_back();
            return res;
        }

        int res = heap_[1];
        // move last value to root
        heap_[1] = heap_[heap_.size() - 1];
        heap_.pop_back();

        // Percolate down
        int i = 1;
        while (2 * i < heap_.size()) {
            if (2 * i < heap_.size() && 
            heap_[2 * i + 1] < heap_[2 * i] &&
            heap_[i] > heap_[2 * i + 1]) {
                // swap right child
                int temp = heap_[i];
                heap_[i] = heap_[2 * i + 1];
                heap_[2 * i + 1] = temp;
                i = 2 * i + 1;
            } else if (heap_[i] > heap_[2 * i]) {
                // swap left child
                int temp = heap_[i];
                heap_[i] = heap_[2 * i];
                heap_[2 * i] = temp;
                i = 2 * i;
            } else {
                break;
            }
        }
        return res;
    }

    int top() {
        if (heap_.size() > 1) {
            return heap_[1];
        }

        return -1; // or throw an exception if heap is empty
    }
};
