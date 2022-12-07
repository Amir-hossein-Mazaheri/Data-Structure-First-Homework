/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Amirhossein Mazaheri
 * Date: 1401/9/15
 */

#pragma once

#include <string>
#include "Patient.h"
#include "ListNode.h"

using namespace std;


class List  {

private:

/* 
 * You can add more attributes to this class, 
 * but you cannot remove the attributes below 
 * nor can you change them.
 */

    // points to the first element in the list
    ListNode<Patient>* head;

    // points to the last element in the list
    ListNode<Patient>* tail;

    const int MAX_ELEMENTS = 1000;      // constant MAX_ELEMENTS
    int elementCount;                  // Number of elements in the data structure
    int capacity;                     // Actual maximum capacity of data structure

    // find the right place for adding the item and return the node that item should be inserted after
    // also used in insert to make sorted inserts
    ListNode<Patient>* findPlace(ListNode<Patient>* node);

public:

/* 
 * You can add more private methods to this class, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * Bottom line: you cannot change the public interface of this List class.
 * 
 */

    // this is a base for two constructor which holds common parts of them
    void baseConstructor();

    // Default constructor
    List();

    // constructor that sets the capacity and act like the List() constructor
    explicit List(int initCapacity);

    // Destructor
    // Description: Destruct a List object, releasing heap-allocated memory.
    ~List();

    // Description: Returns the total element count currently stored in List.
    int  getElementCount() const;

    // check that whether a patient is duplicate or not used in insert to stop
    // adding duplicate items
    bool isDuplicate(ListNode<Patient>* node);

    // Description: Insert an element.
    // Precondition: newElement must not already be in data collection.
    // Postcondition: newElement inserted and elementCount has been incremented.
    bool insert(const Patient& newElement);

    // Description: Remove an element.
    // Postcondition: toBeRemoved is removed and elementCount has been decremented.
    bool remove( const Patient& toBeRemoved );

    // Description: Remove all elements.
    void removeAll();

    // Description: Search for target element.
    //              Returns a pointer to the element if found,
    //              otherwise, returns NULL.
    Patient* search(const Patient& target);

    // Description: Prints all elements stored in List by descending order of search key.
    void printList();

}; // end List.h