#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime;
};

int main() {
    cout << "Enter the number of processes: ";

    int n;
    cin >> n;

    vector<Process> p(n);

    cout << "Enter arrival times : ";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cin >> p[i].arrivalTime;
    }

    cout << "Enter burst times : ";
    for (int i = 0; i < n; i++) {
        cin >> p[i].burstTime;
    }

    // Sorting processes by arrival time
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    double totalTAT = 0, totalWT = 0;

    // Calculating completion, turnaround, and waiting times
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;  // CPU idle time
        }

        p[i].completionTime = currentTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        totalTAT += p[i].turnaroundTime;
        totalWT += p[i].waitingTime;

        currentTime = p[i].completionTime;  // Update current time
    }

    // Printing the results in a tabular format
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : p) {
        cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
    }

    // Printing average turnaround and waiting times
    cout << "\nAverage TAT : " << totalTAT / n << endl;
    cout << "Average WT : " << totalWT / n << endl;

    return 0;
}
