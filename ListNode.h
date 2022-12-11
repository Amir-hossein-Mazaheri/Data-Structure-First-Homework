/*
 * ListNode.h
 *
 * Class Description: Models a Node of a list.
 * Class Invariant: - Double way node
 *                  - Can hold any data type due to its template syntax
 *                  - Abstract interface
 *
 * Author: Amirhossein Mazaheri
 * Date: 1401/9/15
 */

#pragma once

// Note: made this class template which I had to define methods definitions inside this header file
template<class T>
class ListNode {
private:
    ListNode *prev;
    ListNode *next;
    T data;
public:
    // Description: Returns previous node value which is a pointer of ListNode class
    ListNode<T> *getPrevNode() const {
        return this->prev;
    }

    // Description: Returns next node value which is a pointer of ListNode class
    ListNode<T> *getNextNode() const {
        return this->next;
    }

    // Description: Returns node data which type is "T" that can be dynamic
    T getData() const {
        return this->data;
    }

    // Description: Returns pointer to node data which type is "T*" that can be dynamic
    T *getPData() {
        return &this->data;
    }

    // Description: Sets previous node of current node which parameter should be a pointer
    //              of ListNode
    void setPrevNode(ListNode<T> *node) {
        this->prev = node;
    }

    // Description: Sets next node of current node which parameter should be a pointer
    //              of ListNode
    void setNextNode(ListNode<T> *node) {
        this->next = node;
    }

    // Description: Sets data of current node which type is "T" that can be dynamic
    void setData(T aData) {
        this->data = aData;
    }
};
