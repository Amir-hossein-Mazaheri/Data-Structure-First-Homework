/*
 * Patient.h
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author: Amirhossein Mazaheri
 * Date: 1401/9/15
 */

#pragma once

template <class T>
class ListNode {
private:
    ListNode* prev;
    ListNode* next;
    T data;
public:
    // Returns previous node value which is a pointer of ListNode class
    ListNode<T>* getPrevNode() const {
        return this->prev;
    }

    // Returns next node value which is a pointer of ListNode class
    ListNode<T>* getNextNode() const {
        return this->next;
    }

    // Returns node data which type is "T" that can be dynamic
    T getData() const {
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
