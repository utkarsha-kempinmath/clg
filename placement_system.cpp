#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string branch;
    float cgpa;
    Student* next;
};

class PlacementSystem {
private:
    Student* head;

public:
    PlacementSystem() { head = nullptr; }

    // Insert new student
    void insertStudent(int id, string name, string branch, float cgpa) {
        Student* newStudent = new Student{id, name, branch, cgpa, nullptr};
        if (!head) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newStudent;
        }
        cout << "Student inserted successfully!\n";
    }

    // Display all students
    void displayStudents() {
        if (!head) {
            cout << "No records found.\n";
            return;
        }
        Student* temp = head;
        cout << "\n--- Placement Records ---\n";
        while (temp) {
            cout << "ID: " << temp->id << " | Name: " << temp->name
                 << " | Branch: " << temp->branch << " | CGPA: " << temp->cgpa << "\n";
            temp = temp->next;
        }
    }

    // Search student by ID
    void searchStudent(int id) {
        Student* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Record found: ID=" << temp->id << ", Name=" << temp->name
                     << ", Branch=" << temp->branch << ", CGPA=" << temp->cgpa << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Update student details
    void updateStudent(int id) {
        Student* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, temp->name);
                cout << "Enter new branch: ";
                getline(cin, temp->branch);
                cout << "Enter new CGPA: ";
                cin >> temp->cgpa;
                cout << "Record updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Delete student
    void deleteStudent(int id) {
        if (!head) {
            cout << "No records to delete.\n";
            return;
        }
        if (head->id == id) {
            Student* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Record deleted successfully!\n";
            return;
        }
        Student* temp = head;
        while (temp->next && temp->next->id != id) temp = temp->next;
        if (temp->next) {
            Student* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Record deleted successfully!\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    // Sort students by CGPA (descending)
    void sortStudents() {
        if (!head || !head->next) return;
        for (Student* i = head; i; i = i->next) {
            for (Student* j = i->next; j; j = j->next) {
                if (i->cgpa < j->cgpa) {
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->branch, j->branch);
                    swap(i->cgpa, j->cgpa);
                }
            }
        }
        cout << "Records sorted by CGPA (descending).\n";
    }
};

int main() {
    PlacementSystem ps;
    int choice, id;
    string name, branch;
    float cgpa;

    while (true) {
        cout << "\n===== Placement Information System =====\n";
        cout << "1. Insert Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Sort Students by CGPA\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Branch: "; getline(cin, branch);
                cout << "Enter CGPA: "; cin >> cgpa;
                ps.insertStudent(id, name, branch, cgpa);
                break;
            case 2:
                ps.displayStudents();
                break;
            case 3:
                cout << "Enter ID to search: "; cin >> id;
                ps.searchStudent(id);
                break;
            case 4:
                cout << "Enter ID to update: "; cin >> id;
                ps.updateStudent(id);
                break;
            case 5:
                cout << "Enter ID to delete: "; cin >> id;
                ps.deleteStudent(id);
                break;
            case 6:
                ps.sortStudents();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
