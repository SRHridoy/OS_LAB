#include <iostream>
#include <algorithm>
using namespace std;

struct Process{
    int id, bt, pr;
};

bool compare(Process a, Process b){
    return a.pr < b.pr; // ছোট priority আগে আসবে
}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    Process p[n];

    cout<<"Enter burst time and priority:\n";
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        cin>>p[i].bt>>p[i].pr;
    }

    sort(p,p+n,compare); // priority অনুযায়ী sort করছি

    int wt[n]={0}, total_wt=0;

    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+p[i-1].bt;
        total_wt+=wt[i]; // waiting time হিসাব
    }

    cout<<"Average Waiting Time: "<<(float)total_wt/n<<endl;
}
