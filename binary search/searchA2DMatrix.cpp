/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // run binary search on the first column
        // find the first column value that is bigger than target
        // run binary search on the row
        // return true or false
        int left = 0;
        int right = matrix.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target > matrix[mid].back()) {
                left = mid + 1;
            } else if (target < matrix[mid][0]) {
                right = mid - 1;
            } else {
                break;
            }
        }
        if (!(left <= right)) {
            return false;
        }
        int innerLeft = 0;
        int innerRight = matrix[mid].size() - 1;
        while (innerLeft <= innerRight) {
            int innerMid = (innerLeft + innerRight) / 2;
            if (target > matrix[mid][innerMid]) {
                innerLeft = innerMid + 1;
            } else if (target < matrix[mid][innerMid]){
                innerRight = innerMid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};