#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], total_wt = 0;

    cout << "Enter burst times:\n";
    for(int i = 0; i < n; i++)
        cin >> bt[i];

    wt[0] = 0; // প্রথম প্রসেসের waiting time সবসময় 0

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];  // waiting time হিসাব
        total_wt += wt[i];          // waiting time যোগ করছি
    }

    cout << "Average Waiting Time: " << (float)total_wt/n << endl;
}
