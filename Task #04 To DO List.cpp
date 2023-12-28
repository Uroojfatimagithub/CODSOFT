#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
    } else {
        std::cout << "Task List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            std::cout << i + 1 << ". ";
            std::cout << (task.completed ? "[X] " : "[ ] ") << task.description << "\n";
        }
    }
}

void addTask(std::vector<Task>& tasks, const std::string& description) {
    tasks.push_back(Task(description)); // Use push_back instead of emplace_back
    std::cout << "Task added successfully.\n";
}

void markTaskAsCompleted(std::vector<Task>& tasks, int index) {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        tasks[static_cast<size_t>(index)].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

void removeTask(std::vector<Task>& tasks, int index) {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        tasks.erase(tasks.begin() + static_cast<size_t>(index));
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the buffer
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                int index;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter the task index to remove: ";
                std::cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
