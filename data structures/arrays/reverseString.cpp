/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) {
            return;
        }

        // assign 2 pointers to front and back
        int front = 0;
        int back = s.size() - 1;

        // loop while pointers dont cross
        while (front < back) {
            // create temp holder for front pointer
            char temp = s[front];
            // swap end pointer with front pointer
            s[front] = s[back];
            // assign end pointer with temp
            s[back] = temp;
            // update front and back pointer
            front++;
            back--;
        }
    }
};