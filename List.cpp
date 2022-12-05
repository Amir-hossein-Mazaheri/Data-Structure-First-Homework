#include "List.h"

void List::baseConstructor() {
    this->head = new ListNode<Patient>();
    this->tail = new ListNode<Patient>();

    this->head->setPrevNode(nullptr);
    this->head->setNextNode(nullptr);

    this->tail->setPrevNode(nullptr);
    this->tail->setNextNode(nullptr);

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
    ListNode<Patient> *newNode = new ListNode<Patient>();
    newNode->setData(newElement);

    this->elementCount++;

    if (!this->head->getNextNode()) {
        newNode->setPrevNode(this->head);

        this->head->setNextNode(newNode);

        this->tail->setPrevNode(newNode);

        return true;
    }

    if (this->isDuplicate(newNode)) {
        return false;
    }

    newNode->setPrevNode(this->tail->getPrevNode());

    newNode->setNextNode(this->tail);

    this->tail->setPrevNode(newNode);

    return true;
}