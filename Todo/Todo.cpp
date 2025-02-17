#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Main Task: create a program to record tasks by, read them from a file, and write
//          them to a file.
// Improvement: add functionality to complete a task.

// Add a task to the list
void addTask(vector<string> &tasks)
{
    string task; 
    cout << "Enter a task: ";
    cin.ignore(); // clears the input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << endl;
}


// Shows the list of tasks
void showTasks(const vector<string> &tasks)
{
    cout << "To-Do List:\n";
    for (int i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }

    cout << endl;
}

// Remove a completed task
void completedTask(vector<string> &tasks)
{
    int index;

    do
    {
        showTasks(tasks);
        cout << "Which task has been completed:";
        cin.ignore();
        cin >> index;
        if (index > 0  && index <= tasks.size())
        {
            tasks.erase(tasks.begin() + (index -1));
        } else  {
            cout << "Invalid input. Please enter a number between 1 and "
                << tasks.size() << endl;
        }
    } while (index <= 0 || index > tasks.size());

    cout << endl;

}

// Handle user interaction 
int main()
{
    vector<string>  tasks; // Vector to store the tasks
    string          task;  // String variable to
    char            choice;// User's choice

    // load existing tasks from file
    ifstream inputFile("tasks.txt");
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        cout << "A - Add a task\n";
        cout << "V - View tasks\n";
        cout << "C - Completed task\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 'A':
        case 'a':
            addTask(tasks);
            break;
        case 'V':
        case 'v':
            showTasks(tasks);
            break;
        case 'C':
        case 'c':
            completedTask(tasks);
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    // save tasks to file
    ofstream outputFile("tasks.txt");
    for (const auto &t :tasks)
    {
        outputFile << t << endl;
    }

    outputFile.close();

    return 0;


}