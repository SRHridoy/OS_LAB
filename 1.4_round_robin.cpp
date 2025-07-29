#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter quantum: ";
    cin >> quantum;

    int bt[n], rem_bt[n], wt[n]={0},t=0;
    queue<int> q;

    cout << "Enter burst times:\n";
    for(int i=0;i<n;i++){
        cin>>bt[i];
        rem_bt[i]=bt[i]; // remaining burst time
        q.push(i);       // সব প্রসেস queue তে যোগ
    }

    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(rem_bt[i]>quantum){
            rem_bt[i]-=quantum; // quantum সময় কাজ করে আবার queue তে ঢুকাচ্ছি
            t+=quantum;
            q.push(i);
        }else{
            t+=rem_bt[i];
            wt[i]=t-bt[i]; // waiting time হিসাব
        }
    }

    float avg=0;
    for(int i=0;i<n;i++) avg+=wt[i];
    cout<<"Average Waiting Time: "<<avg/n<<endl;
}
