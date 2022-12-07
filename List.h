/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Amirhossein Mazaheri
 * Date: (For you to fill)
 */

#pragma once

// You can add #include statements if you wish.
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

    ListNode<Patient>* head;
    ListNode<Patient>* tail;

    const int MAX_ELEMENTS = 1000;  // constant MAX_ELEMENTS
    // Data structure of elements
    int elementCount;                  // Number of elements in the data structure
    int capacity;                      // Actual maximum capacity of data structure

    ListNode<Patient>* findPlace(ListNode<Patient>* node);

public:

/* 
 * You can add more private methods to this class, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * Bottom line: you cannot change the public interface of this List class.
 * 
 */
    void baseConstructor();

    // Default constructor
    List();

    List(int initCapacity);

    // Destructor
    // Description: Destruct a List object, releasing heap-allocated memory.
    ~List();

    // Description: Returns the total element count currently stored in List.
    int  getElementCount() const;

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