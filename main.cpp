#include "TaskList.h"
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int main() {

    // ------------------- Edge cases ------------------- //
    
    {
        std::cerr << "[Edge Case 1] Adding and removing from an empty list\n";

        TaskList list;

        // Initially empty
        std::cerr << "List empty? " << (list.empty() ? "Yes" : "No") << "\n";
        std::cerr << "Initial size: " << list.size() << "\n";

        // Attempt to remove from an empty list
        bool removed = list.removeFront();
        std::cerr << "Attempted removeFront() on empty list. Success? "
            << (removed ? "Yes" : "No") << "\n";

        // Add a single task, then remove it
        list.addBack("Task 1");
        std::cerr << "Added 'Task 1'. Size now: " << list.size() << "\n";

        list.removeFront();
        std::cerr << "Removed front. List empty now? "
            << (list.empty() ? "Yes" : "No") << "\n\n";
    }

    {
        std::cerr << "[Edge Case 2] Getting(finding) invalid positions\n";

        TaskList list;
        list.addBack("Task A");
        list.addBack("Task B");
        list.addBack("Task C");

        std::string task;
        bool got;

        // Try to get a task at a negative position
        got = list.get(-1, task);
        std::cerr << "Get(-1): " << (got ? "Found" : "Invalid") << "\n";

        // Try to get a task beyond the end of the list
        got = list.get(5, task);
        std::cerr << "Get(5): " << (got ? "Found" : "Invalid") << "\n";

        // Try to find a task that doesn’t exist
        int pos = list.find("Nonexistent Task");
        std::cerr << "Find('Nonexistent Task'): "
            << (pos == -1 ? "Not found" : "Found at " + std::to_string(pos)) << "\n\n";
    }

    {
        std::cerr << "[Edge Case 3] Copying and assigning lists of different sizes\n";

        TaskList list1;
        list1.addBack("Task 1");
        list1.addBack("Task 2");

        TaskList list2;
        list2.addBack("A");
        list2.addBack("B");
        list2.addBack("C");
        list2.addBack("D");

        // Copy constructor test
        TaskList copyList(list1);
        std::cerr << "Created copyList from list1 using copy constructor.\n";
        std::cerr << "Original list1 size: " << list1.size()
            << " | Copied list size: " << copyList.size() << "\n";

        // Modify copyList and check list1 unaffected
        copyList.addBack("Extra");
        std::cerr << "Added 'Extra' to copyList.\n";
        std::cerr << "list1 size: " << list1.size()
            << " | copyList size: " << copyList.size() << "\n";

        // Assignment operator test (different sizes)
        list1 = list2;
        std::cerr << "Assigned list2 to list1 using the equal operator.\n";
        std::cerr << "list1 size after assignment: " << list1.size() << "\n";
        std::cerr << "Expected size (same as list2): " << list2.size() << "\n\n";
    }

    
    TaskList tasks;

    cerr << "Adding tasks...\n";
    tasks.addBack("Reply to client emails");
    tasks.addBack("Finish history essay");
    tasks.addBack("Study for math quiz");
    tasks.printAll();

    cerr << "\nSize: " << tasks.size() << endl;

    cerr << "\nFinding 'Study for math quiz': " << tasks.find("Study for math quiz") << endl;
    cerr << "Finding 'Walk dog': " << tasks.find("Walk dog") << endl;

    string task;
    if (tasks.get(0, task))
        cerr << "\nFirst task: " << task << endl;

    cerr << "\nRemoving front task...\n";
    tasks.removeFront();
    tasks.printAll();

    cerr << "\nClearing list...\n";
    tasks.clear();
    cerr << "Empty: " << tasks.empty() << endl;

    cerr << "\nTesting copy constructor...\n";
    tasks.addBack("Task A");
    tasks.addBack("Task B");
    TaskList copy(tasks);
    copy.printAll();

    cerr << "\nTesting assignment operator...\n";
    TaskList assigned;
    assigned = tasks;
    assigned.printAll();

    return 0;

}