class DoubleListNode {
public:
    int val_;
    DoubleListNode *next = nullptr;
    DoubleListNode *prev = nullptr;

    DoubleListNode(int val) {
        val_ = val;
    }
};

class MyLinkedList {
public:
    DoubleListNode *head;
    DoubleListNode *tail;

    MyLinkedList() {
        head = new DoubleListNode(-1);
        tail = new DoubleListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        DoubleListNode *curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
            if (curr == nullptr) {
                return -1;
            }
        }
        return curr->val_;
    }
    
    void addAtHead(int val) {
        DoubleListNode *newNode = new DoubleListNode(val);
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
    }
    
    void addAtTail(int val) {
        DoubleListNode *newNode = new DoubleListNode(val);
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
        DoubleListNode *curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
            if (curr == nullptr) {
                if (curr->prev == tail) {
                    addAtTail(val);
                } else {
                    return;
                }
            }
        }
        DoubleListNode *newNode = new DoubleListNode(val);
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        DoubleListNode *curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
            if (curr == nullptr) {
                return;
            }
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */