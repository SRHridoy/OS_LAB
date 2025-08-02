/*
    * Code for Banker's Algorithm in C++
    * This implementation checks for safe state and resource allocation 
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;
    vector<vector<int>> allocation(n, vector<int>(m)), max_need(n, vector<int>(m)), need(n, vector<int>(m));
    vector<int> available(m), work(m);
    vector<bool> finish(n, false);
    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }
    cout << "Enter maximum need matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max_need[i][j];
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
    cout << "Enter available resources vector:\n";
    for (int j = 0; j < m; j++) {
        cin >> available[j];
    }

    // Banker's Algorithm
    work = available;
    while (true) {
        int i;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canProceed = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }
                if (canProceed) {
                    break;
                }
            }
        }
        if (i == n) {
            cout << "System is in a safe state.\n";
            return 0;
        }
        finish[i] = true;
        for (int j = 0; j < m; j++) {
            work[j] += allocation[i][j];
        }
    }
    cout << "System is not in a safe state.\n";
    return 0;
}

/*
Enter number of processes: 5
Enter number of resources: 3
Enter allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter maximum need matrix:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter available resources vector:
3 3 2

System is in a safe state.

*/