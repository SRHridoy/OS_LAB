#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int at[n], bt[n], rt[n];

    cout << "Enter Arrival & Burst times:\n";
    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
        rt[i]=bt[i]; // Remaining Time
    }

    int complete=0,t=0,shortest;
    float total_wt=0;

    while(complete!=n){
        shortest=-1;
        for(int j=0;j<n;j++){
            if(at[j]<=t && rt[j]>0){
                if(shortest==-1 || rt[j]<rt[shortest])
                    shortest=j; // ছোট Remaining Time এর প্রসেস বেছে নেয়া
            }
        }
        if(shortest==-1){
            t++; continue;
        }
        rt[shortest]--;
        if(rt[shortest]==0){
            complete++;
            total_wt+= (t+1)-at[shortest]-bt[shortest]; // waiting time হিসাব
        }
        t++;
    }
    cout<<"Average Waiting Time: "<<total_wt/n<<endl;
}
