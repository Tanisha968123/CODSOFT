#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
private:
    vector<string> tasks;  // Store tasks as a dynamic array (vector)

public:
    // Function to add a task
    void addTask(const string& task) {
        tasks.push_back(task);  // Add the task to the list
        cout << "Task added successfully!" << endl;
    }

    // Function to display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty!" << endl;
            return;
        }

        cout << "Your To-Do List: " << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    // Function to delete a task
    void deleteTask(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number!" << endl;
        } else {
            tasks.erase(tasks.begin() + taskNumber - 1);  // Remove task from the list
            cout << "Task deleted successfully!" << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string task;
    int taskNumber;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after integer input

        switch (choice) {
            case 1:
                cout << "Enter the task to add: ";
                getline(cin, task);  // Get the task as a string (including spaces)
                todoList.addTask(task);
                break;
            case 2:
                todoList.displayTasks();
                break;
            case 3:
                todoList.displayTasks();
                cout << "Enter the task number to delete: ";
                cin >> taskNumber;
                todoList.deleteTask(taskNumber);
                break;
            case 4:
                cout << "Exiting the To-Do List program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
