#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)  
        return 1;
    return n * factorial(n - 1); 
}

int fibonacci(int n) {
    if (n == 0) return 0;   
    if (n == 1) return 1;  
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    cout << "enter a number: "<<endl;
    cin >> num;

    if (num < 0) {
        cout << "factorial is not defined for negative numbers" << endl;
    } else {
        cout << "factorial of " << num << " is " << factorial(num) << endl;
    }

    cout << "fibonacci Series: ";
    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}