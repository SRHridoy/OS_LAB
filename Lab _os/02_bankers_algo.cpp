#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes and resources: ";
    cin >> n >> m;

    int alloc[n][m], maxNeed[n][m], avail[m];
    cout << "Enter Allocation Matrix:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> alloc[i][j];

    cout << "Enter Max Matrix:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> maxNeed[i][j];

    cout << "Enter Available resources:\n";
    for(int i=0; i<m; i++)
        cin >> avail[i];

    int f[n] = {0}, ans[n], ind = 0;
    int need[n][m];

    // Calculate Need matrix
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            need[i][j] = maxNeed[i][j] - alloc[i][j];

    // Find the safe sequence
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            if(f[i] == 0) { // Not finished yet
                bool flag = true;
                for(int j=0; j<m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    for(int j=0; j<m; j++)
                        avail[j] += alloc[i][j];
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    bool safe = true;
    for(int i=0; i<n; i++)
        if(f[i] == 0)
            safe = false;

    if(safe) {
        cout << "System is SAFE.\nSafe sequence: ";
        for(int i=0; i<n; i++)
            cout << "P" << ans[i] << " ";
        cout << endl;
    } else {
        cout << "System is NOT safe!\n";
    }

    return 0;
}
