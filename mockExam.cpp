#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to check if placing a queen is safe
bool isSafe(int board[], int col, int row) {
    for(int i = 0; i < col; i++) {
        // Check row and diagonal conflicts
        if(board[i] == row || abs(board[i] - row) == abs(i - col))
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter value of N (number of queens): ";
    cin >> n;

    int* board = new int[n];  
    stack<pair<int, int>> st;  // Stack to store (col, row)

    int col = 0, row = 0;
    int solutions = 0;

    while (true) {
        bool placed = false;

        // Try placing a queen row by row in current column
        while (row < n && !placed) {
            if (isSafe(board, col, row)) {
                board[col] = row;
                st.push({col, row});
                col++;
                row = 0;
                placed = true;
            } else {
                row++;
            }
        }

        // If no safe position found → backtrack
        if (!placed) {
            if (st.empty()) break; // explored all possibilities

            auto last = st.top();
            st.pop();
            col = last.first;
            row = last.second + 1;
            continue;
        }

        // If one full solution is formed
        if (col == n) {
            solutions++;
            cout << "Solution " << solutions << ":\n";

            // Display board visually
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << (board[i] == j ? "Q " : ". ");
                }
                cout << endl;
            }
            cout << endl;

            // Continue searching (backtrack)
            auto last = st.top();
            st.pop();
            col = last.first;
            row = last.second + 1;
        }
    }

    cout << "Total number of solutions: " << solutions << endl;

    delete[] board;  // Free memory
    return 0;
}
