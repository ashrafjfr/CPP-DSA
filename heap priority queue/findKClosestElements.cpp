/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // initialise a result array
        // initialise a min heap containing a pair of diff and index
        // loop through arr to calculate diff between each element and x
            // push each diff into min heap
        // loop through while k 
            // insert element at index of top item in min heap
            // pop item from min heap
        // sort result
        // return result

        struct ComparePair {
            bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
                if (p1.first != p2.first) {
                    return p1.first > p2.first;
                }
                return p1.second > p2.second;
            }
        };

        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            pq.push(make_pair(diff, i));
        }
        while (k) {
            result.push_back(arr[pq.top().second]);
            pq.pop();
            k--;
        }
        sort(result.begin(), result.end());
        return result;
    }
};