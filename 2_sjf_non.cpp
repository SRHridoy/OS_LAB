#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, arrival, burst, completion, turnaround, waiting;
};

// Comparator for priority queue (shortest burst time first)
struct CompareBurst {
    bool operator()(const Process &a, const Process &b) {
        // If burst times are the same, sort by arrival time
        if (a.burst == b.burst)
            return a.arrival > b.arrival;  // if same burst time, earlier arrival first
        return a.burst > b.burst;  // min-heap based on burst time
    }
};

int main() {
    cout << "Enter number of processes: ";
    int n; cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].arrival;
        processes[i].id = i + 1;
    }

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].burst;
    }

    // Sort all processes by arrival time
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    int current_time = 0, index = 0;
    priority_queue<Process, vector<Process>, CompareBurst> ready_queue;
    vector<Process> completed;

    while (completed.size() < n) {
        // Push all processes that have arrived into the ready_queue
        while (index < n && processes[index].arrival <= current_time) {
            ready_queue.push(processes[index]);
            index++;
        }

        if (ready_queue.empty()) {
            // CPU idle: move to next process arrival
            current_time = processes[index].arrival;
            continue;
        }

        // Pick process with shortest burst time
        Process current = ready_queue.top();
        ready_queue.pop();

        current_time += current.burst;
        current.completion = current_time;
        current.turnaround = current.completion - current.arrival;
        current.waiting = current.turnaround - current.burst;

        completed.push_back(current);
    }

    // Sort completed processes by process ID
    sort(completed.begin(), completed.end(), [](const Process &a, const Process &b) {
        return a.id < b.id;
    });

    double total_TAT = 0, total_WT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto &p : completed) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.completion << "\t" << p.turnaround << "\t" << p.waiting << "\n";
        total_TAT += p.turnaround;
        total_WT += p.waiting;
    }

    cout << "\nAverage Turnaround Time: " << total_TAT / n;
    cout << "\nAverage Waiting Time: " << total_WT / n << endl;

    return 0;
}
