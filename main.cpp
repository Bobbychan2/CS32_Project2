#include "TaskList.h"
#include <iostream>
using namespace std;

int main() {
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