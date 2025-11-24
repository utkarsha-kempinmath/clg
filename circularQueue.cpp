#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

// Round Robin Scheduling
int main() {
    int n = 5; // Number of processes
    int timeQuantum = 2;

    Process p[5] = {
        {"P1", 0, 5, 5, 0, 0, 0},
        {"P2", 1, 3, 3, 0, 0, 0},
        {"P3", 2, 1, 1, 0, 0, 0},
        {"P4", 3, 2, 2, 0, 0, 0},
        {"P5", 4, 3, 3, 0, 0, 0}
    };

    queue<int> q; // circular queue of process indices
    int currentTime = 0;
    int completed = 0;
    bool inQueue[5] = {false};

    // Start with the first process
    q.push(0);
    inQueue[0] = true;

    while (completed != n) {
        if (q.empty()) {
            // If queue is empty, jump to next process arrival
            for (int i = 0; i < n; i++) {
                if (p[i].remainingTime > 0) {
                    currentTime = max(currentTime, p[i].arrivalTime);
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }

        int idx = q.front();
        q.pop();

        // Execute current process
        int execTime = min(timeQuantum, p[idx].remainingTime);
        p[idx].remainingTime -= execTime;
        currentTime += execTime;

        // Add newly arrived processes to the queue
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0 && !inQueue[i]) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[idx].remainingTime == 0) {
            p[idx].completionTime = currentTime;
            completed++;
            inQueue[idx] = false;
        } else {
            q.push(idx); // Reinsert for next round
        }
    }

    // Calculate turnaround and waiting times
    double totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        totalTAT += p[i].turnaroundTime;
        totalWT += p[i].waitingTime;
    }

    // Display results
    cout << "\nRound Robin CPU Scheduling (Time Quantum = " << timeQuantum << ")\n";
    cout << "--------------------------------------------------------------\n";
    cout << left << setw(8) << "Process" << setw(15) << "ArrivalTime" << setw(12)
         << "BurstTime" << setw(16) << "Completion" << setw(15)
         << "Turnaround" << setw(10) << "Waiting" << "\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(8) << p[i].name << setw(15) << p[i].arrivalTime
             << setw(12) << p[i].burstTime << setw(16) << p[i].completionTime
             << setw(15) << p[i].turnaroundTime << setw(10) << p[i].waitingTime << "\n";
    }

    cout << "--------------------------------------------------------------\n";
    cout << "Average Turnaround Time = " << totalTAT / n << endl;
    cout << "Average Waiting Time = " << totalWT / n << endl;

    return 0;
}
