#include <iostream>
#include <string>
#include <vector>
#include<cstdlib> // For system("pause") and system("cls")
using namespace std;
/*
* in my code we use:
     cin.ignore() before getline() to make sure that
     any leftover newline characters are cleared from the input buffer.
     This avoids issues where getline() might incorrectly read an empty line or not work as expected.


        system("pause");// Pause to allow user to see the message
        system("cls");  // Close the console window
*/
// Task struct to represent a task
struct Task {
    string name;
    string description;
    string dueDate;
    bool completed;

    // Mark the task as completed
    void markCompleted() { completed = true; }

    // Display task details
    /*
    Ì⁄ »— «Â„ ›«‰‘ﬂ‰ ›Ì «·ﬂÊœ ·«‰ »Ì „ «” œ⁄«∆Â« ›Ì ﬂ· «·›«‰ﬂ‘‰“
    ·⁄—÷  ›«’Ì· «· «”ﬂ«  «·„ Œ“‰…
    */
    void display() {
        cout << "   " << name << " (" << (completed ? "Completed" : "Pending")
            << ") \n - Due: " << dueDate << "\n   Description: " << description << endl;
    }
};

// ToDoList struct to manage a list of tasks
struct ToDoList {
    vector<Task> tasks; // Vector to store tasks



    // Display the menu
    void displayMenu() {
        system("color FD");// Set console color
        cout << "\t\t\t***********************************************************************" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
        cout << "1. Add Task\n2. Delete Task\n3. Display Tasks\n4. Mark Task as Completed\n5. Edit Task\n6. Exit\n";
    }

    // Add a new task
    void addTask() {
        Task newTask;
        cin.ignore();

        cout << "Enter task name: ";
        getline(cin, newTask.name);
        cout << "Enter task description: ";
        getline(cin, newTask.description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, newTask.dueDate);

        newTask.completed = false;                       // Initialize completed to false
        tasks.push_back(newTask);                        // Add the new task to the vector
        cout << "Task added successfully!" << endl;
        system("pause");
        system("cls");
    }

    /*
    Delete a task
     ›«‰ﬂ‘‰ ·Õ–›  «”ﬂ „⁄Ì‰
     No tasks to delete! ·Ê „›Ì‘ «Ì  «”ﬂ „÷«› ÂÌ—Ã⁄
     ·Ê ›ÌÂ  «”ﬂ«  „ Œ“‰… ÂÌÿ·» „‰ «·ÌÊ“— ÌŒ «— «· «”ﬂ «·–Ì Ì—€» ›Ì Õ–›Â.

    */
    void deleteTask() {
        if (tasks.empty()) {                     // Check if there are no tasks
            cout << "No tasks to delete!" << endl;
            return;
        }
        displayTasks();                           //if the vector is not empty display the existing tasks
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;                                    //Choose the number of task you want to delete
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {   //if the number exist it will be deleted
            tasks.erase(tasks.begin() + taskNumber - 1);       // Remove the task from the vector
            cout << "Task deleted successfully!" << endl;
        }
        else {                         //if the number not exist print
            cout << "Invalid task number!" << endl;
        }
        system("pause");
        system("cls");
    }


    /*
    Display all tasks
    ›«‰ﬂ‘‰ ·⁄—÷  ›«’Ì· «· «”ﬂ«  ⁄‰ ÿ—Ìﬁ «” œ⁄«¡ ›«‰ﬂ‘‰ «·⁄—÷ · task struct

    */
    void displayTasks() {

        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << "\n";
            tasks[i].display();   // Call display function of the Task struct
        }

        system("pause");

    }


    /*
    Mark a task as completed
     ›«‰ﬂ‘‰ ·Ã⁄· «· «”ﬂ „ﬂ „· ⁄‰ ÿ—Ìﬁ ⁄—÷ Ã„Ì⁄ «· «”ﬂ«  «·„ Œ“‰…
     Ê«·ÌÊ“— ÌŒ «— —ﬁ„ «· «”ﬂ «·–Ì Ì—Ìœ «‰ ÌÃ⁄·Â „ﬂ „·«

    */
    void markTaskCompleted() {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!" << endl;
            return;
        }
        displayTasks();
        cout << "Enter the task number to mark as completed: ";
        int taskNumber; cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
        system("pause");
        system("cls");
    }

    /*
     Edit a task
     (Edit task) ⁄‰œ «Œ Ì«— «·ÌÊ“— «Ê»‘‰
      »Ì „ ⁄—÷ Ã„Ì⁄ «· «”ﬂ«  «·„ Œ“‰…
     Ê«·ÌÊ“— Ì»œ« ›Ì «Œ Ì«— —ﬁ„ «· «”ﬂ «·–Ì Ì—Ìœ  ⁄œÌ·Â ÊÌ „ Õ›ŸÂ „Ãœœ«


    */

    void editTask() {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        displayTasks();
        cout << "Enter the task number to edit: ";
        int taskNumber; cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            Task& task = tasks[taskNumber - 1];  /* we use reference(&)to ensure that
                                                 your edits are applied directly to the task in the vector
                                                , reflecting immediately in your list. */
            cin.ignore();
            cout << "Enter new task name (current: " << task.name << "): ";
            getline(cin, task.name);
            cout << "Enter new task description (current: " << task.description << "): ";
            getline(cin, task.description);
            cout << "Enter new task due date (current: " << task.dueDate << "): ";
            getline(cin, task.dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
        system("pause");
        system("cls");
    }

    /*
    Run the to-do list application
     ›«‰ﬂ‘‰  ‘€Ì· «·»—‰«„Ã
     «Ê·«: »Ì „ ⁄—÷ ﬁ«∆„… «·«Œ Ì«—« 
     1.Add Tasks:
     2.Delete Tasks:
     3.Display Tasks:
     4.Mark Task as Completed:
     5.Edit Task:
     6.Exit:
     ⁄‰œ «Œ Ì«— «·ÌÊ“— «·—ﬁ„ «·–Ì Ì—ÌœÂ
     Ì „ «” œ⁄«¡ «·›«‰ﬂ‘‰ «·„„À·… ·Â–« «·—ﬁ„ Ê ‰›Ì–Â«

    */
    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1: addTask(); break;                     // Call addTask function
            case 2: deleteTask(); break;                 // Call deleteTask function
            case 3: displayTasks(); break;              // Call displayTasks function
            case 4: markTaskCompleted(); break;        // Call markTaskCompleted function
            case 5: editTask(); break;                // Call editTask function
            case 6: cout << "Exiting program. Bye!" << endl; break;
            default: cout << "Invalid choice. Please try again!" << endl;   // Handle invalid choices
            }
        } while (choice != 6);   // Repeat until user chooses to exit
    }
};

// Main function
int main() {
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
