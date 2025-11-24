#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
    string dept;
};

//Utility Function to Display
void display(const vector<Student>& s) {
    cout << "\n------------------------------------------------------------\n";
    cout << left << setw(10) << "RollNo" << setw(20) << "Name" 
         << setw(10) << "SGPA" << setw(15) << "Department" << endl;
    cout << "------------------------------------------------------------\n";
    for (auto &st : s)
        cout << left << setw(10) << st.rollNo << setw(20) << st.name 
             << setw(10) << st.sgpa << setw(15) << st.dept << endl;
    cout << "------------------------------------------------------------\n";
}

//(a) Bubble Sort by RollNo
void bubbleSort(vector<Student>& s) {
    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (s[j].rollNo > s[j+1].rollNo)
                swap(s[j], s[j+1]);
        }
    }
}

//(b) Insertion Sort by Name
void insertionSort(vector<Student>& s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > key.name) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

//(c) Quick Sort by SGPA
int partition(vector<Student>& s, int low, int high) {
    float pivot = s[high].sgpa;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (s[j].sgpa > pivot) { // Descending order
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void quickSort(vector<Student>& s, int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

//(d) Linear Search by SGPA
void linearSearchSGPA(const vector<Student>& s, float target) {
    bool found = false;
    for (auto &st : s) {
        if (st.sgpa == target) {
            if (!found) cout << "\nStudents having SGPA " << target << ":\n";
            cout << left << setw(10) << st.rollNo << setw(20) << st.name 
                 << setw(10) << st.sgpa << setw(15) << st.dept << endl;
            found = true;
        }
    }
    if (!found) cout << "\nNo student found with SGPA " << target << endl;
}

//(e) Binary Search by Name (Non-recursive)
void binarySearchName(vector<Student> s, string key) {
    insertionSort(s); // must be sorted alphabetically
    int low = 0, high = s.size() - 1;
    bool found = false;
    cout << "\nSearching for students containing name '" << key << "':\n";
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].name.find(key) != string::npos) {
            found = true;
            cout << left << setw(10) << s[mid].rollNo << setw(20) << s[mid].name 
                 << setw(10) << s[mid].sgpa << setw(15) << s[mid].dept << endl;
            // Check surrounding names for partial matches
            int leftIdx = mid - 1, rightIdx = mid + 1;
            while (leftIdx >= 0 && s[leftIdx].name.find(key) != string::npos) {
                cout << left << setw(10) << s[leftIdx].rollNo << setw(20) << s[leftIdx].name 
                     << setw(10) << s[leftIdx].sgpa << setw(15) << s[leftIdx].dept << endl;
                leftIdx--;
            }
            while (rightIdx < s.size() && s[rightIdx].name.find(key) != string::npos) {
                cout << left << setw(10) << s[rightIdx].rollNo << setw(20) << s[rightIdx].name 
                     << setw(10) << s[rightIdx].sgpa << setw(15) << s[rightIdx].dept << endl;
                rightIdx++;
            }
            break;
        } else if (s[mid].name < key) low = mid + 1;
        else high = mid - 1;
    }
    if (!found) cout << "No student found with name containing '" << key << "'.\n";
}

//(f) Fibonacci Search by Department
int minVal(int x, int y) { return (x <= y) ? x : y; }

void fibonacciSearchDept(const vector<Student>& s, string deptName) {
    int n = s.size();
    int fibMMm2 = 0;  
    int fibMMm1 = 1;  
    int fibM = fibMMm2 + fibMMm1;  
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1) {
        int i = minVal(offset + fibMMm2, n - 1);
        if (s[i].dept < deptName) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (s[i].dept > deptName) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            cout << "\nStudent belongs to " << deptName << " department.\n";
            return;
        }
    }
    cout << "\nNo student found in department " << deptName << ".\n";
}

int main() {
    vector<Student> s = {
        {1, "Utkarsha", 9.5, "Computer"},
        {2, "Rohit", 8.7, "ENTC"},
        {3, "Sneha", 9.2, "Mechanical"},
        {4, "Anjali", 8.9, "Computer"},
        {5, "Tejas", 7.8, "Civil"},
        {6, "Priya", 9.6, "Computer"},
        {7, "Amit", 8.4, "ENTC"},
        {8, "Meera", 9.8, "Computer"},
        {9, "Karan", 8.1, "Civil"},
        {10, "Ishita", 9.4, "Mechanical"},
        {11, "Suresh", 8.0, "Computer"},
        {12, "Tanvi", 9.1, "ENTC"},
        {13, "Vikas", 7.9, "Civil"},
        {14, "Rutuja", 9.7, "Computer"},
        {15, "Omkar", 8.8, "ENTC"}
    };

    int choice;
    do {
        cout << "\n=========== STUDENT DATABASE MENU ===========";
        cout << "\n1. Display Roll Call List (Bubble Sort)";
        cout << "\n2. Arrange Alphabetically (Insertion Sort)";
        cout << "\n3. Find Top 10 Toppers (Quick Sort)";
        cout << "\n4. Search Students by SGPA (Linear Search)";
        cout << "\n5. Search Student by Name (Binary Search)";
        cout << "\n6. Search if Student belongs to Computer Dept (Fibonacci Search)";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                bubbleSort(s);
                cout << "\nRoll Call List (Ascending by RollNo):";
                display(s);
                break;
            }
            case 2: {
                insertionSort(s);
                cout << "\nStudents Sorted Alphabetically:";
                display(s);
                break;
            }
            case 3: {
                quickSort(s, 0, s.size() - 1);
                cout << "\nTop 10 Toppers of the Class:\n";
                for (int i = 0; i < 10 && i < s.size(); i++)
                    cout << left << setw(10) << s[i].rollNo << setw(20) << s[i].name 
                         << setw(10) << s[i].sgpa << setw(15) << s[i].dept << endl;
                break;
            }
            case 4: {
                float sgpa;
                cout << "Enter SGPA to search: ";
                cin >> sgpa;
                linearSearchSGPA(s, sgpa);
                break;
            }
            case 5: {
                string key;
                cout << "Enter name or part of name to search: ";
                cin >> key;
                binarySearchName(s, key);
                break;
            }
            case 6: {
                string deptName = "Computer";
                fibonacciSearchDept(s, deptName);
                break;
            }
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
