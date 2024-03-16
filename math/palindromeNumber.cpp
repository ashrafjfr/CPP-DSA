/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || ((x != 0) && (x % 10 == 0))) {
            return false;
        }
        // remove the last number % 10 -> 121 = 120 and 1
        // divide by 10 -> 120 = 12 
        // remove the last number % 10 -> 12 = 10 and 2
        // divide by 10 -> 10 = 1
        // remove the last number % 10 -> 1 = 1
        // divide by 10 -> 1 = 0
        long long n = 0;
        long long ans = x;
        while (x > 0) {
            n = (n * 10) + (x % 10);
            x /= 10;
        }
        if (n == ans) {
            return true;
        }
        return false;
    }
};