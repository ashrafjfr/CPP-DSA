/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <stack>

using std::stack;

class MinStack {
public:
    stack<int> stack_;
    stack<int> minStack_;
    int minItem;

    MinStack() {}
    
    void push(int val) {
        if (stack_.empty()) {
            minItem = val;
            stack_.push(val);
            minStack_.push(minItem);
        } else if (!stack_.empty() && val <= minItem) {
            minItem = val;
            stack_.push(val);
            minStack_.push(minItem);
        } else if (!stack_.empty() && val > minItem) {
            stack_.push(val);
            minStack_.push(minItem);
        }
    }
    
    void pop() {
        stack_.pop();
        minStack_.pop();
        if (!minStack_.empty()) {
            minItem = minStack_.top();
        } else {
            minItem = 0;
        }
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return minStack_.top();
    }
};