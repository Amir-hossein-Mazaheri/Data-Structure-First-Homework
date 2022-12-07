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

bool List::insert(const Patient &newElement) {
    auto newNode = new ListNode<Patient>();
    newNode->setData(newElement);

    if (this->elementCount == this->capacity) {
        return false;
    }

    if (!this->head) {
        newNode->setPrevNode(nullptr);

        newNode->setNextNode(nullptr);

        this->head = this->tail = newNode;

        this->elementCount++;

        return true;
    }

    if (this->isDuplicate(newNode)) {
        return false;
    }

    this->tail->setNextNode(newNode);

    newNode->setPrevNode(this->tail);
    newNode->setNextNode(nullptr);

    this->tail = newNode;

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