#include <iostream>
#include <vector>
#include <list>
using namespace std;

// -----------------------------
// a) Linear Probing (without replacement)
// -----------------------------
class LinearProbing {
    int size;
    vector<int> table;
public:
    LinearProbing(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insert(int key) {
        int index = key % size;
        int startIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[index] = key;
    }

    void display() {
        cout << "\nLinear Probing Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

// -----------------------------
// b) Separate Chaining (Linked List)
// -----------------------------
class SeparateChaining {
    int size;
    vector<list<int>> table;
public:
    SeparateChaining(int s) {
        size = s;
        table.resize(size);
    }

    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);
    }

    void display() {
        cout << "\nSeparate Chaining Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (auto &val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

// -----------------------------
// c) Quadratic Probing (without replacement)
// -----------------------------
class QuadraticProbing {
    int size;
    vector<int> table;
public:
    QuadraticProbing(int s) {
        size = s;
        table.assign(size, -1);
    }

    void insert(int key) {
        int index = key % size;
        int i = 0;
        int newIndex;
        while (true) {
            newIndex = (index + i * i) % size;
            if (table[newIndex] == -1) {
                table[newIndex] = key;
                break;
            }
            i++;
            if (i == size) {
                cout << "Hash table full!\n";
                break;
            }
        }
    }

    void display() {
        cout << "\nQuadratic Probing Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

// -----------------------------
// Main Function
// -----------------------------
int main() {
    int n;

    // a) Linear Probing
    cout << "=== (a) Linear Probing ===\n";
    LinearProbing lp(6);
    cout << "Enter number of cold drink flavours: ";
    cin >> n;
    cout << "Enter " << n << " flavour keys:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        lp.insert(key);
    }
    lp.display();

    // b) Separate Chaining
    cout << "\n=== (b) Separate Chaining ===\n";
    SeparateChaining sc(20);
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        sc.insert(key);
    }
    sc.display();

    // c) Quadratic Probing
    cout << "\n=== (c) Quadratic Probing ===\n";
    QuadraticProbing qp(11);
    cout << "Enter number of mango categories: ";
    cin >> n;
    cout << "Enter number of mangoes for each category:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        qp.insert(key);
    }
    qp.display();

    return 0;
}
