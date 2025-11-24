#include <iostream>
using namespace std;

// Node structure to represent each order
struct Node {
    int orderID;
    Node* next;
};

// Class for Pizza Parlor system
class PizzaParlor {
private:
    Node* front;
    Node* rear;
    int maxOrders;
    int count;

public:
    // Constructor
    PizzaParlor(int m) {
        front = rear = nullptr;
        maxOrders = m;
        count = 0;
    }

    // Function to place an order
    void placeOrder(int id) {
        if (count == maxOrders) {
            cout << "Parlor Full! Cannot accept more orders.\n";
            return;
        }

        Node* newNode = new Node{id, nullptr};

        if (front == nullptr) {  // first order
            front = rear = newNode;
            rear->next = front;  // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // maintain circular structure
        }

        count++;
        cout << "Order " << id << " placed successfully.\n";
    }

    // Function to serve an order
    void serveOrder() {
        if (front == nullptr) {
            cout << "No orders to serve.\n";
            return;
        }

        int servedID = front->orderID;

        if (front == rear) {  // only one order
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        count--;
        cout << "Order " << servedID << " served successfully.\n";
    }

    // Function to display pending orders
    void displayOrders() {
        if (front == nullptr) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        Node* temp = front;
        do {
            cout << temp->orderID << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

// Main function
int main() {
    int M;
    cout << "Enter the maximum number of orders the parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);
    int choice, id;

    do {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> id;
                parlor.placeOrder(id);
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice, Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
