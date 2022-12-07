#pragma once

template <class T>
class ListNode {
private:
    ListNode* prev;
    ListNode* next;
    T data;
public:
    // Returns previous node value which is a pointer of ListNode class
    ListNode<T>* getPrevNode() {
        return this->prev;
    }

    // Returns next node value which is a pointer of ListNode class
    ListNode<T>* getNextNode() {
        return this->next;
    }

    // Returns node data which type is "T" that can be dynamic
    T getData() {
        return this->data;
    }

    T* getPData() {
        return &this->data;
    }

    // Sets previous node of current node which parameter should be a pointer
    //                                                              of ListNode
    void setPrevNode(ListNode<T>* node) {
        this->prev = node;
    }

    // Sets next node of current node which parameter should be a pointer
    //                                                              of ListNode
    void setNextNode(ListNode<T>* node) {
        this->next = node;
    }

    // Sets data of current node which type is "T" that can be dynamic
    void setData(T aData) {
        this->data = aData;
    }
};
