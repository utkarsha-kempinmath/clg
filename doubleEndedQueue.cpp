#include <iostream>
#define SIZE 10
using namespace std;

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertRear(int item) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more customers.\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = item;
        cout << "Customer " << item << " entered from Rear.\n";
    }

    void insertFront(int item) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more customers.\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = SIZE - 1;
        else
            front--;
        arr[front] = item;
        cout << "Customer " << item << " entered from Front.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "No customers to remove!\n";
            return;
        }
        cout << "Customer " << arr[front] << " exited from Front.\n";
        if (front == rear)
            front = rear = -1;
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "No customers to remove!\n";
            return;
        }
        cout << "Customer " << arr[rear] << " exited from Rear.\n";
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = SIZE - 1;
        else
            rear--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }
        cout << "Customers currently in queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

void inputRestrictedDeque() {
    Deque dq;
    int choice, item;

    do {
        cout << "\n--- Shopping Mall (Input Restricted Deque) ---\n";
        cout << "1. Insert Rear (Customer enters)\n";
        cout << "2. Delete Front (Customer exits)\n";
        cout << "3. Delete Rear (Customer exits)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer ID: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case 2:
            dq.deleteFront();
            break;
        case 3:
            dq.deleteRear();
            break;
        case 4:
            dq.display();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void outputRestrictedDeque() {
    Deque dq;
    int choice, item;

    do {
        cout << "\n--- Shopping Mall (Output Restricted Deque) ---\n";
        cout << "1. Insert Rear (Customer enters)\n";
        cout << "2. Insert Front (Customer enters)\n";
        cout << "3. Delete Front (Customer exits)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer ID: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case 2:
            cout << "Enter Customer ID: ";
            cin >> item;
            dq.insertFront(item);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.display();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

int main() {
    int option;
    do {
        cout << "\n========= SHOPPING MALL DEQUE SIMULATION =========\n";
        cout << "1. Input Restricted Deque\n";
        cout << "2. Output Restricted Deque\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            inputRestrictedDeque();
            break;
        case 2:
            outputRestrictedDeque();
            break;
        case 3:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (option != 3);

    return 0;
}
