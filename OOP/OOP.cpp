#include <iostream>
#include <string>
using namespace std;

// Structure for a student
struct Student {
    string name;     // Student's first name
    string surname;  // Student's last name
    int age;         // Student's age
    double mark;     // Student's mark

    // Method to display student information
    void PrintInfoAboutStudent() {
        cout << "Student's name: " << name << endl;
        cout << "Student's surname: " << surname << endl;
        cout << "Student's age: " << age << endl;
        cout << "Student's mark: " << mark << endl;
    }

    // Method to change student information
    void ChangeInfoAboutStudent() {
        cout << "Enter a new name for the student: ";
        cin >> name;
        cout << "Enter a new surname for the student: ";
        cin >> surname;
        cout << "Enter a new age for the student: ";
        cin >> age;
        cout << "Enter a new mark for the student: ";
        cin >> mark;
    }
};

// Structure for a group
struct Group {
    Student* students;        // Dynamic array of students
    int amountOfStudents;     // Number of students in the group

    // Method to initialize the group
    void InitializeGroup(int size) {
        amountOfStudents = size;               // Set the number of students
        students = new Student[amountOfStudents]; // Allocate memory for students
        for (int i = 0; i < amountOfStudents; i++) {
            cout << "Enter details for student #" << i + 1 << ":" << endl;
            cout << "Name: ";
            cin >> students[i].name;
            cout << "Surname: ";
            cin >> students[i].surname;
            cout << "Age: ";
            cin >> students[i].age;
            cout << "Mark: ";
            cin >> students[i].mark;
        }
    }

    // Method to remove a student by index
    void RemoveStudent(int index) {
        if (index < 0 || index >= amountOfStudents) { // Check for a valid index
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < amountOfStudents - 1; i++) {
            students[i] = students[i + 1]; // Shift students to fill the gap
        }
        amountOfStudents--;  // Decrease the number of students
        cout << "Student removed successfully!" << endl;
    }

    // Method to rename a student by index
    void RenameStudent(int index) {
        if (index < 0 || index >= amountOfStudents) { // Check for a valid index
            cout << "Invalid index!" << endl;
            return;
        }
        cout << "Renaming student at index " << index << ":" << endl;
        students[index].ChangeInfoAboutStudent();
    }

    // Method to display all students in the group
    void PrintAllStudents() {
        for (int i = 0; i < amountOfStudents; i++) {
            cout << "Student #" << i + 1 << ":" << endl;
            students[i].PrintInfoAboutStudent();
            cout << endl;
        }
    }

    // Method to destroy the group and free memory
    void DestroyGroup() {
        delete[] students;  // Free the memory allocated for students
        students = nullptr; // Set the pointer to null
    }
};

int main() {
    Group group;

    // Initialize the group
    cout << "Enter the number of students in the group: ";
    int size;
    cin >> size;
    group.InitializeGroup(size);

    // Display all students
    cout << "\nAll students in the group:" << endl;
    group.PrintAllStudents();

    // Remove a student
    cout << "\nEnter the index of the student to remove (starting from 0): ";
    int indexToRemove;
    cin >> indexToRemove;
    group.RemoveStudent(indexToRemove);

    // Rename a student
    cout << "\nEnter the index of the student to rename (starting from 0): ";
    int indexToRename;
    cin >> indexToRename;
    group.RenameStudent(indexToRename);

    // Display all students after modifications
    cout << "\nAll students in the group after changes:" << endl;
    group.PrintAllStudents();

    // Destroy the group and free memory
    group.DestroyGroup();

    return 0;
}
