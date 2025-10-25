#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>

// Tracker for memory leak testing

struct Tracker {
    static int created;
    static int destroyed;
    Tracker() { created++; }
    ~Tracker() { destroyed++; }
};

class TaskList {
public:
    // Constructor / Destructor / Copy / Assignment
    TaskList();
    ~TaskList();
    TaskList(const TaskList& other);
    TaskList& operator=(const TaskList& rhs);

    // Core functions
    bool empty() const;
    int size() const;
    void addBack(const std::string& task); // void addBack(const std::string& task);
    bool removeFront();
    bool get(int pos, std::string& task) const;
    int find(const std::string& task) const;
    void clear();
    void printAll() const;

private:
    struct Node {
        std::string data; //  std::string data;
        Node* prev;
        Node* next;
        Node(const std::string& d) : data(d), prev(nullptr), next(nullptr) {} // Node(const std::string& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int m_size;

    // Helper functions
    void copyList(const TaskList& other);
    void freeList();
    Node* getNode(int pos) const;
};

#endif // TASKLIST_H
