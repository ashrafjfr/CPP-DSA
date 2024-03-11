/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Input: s = "()[]{}"
Output: true
*/

#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stackLeft;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stackLeft.push(s[i]);
            } else if (s[i] == ')') {
                if (!stackLeft.empty() && stackLeft.top() == '(') {
                    stackLeft.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!stackLeft.empty() && stackLeft.top() == '[') {
                    stackLeft.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!stackLeft.empty() && stackLeft.top() == '{') {
                    stackLeft.pop();
                } else {
                    return false;
                }
            }
        }

        return stackLeft.empty();
    }
};