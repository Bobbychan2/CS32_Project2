#include "TaskList.h"
#include <iostream>

// ------------------------ C'tor, D'tor, AO, and CC ------------------------ //

TaskList::TaskList() : head(nullptr), tail(nullptr), m_size(0) {}


TaskList::~TaskList() {
    freeList();
}

TaskList::TaskList(const TaskList& other) : head(nullptr), tail(nullptr), m_size(0) {
    copyList(other);
}

TaskList& TaskList::operator=(const TaskList& rhs) {
    if (this != &rhs) {
        freeList();
        copyList(rhs);
    }
    return *this;
}

// ------------------------ Core functions ------------------------ //

bool TaskList::empty() const {
    return m_size == 0;
} // TODO: Return true if list is empty

int TaskList::size() const {
    return m_size; // TODO: Return actual size
}

void TaskList::addBack(const std::string& task) {
    Node* newNode = new Node(task);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    m_size++;
}

bool TaskList::removeFront() {
    if (empty()) return false;

    Node* temp = head;
    if (head == tail) { // Only one node
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    m_size--;
    return true;
}

bool TaskList::get(int pos, std::string& task) const {
    Node* node = getNode(pos);
    if (node == nullptr) return false;
    task = node->data;
    return true;
}

int TaskList::find(const std::string& task) const {
    Node* curr = head;
    int index = 0;
    while (curr != nullptr) {
        if (curr->data == task)
            return index;
        curr = curr->next;
        index++;
    }
    return -1; // Not found
}

void TaskList::clear() {
    freeList();
}

void TaskList::printAll() const {
    Node* curr = head;
    while (curr != nullptr) {
        std::cerr << curr->data << std::endl;
        curr = curr->next;
    }
}

// ------------------------ Helper Functions ------------------------ //

void TaskList::copyList(const TaskList& other) {
    Node* curr = other.head;
    while (curr != nullptr) {
        addBack(curr->data);
        curr = curr->next;
    }
}

void TaskList::freeList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
    m_size = 0;
}

TaskList::Node* TaskList::getNode(int pos) const {
    if (pos < 0 || pos >= m_size) return nullptr;
    Node* curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;
    return curr;
}