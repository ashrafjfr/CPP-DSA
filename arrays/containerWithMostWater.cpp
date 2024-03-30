/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightNum = 0;
        int widthNum = 0;
        int area = 0;
        int maxArea = 0;
        int leftPtr = 0;
        int rightPtr = height.size() - 1;

        while (leftPtr < rightPtr) {
            if (height[leftPtr] < height[rightPtr]) {
                heightNum = height[leftPtr];
            } else {
                heightNum = height[rightPtr];
            }
            widthNum = rightPtr - leftPtr;
            area = heightNum * widthNum;
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[leftPtr] < height[rightPtr]) {
                leftPtr++;
            } else {
                rightPtr--;
            }
        }

        return maxArea;
    }
};