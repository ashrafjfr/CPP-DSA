#include <iostream>

using std::cout;
using std::endl;

class ListNode {
public:
    int val_;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    ListNode(int val) {
        val_ = val;
    }
};

// Implementation of Doubly Linked List
class LinkedList {
public:
    ListNode* head;
    ListNode* tail;

    // Init the list with dummy node
    LinkedList() {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
    }

    void insertFront(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->prev = head;
        newNode->next = head->next;

        head->next->prev = newNode;
        head->next = newNode;
    }

    void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = tail;
        newNode->prev = tail->prev;

        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    // Remove first node after dummy head (assume exists)
    void removeFront() {
        head->next->next->prev = head;
        head->next = head->next->next;
    }

    // Remove last node before dummy tail (assume exists)
    void removeEnd() {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }

    void print() {
        ListNode* curr = head->next;
        while (curr!= tail) {
            cout << curr->val_ << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};