#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, bt;
};

bool compare(Process a, Process b) {
    return a.bt < b.bt;  // ছোট burst time আগে আসবে
}

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter burst times:\n";
    for(int i = 0; i < n; i++){
        p[i].id = i+1;
        cin >> p[i].bt;
    }

    sort(p, p+n, compare); // burst time অনুযায়ী sort করছি

    int wt[n]={0}, total_wt=0;

    for(int i=1; i<n; i++){
        wt[i] = wt[i-1] + p[i-1].bt; // waiting time হিসাব
        total_wt += wt[i];
    }

    cout << "Average Waiting Time: " << (float)total_wt/n << endl;
}
