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

#include <iostream>
#include "List.h"

using namespace std;

void List::baseConstructor() {
    this->head = nullptr;
    this->tail = nullptr;

    this->elementCount = 0;
    this->capacity = this->MAX_ELEMENTS;
}

List::List() {
    this->baseConstructor();
};

List::List(int initCapacity) {
    this->baseConstructor();

    this->capacity = initCapacity;
}

List::~List() {
    this->removeAll();
}

int List::getElementCount() const {
    return this->elementCount;
}

bool List::isDuplicate(ListNode<Patient> *node) {
    // !this->elementCount is equal to this->elementCount == 0
    if (!this->elementCount) {
        return false;
    }

    ListNode<Patient> *tmp = this->head;

    while (tmp) {
        if (tmp->getData() == node->getData()) {
            return true;
        }

        tmp = tmp->getNextNode();
    }

    return false;
}

ListNode<Patient> *List::findPlace(ListNode<Patient> *node) {
    auto tmp = this->head;

    while (tmp) {
        if (node->getData().getCareCard() == "0000000000") break;

        auto a = stoll(tmp->getData().getCareCard());
        auto b = stoll(node->getData().getCareCard());
        long long c;

        if (tmp->getNextNode()) {
            c = stoll(tmp->getNextNode()->getData().getCareCard());
        } else {
            c = 0;
        }

        if (a > b && b > c) {
            return tmp;
        }

//        if(tmp->getData().getCareCard() > node->getData().getCareCard() && tmp->getNextNode()->getData().getCareCard() < node->getData().getCareCard()) {
//            return tmp;
//        }

        tmp = tmp->getNextNode();
    }

    return this->tail;
}

bool List::insert(const Patient &newElement) {
    auto newNode = new ListNode<Patient>();
    newNode->setData(newElement);

    newNode->setPrevNode(nullptr);
    newNode->setNextNode(nullptr);

    if (this->elementCount == this->capacity) {
        return false;
    }

    if (!this->head) {
        this->head = this->tail = newNode;

        this->elementCount++;

        return true;
    }

    if (this->isDuplicate(newNode)) {
        return false;
    }

    auto place = this->findPlace(newNode);

    if (place == this->tail) {

        this->tail->setNextNode(newNode);

        newNode->setPrevNode(this->tail);

        this->tail = newNode;

    } else {

        auto prevNode = place->getPrevNode();
        auto nextNode = place->getNextNode();

        newNode->setNextNode(nextNode);

        place->setNextNode(newNode);

        nextNode->setPrevNode(newNode);

        newNode->setPrevNode(place);
    }

    this->elementCount++;

    return true;
}

bool List::remove(const Patient &toBeRemoved) {
    auto tmp = this->head;

    while (tmp) {
        if (tmp->getData() == toBeRemoved) {

            auto nextNode = tmp->getNextNode();
            auto prevNode = tmp->getPrevNode();

            if (nextNode)
                nextNode->setPrevNode(prevNode);
            else {
                this->tail = prevNode;

                if (prevNode)
                    prevNode->setNextNode(nullptr);

            }

            if (prevNode)
                prevNode->setNextNode(nextNode);
            else {
                this->head = nextNode;

                if (nextNode)
                    nextNode->setPrevNode(nullptr);
            }

            if (this->elementCount == 1) {
                this->tail = this->head = nullptr;
            }

            tmp->setNextNode(nullptr);
            tmp->setPrevNode(nullptr);


            delete tmp;

            this->elementCount--;

            return true;
        }

        tmp = tmp->getNextNode();
    }

    return false;
}

void List::removeAll() {
    auto tmp = this->head;

    while (tmp) {
        auto nextNode = tmp->getNextNode();

        delete tmp;

        tmp = nullptr;

        tmp = nextNode;
    }

    this->tail = this->head = nullptr;

    this->elementCount = 0;
}

Patient *List::search(const Patient &target) {
    auto tmp = this->head;

    while (tmp) {
        if (tmp->getData() == target)
            return tmp->getPData();


        tmp = tmp->getNextNode();
    }

    return nullptr;
}

void List::printList() {
    auto tmp = this->head;

    while (tmp) {
        cout << "item: " << tmp->getData() << endl;

        tmp = tmp->getNextNode();
    }
}